#include "sfp.h"
#include <stdlib.h>

typedef union fbit {
    float f;
    unsigned int i;
} fbit;

sfp int2sfp(int input){
    sfp output;
	if (!input) output = 0b000000000000000; // int = 0 -> 0
    else if (input > 65504) output = 0b0111110000000000; // int > sfp max value -> +infinity
    else if (input < -65504) output = 0b1111110000000000; // int < sfp min value -> -infinity
    else {
        unsigned char sign = (input >= 0 ? 0 : 1);
        unsigned char exp;
        unsigned short frac = (input >= 0 ? input : -input);
        unsigned char frac_length = 0;
        unsigned short count_exp = frac;

        // Get the length of frac
        while (count_exp != 1) {
            count_exp = count_exp >> 1;
            frac_length++;
        }

        exp = frac_length + (1 << 4) - 1;

        // Configure frac length to 10
        while (frac_length > 10) {
            frac = frac >> 1;
            frac_length--;
        }
             
        while (frac_length < 10) {
            frac = frac << 1;
            frac_length++;
        }
        
        output = (sign << 15) + (exp << 10) + (frac & ((1 << 10) - 1));
    }

    return output;
}

int sfp2int(sfp input){
    int output;

    // When sfp = +Infinity or Nan 
    if ((input >> 10) == 0b011111) {
        if (input & ((1 << 10) - 1) != 0) output = (1 << 31); // When int = Nan -> -TMin
        else output = (unsigned) (1 << 31) - 1; // When int = +infinity -> TMax
    }
    // When sfp = -infinity or Nan
    else if ((input >> 10) == 0b111111) output = (1 << 31); // int = Nan or -Infinity -> TMin

    else {
        unsigned char sign = ((input >> 15) & 1);
        unsigned char exp = ((input >> 10) & ((1 << 5) - 1)) - ((1 << 4) - 1);
        unsigned short frac = ((input & ((1 << 10) - 1)) + (1 << 10));
        
        // abs(output) = frac * (2 ^ (exp - 10))  (hidden leading one 1)
        if (exp >= 10) output = frac << (exp - 10);
        else output = frac >> (10 - exp); 
        if (sign) output = -output; // adjust the sign of output
    }
    return output;
}

sfp float2sfp(float input){
    sfp output;
    fbit uInput;
    uInput.f = input;

    unsigned char sign = (uInput.i >> 31);
    short exp = ((uInput.i & ((unsigned) (1 << 31) - (1 << 23))) >> 23) - ((1 << 7) - (1 << 4));
    unsigned int frac = (uInput.i & ((1 << 23) - 1));
    
    // Input = +0 or -0
    if (uInput.i == 0) output = 0; // float = +0 -> +0
    else if (uInput.i == (1 << 31)) output = 0b1000000000000000; // float = -0 -> -0
    
    // float exp <= sfp min exp value : Denormalizaion part
    else if ((exp <= 0)) {
        frac = frac + (1 << 23); // add float's hidden leading one.
        frac = frac >> (-exp + 1); // sfp's exp is 0, adjust frac by right shift.
        output = (sign << 15) + (frac >> (23 - 10));
    }

    // When abs(float) exceeds the max sfp value
    else if ( (exp >= ((1 << 5) - 1)) || ((exp == ((1 << 5) - 2)) && (frac > (((1 << 10) - 1) << (23 - 10)))) ) {
        if (sign == 0) output = 0b0111110000000000; // float > 0 -> +infinity
        else output = 0b1111110000000000; // float < 0 -> -infinity
    }
    
    else output = (sign << 15) + (exp << 10) + (frac >> (23 - 10));
    return output;
}

float sfp2float(sfp input) {
    fbit uOutput;
    unsigned int sign = (input & (1 << 15)) << 16;
    unsigned int exp = ((input & ((1 << 15) - (1 << 10))) + (((1 << 7) - (1 << 4)) << 10)) << (23 - 10);
    unsigned int frac = (input & ((1 << 10) - 1)) << (23 - 10);

    // When sfp's exp = -15(in denormalization of sfp), normalize the value to float.
    if (exp == ((((1 << 7) - (1 << 4)) << 10) << (23 - 10))) {
        while (((frac & (1 << 23)) == 0) && (frac != 0)) {
            frac = frac << 1;
            exp = exp - (1 << 23);
        }
    }
    uOutput.i = sign + exp + frac;
    return uOutput.f;
}

sfp sfp_add(sfp a, sfp b) {
    sfp output;
    unsigned char asign = (a >> 15) & 1;
    unsigned char aexp = (a >> 10) & ((1 << 5) - 1);
    unsigned short afrac = a & ((1 << 10) - 1);

    unsigned char bsign = (b >> 15) & 1;
    unsigned char bexp = (b >> 10) & ((1 << 5) - 1);
    unsigned short bfrac = b & ((1 << 10) - 1);

    unsigned char sum_sign = asign ^ bsign;
    unsigned char sum_exp;
    unsigned short sum_frac;
    unsigned short exp_dif;

    // Get the difference of two numbers.
    if ((aexp == 0) && (bexp > 0)) exp_dif = bexp - (aexp + 1); // When a is a denorm num and b is a norm num
    else if ((aexp > 0) && (bexp == 0)) exp_dif = aexp - (bexp + 1); // When b is a denorm num and a is a norm num
    else exp_dif = (aexp >= bexp ? aexp - bexp : bexp - aexp); // When two numbers are same norm numbers or denomr num.

    if (aexp == 0b11111 && bexp == 0b11111) {
        // a = infinity and b = infinity
        if (afrac == 0 && bfrac == 0) {
            if (asign == 0 && bsign == 0) output = 0b0111110000000000; // a and b > 0 -> +infinity
            else if (asign == 1 && bsign == 1) output = 0b1111110000000000; // a and b < 0 -> -infinity
            else output = 0b0111110000000001; // a * b < 0 -> NaN
        }
        // a or b = NaN
        else output = 0b0111110000000001;

    }
    else if (aexp == 0b11111) output = a; // a = infinity or NaN -> a
    else if (bexp == 0b11111) output = b; // b = infinity or NaN -> b

    // Addition (a and b have a same sign)
    else if (asign == bsign) {

        // Set hidden leading one and denormalized sfp's exp configuration
        if (aexp != 0) afrac += (1 << 10); // Set hidden leading one
        else aexp++; // denormalized sfp's exp(-15) to -14
        if (bexp != 0) bfrac += (1 << 10); // Set hidden leading one
        else bexp++; // denormalized sfp's exp(-15) to -14

        // Frac addition
        if (aexp >= bexp) {
            sum_exp = aexp;
            sum_frac = afrac + (bfrac >> exp_dif);
        }

        else {
            sum_exp = bexp;
            sum_frac = (afrac >> exp_dif) + bfrac;
        }

        // Set exp of denormilized numbers addtion
        if ((sum_exp == 1) && ((sum_frac & ((1 << 12) - (1 << 10))) == 0)) sum_exp--;
        
        // Adjust a carry
        if (sum_frac & (1 << 11)) { 
            sum_exp++;
            sum_frac = sum_frac >> 1;
        }
        // Check overflow
        if (sum_exp >= 0b11111) {
            if (asign == 0) return output = 0b0111110000000000; // a + b > sfp max and a, b > 0
            else return output = 0b1111110000000000;  // a + b < sfp min and a, b < 0
        }

        output = (asign << 15) + (sum_exp << 10) + (sum_frac & ((1 << 10) - 1));
    }

    // Subtraction(a and b do not have same sign)
    else {
        // When abs(a) = abs(b)
        if (afrac == bfrac && aexp == bexp) return output = 0;

        // Set hidden leading one and denormalized sfp's exp configuration
        if (aexp != 0) afrac += (1 << 10); // Set hidden leading one
        else aexp++; // denormalized sfp's exp(-15) to -14
        if (bexp != 0) bfrac += (1 << 10); // Set hidden leading one
        else bexp++; // denormalized sfp's exp(-15) to -14

        // find which a or b is bigger, and subtract smaller one from bigger one.
        if (aexp > bexp) {
            sum_sign = asign;
            sum_exp = aexp;
            sum_frac = afrac - (bfrac >> exp_dif);
        }

        else if (aexp < bexp){
            sum_sign = bsign;
            sum_exp = bexp;
            sum_frac = bfrac - (afrac >> exp_dif);
        }

        else {
            if (afrac > bfrac){
                sum_sign = asign;
                sum_exp = aexp;
                sum_frac = afrac - bfrac;
            }
            else {
                sum_sign = bsign;
                sum_exp = bexp;
                sum_frac = bfrac - afrac;
            }
        }

        // sum_exp configuration
        while (((sum_frac & (1 << 10)) == 0) && (sum_exp > 1)) { 
            sum_exp--;
            sum_frac = sum_frac << 1;
        }

        // Adjust denormalized number adjust
        if ((sum_exp == 1) && ((sum_frac & (1 << 10)) == 0)) sum_exp--;

        output = (sum_sign << 15) + (sum_exp << 10) + (sum_frac & ((1 << 10) - 1));
    }

    return output;
}

sfp sfp_mul(sfp a, sfp b) {

    sfp output;
    unsigned char asign = (a >> 15) & 1;
    unsigned char aexp = (a >> 10) & ((1 << 5) - 1);
    unsigned short afrac = a & ((1 << 10) - 1);

    unsigned char bsign = (b >> 15) & 1;
    unsigned char bexp = (b >> 10) & ((1 << 5) - 1);
    unsigned short bfrac = b & ((1 << 10) - 1);

    unsigned char mul_sign = asign ^ bsign;
    char mul_exp = aexp + bexp - ((1 << 4) - 1);
    unsigned int mul_frac;

    // a and b are infinity or NaN either
    if (aexp == 0b11111 && bexp == 0b11111) {
        if (afrac == 0 && bfrac == 0) output = (mul_sign << 15) + (0b11111 << 10); // a and b are infinity -> (a * b sign) infinity
        else output = 0b0111110000000001; // a or b is NaN -> NaN
    }
    // a is infinity or NaN, and b is not.
    else if (aexp == 0b11111) {
        if (afrac == 0) {
            if (b == 0) output = 0b0111110000000001; // a is infinity and b is 0 -> NaN
            else output = (mul_sign << 15) + (0b11111 << 10); // a is infinity and b is a normal number-> (a * b sign) infinity
        }
        else output = 0b0111110000000001; // a is NaN -> NaN
    }

    // b is infinity or a NaN, and a is not.
    else if (bexp == 0b11111) {
        if (bfrac == 0) {
            if (a == 0) output = 0b0111110000000001; // b is infinity and a is 0 -> NaN
            else output = (mul_sign << 15) + (0b11111 << 10); // b is infinity and a is a normal number-> (a * b sign) infinity
        }
        else output = 0b0111110000000001; // b is a NaN -> NaN
    }

    else {
        if (mul_exp >= ((1 << 5) - 1)) return output = (mul_sign << 15) + (0b11111 << 10); // a *b > sfp max value -> (a * b sign) infinity
        
        // frac normalization
        if (aexp != 0) afrac += (1 << 10);
        if (bexp != 0) bfrac += (1 << 10);
        
        mul_frac = afrac * bfrac;

        // carry overflow
        if ((mul_frac & (1 << 21)) != 0) { 
            mul_exp++;
            mul_frac = mul_frac >> 1;
        }
        // mul_frac configuration
        while ((mul_frac & ((1 << 21)-(1 << 11))) != 0) mul_frac = mul_frac >> 1;

        if (mul_exp >= 0b11111) return output = (mul_sign << 15) + (0b11111 << 10); // when mul_exp exceed max sfp exp -> (a * b sign) infinity
        else if (mul_exp < 0) return output = 0; // a * b < sfp min value -> 0

        output = (mul_sign << 15) + (mul_exp << 10) + (mul_frac & ((1 << 10) - 1));
    }
    return output;	
}

char* sfp2bits(sfp result){
    char *sfpstr = (char * )calloc(17, sizeof(char));
    for (int i = 15; i >= 0; i--) {
        sfpstr[i] = '0' + (result & 1);
        result = result >> 1;
    }
    return sfpstr;
}