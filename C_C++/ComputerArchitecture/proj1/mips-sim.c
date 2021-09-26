#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    unsigned int iinst;
    unsigned char cinst;
    unsigned int Linst;
    int instruction_number = 0;
    char opcode;

   
    FILE *fp = fopen("C:/Projects/C_C++_Projects/ComputerArchitecture/proj1/test3.bin", "rb");

    if (!fp) {
        perror("fopen error");
        exit(1);
    }

    while (1) {

        // Read the file and check an error.
        if (fread(&iinst, sizeof(int), 1, fp) == -1) {
            perror("read error");
            exit(1);
        }
        // End the loop when the fp reeachs EOF.
        if (feof(fp)) break;

        Linst = 0;
        // Enddian change.
        for (int i = 0; i < sizeof(int) / sizeof(char); i++) {
            cinst = iinst & ((1 << 8) - 1);
            iinst = iinst >> 8;
            Linst += cinst * (1 << ((3 - i) * 8));
        }
        printf("inst %d: %08x ", instruction_number, Linst);

        opcode = (Linst >> (32 - 6)) & ((1 << 6) - 1);

        // R-type instructions
        if (!opcode) {

            unsigned char rs = (Linst >> (32 - 11)) & ((1 << 5) -1);
            unsigned char rt = (Linst >> (32 - 16)) & ((1 << 5) -1);
            unsigned char rd = (Linst >> (32 - 21)) & ((1 << 5) -1);
            char sa = (Linst >> (32 - 26)) & ((1 << 5) -1);
            char funct = Linst & ((1 << 6) - 1);

            if (funct == 0b100000) printf("add $%d, $%d, $%d\n", rd, rs, rt);
            else if (funct == 0b100001) printf("addu $%d, $%d, $%d\n", rd, rs, rt);
            else if (funct == 0b100100) printf("and $%d, $%d, $%d\n", rd, rs, rt);
            // else if (funct == 0b001101) printf("break\n");
            else if (funct == 0b011010) printf("div $%d, $%d\n", rs, rt);
            else if (funct == 0b011011) printf("divu $%d, $%d\n", rs, rt);
            else if (funct == 0b001001) printf("jalr $%d, $%d\n", rd, rs);
            else if (funct == 0b001000) printf("jr $%d\n", rs);
            else if (funct == 0b010000) printf("mfhi $%d\n", rd);
            else if (funct == 0b010010) printf("mflo $%d\n", rd);
            else if (funct == 0b010001) printf("mthi $%d\n", rs);
            else if (funct == 0b010011) printf("mtlo $%d\n", rs);
            else if (funct == 0b011000) printf("mult $%d, $%d\n", rs, rt);
            else if (funct == 0b011001) printf("multu $%d, $%d\n", rs, rt);
            else if (funct == 0b100100) printf("and $%d, $%d, $%d\n", rd, rs, rt);
            else if (funct == 0b100111) printf("nor $%d, $%d, $%d\n", rd, rs, rt);
            else if (funct == 0b100101) printf("or $%d, $%d, $%d\n", rd, rs, rt);
            else if (funct == 0b000000) printf("sll $%d, $%d, %d\n", rd, rt, sa);
            else if (funct == 0b000100) printf("sllv $%d, $%d, $%d\n", rd, rt, rs);
            else if (funct == 0b101010) printf("slt $%d, $%d, $%d\n", rd, rs, rt);
            else if (funct == 0b101011) printf("sltu $%d, $%d, $%d\n", rd, rs, rt);
            else if (funct == 0b000011) printf("sra $%d, $%d, %d\n", rd, rt, sa);
            else if (funct == 0b000111) printf("srav $%d, $%d, $%d\n", rd, rt, rs);
            else if (funct == 0b000010) printf("srl $%d, $%d, %d\n", rd, rt, sa);
            else if (funct == 0b000110) printf("srlv $%d, $%d, $%d\n", rd, rt, rs);
            else if (funct == 0b100010) printf("sub $%d, $%d, $%d\n", rd, rs, rt);
            else if (funct == 0b100011) printf("subu $%d, $%d, $%d\n", rd, rs, rt);
            else if (funct == 0b001100) printf("syscall\n");
            else if (funct == 0b100110) printf("xor $%d, $%d, $%d\n", rd, rs, rt);
            else printf("unknown instruction\n");
        }

        // J-type instructions
        else if (((opcode >> 1) == 0b00001)) {

            int target = Linst & ((1 << 26) - 1);
            if (opcode == 0b000010) printf("j %d\n", target);
            if (opcode == 0b000011) printf("jal %d\n", target);
        }

        // I-type instructions
        else{

            unsigned char rs = (Linst >> (32 - 11)) & ((1 << 5) -1);
            unsigned char rt = (Linst >> (32 - 16)) & ((1 << 5) -1);
            short im = Linst & ((1 << 16) - 1);

            if (opcode == 0b001000) printf("addi $%d, $%d, %d\n", rt, rs, im);
            else if (opcode == 0b001001) printf("addiu $%d, $%d, %d\n", rt, rs, im);
            else if (opcode == 0b001100) printf("andi $%d, $%d, %d\n", rt, rs, im);
            else if (opcode == 0b000100) printf("beq $%d, $%d, %d\n", rs, rt, im);
            else if (opcode == 0b000001) {
                rt = 0b00000;
                printf("bgez $%d, %d\n", rs, im);
            }
            else if (opcode == 0b000111) {
                rt = 0b00000;
                printf("bgtz $%d, %d\n", rs, im);
            }
            else if (opcode == 0b000110) {
                rt = 0b00000;
                printf("blez $%d, %d\n", rs, im);
            }
            else if (opcode == 0b000001) {
                rt = 0b00000;
                printf("bltz $%d, %d\n", rs, im);
            }
            else if (opcode == 0b000101) printf("bne $%d, $%d, %d\n", rs, rt, im);
            else if (opcode == 0b100000) printf("lb $%d, %d($%d)\n", rt, im, rs);
            else if (opcode == 0b100100) printf("lbu $%d, %d($%d)\n", rt, im, rs);
            else if (opcode == 0b100001) printf("lh $%d, %d($%d)\n", rt, im, rs);
            else if (opcode == 0b100101) printf("lhu $%d, %d($%d)\n", rt, im, rs);
            else if (opcode == 0b001111) printf("lui $%d, %d\n", rt, im);
            else if (opcode == 0b100011) printf("lw $%d, %d($%d)\n", rt, im, rs);
            else if (opcode == 0b110001) printf("lwcl $%d, %d($%d)\n", rt, im, rs);
            else if (opcode == 0b001101) printf("ori $%d, $%d, %d\n", rt, rs, im);
            else if (opcode == 0b101000) printf("sb $%d, %d($%d)\n", rt, im, rs);
            else if (opcode == 0b001010) printf("slti $%d, $%d, %d\n", rt, rs, im);
            else if (opcode == 0b001011) printf("sltiu $%d, $%d, %d\n", rt, rs, im);
            else if (opcode == 0b101001) printf("sh $%d, %d($%d)\n", rt, im, rs);
            else if (opcode == 0b101011) printf("sw $%d, %d($%d)\n", rt, im, rs);
            else if (opcode == 0b111001) printf("swel $%d, %d($%d)\n", rt, im, rs);
            else if (opcode == 0b001110) printf("xori $%d, $%d, %d\n", rt, rs, im);
        }
        instruction_number++;
    }

    if (fclose(fp)) {
        perror("fclose error");
        exit(1);
    }
    return 0;
}