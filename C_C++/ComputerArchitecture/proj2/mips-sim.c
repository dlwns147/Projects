#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REG_NUM 33
#define MEM_SIZE 4000

int main(int argc, char** argv) {
    
    unsigned int uInput_inst;
    unsigned char cInst;
    unsigned int uLE_inst;
    char opcode;


    int reg[REG_NUM] = { 0, }; // Registers, 0 to 31 : general purpose register / 32 = PC register
    int inst_mem[MEM_SIZE]; // Instruction memory space
    int data_mem[MEM_SIZE]; // Data memory space
    for (int i = 0; i < MEM_SIZE; i++) data_mem[i] = inst_mem[i] = 0xffffffff;

    int inst_num = 60;
    char command[4] = "reg";
    int mem_loc = 0x10000008;
    //scanf("%s", command);

    FILE *fp = fopen("C:/Projects/C_C++_Projects/ComputerArchitecture/proj2/proj2_3.bin", "rb");

    if (!fp) {
        perror("fopen error");
        exit(1);
    }
    int count = 0;
    while(1) {

        // Read the file and check an error.
        if (fread(&uInput_inst, sizeof(int), 1, fp) == -1) {
            perror("read error");
            exit(1);
        }

        // End the loop when the fp reeachs EOF.
        if (feof(fp)) break;

        uLE_inst = 0;
        // Change the instruction enddian.
        for (int i = 0; i < sizeof(int) / sizeof(char); i++) {
            cInst = uInput_inst & ((1 << 8) - 1);
            uInput_inst = uInput_inst >> 8;
            uLE_inst += cInst * (1 << ((3 - i) * 8));
            // printf("%u\n", inst_mem[i]);
        }
        inst_mem[count++] = uLE_inst;
    }

    for (int i = 0; i < inst_num; i++) {

        uLE_inst = inst_mem[reg[REG_NUM - 1] / 4];
        reg[REG_NUM - 1] += 4; // PC + 4

        opcode = (uLE_inst >> (32 - 6)) & ((1 << 6) - 1);

        // R-type instructions
        if (!opcode) {

            unsigned char rs = (uLE_inst >> (32 - 11)) & ((1 << 5) -1);
            unsigned char rt = (uLE_inst >> (32 - 16)) & ((1 << 5) -1);
            unsigned char rd = (uLE_inst >> (32 - 21)) & ((1 << 5) -1);
            unsigned char sa = (uLE_inst >> (32 - 26)) & ((1 << 5) -1);
            char funct = uLE_inst & ((1 << 6) - 1);

            // add rd, rs, rt
            if (funct == 0b100000) reg[rd] = (reg[rs] + reg[rt]);
            // and rd, rs, rt
            else if (funct == 0b100100) reg[rd] = (reg[rs] & reg[rt]);
            // or rd, rs, rt
            else if (funct == 0b100101) reg[rd] = (reg[rs] | reg[rt]);
            // sll rd, rt, sa
            else if (funct == 0b000000) reg[rd] = (reg[rt] << sa);
            // slt rd, rs, rt
            else if (funct == 0b101010) reg[rd] = (reg[rs] < reg[rt]) ? 1 : 0;
            // srl rd, rt, sa
            else if (funct == 0b000010) reg[rd] = (((unsigned) reg[rt]) >> sa);
            // sub rd, rs, rt
            else if (funct == 0b100010) reg[rd] = (reg[rs] - reg[rt]);
            else {
                printf("unknown instruction\n");
                break;
            }
        }

        // J-type instructions
        else if (((opcode >> 1) == 0b00001)) {

            int target = uLE_inst & ((1 << 26) - 1);
            // j target
            if (opcode == 0b000010) {
                target = target << 2;
                reg[REG_NUM - 1] = target + (reg[REG_NUM - 1] & ((1 << 32) - (1 << 30)));
            }
            else {
                printf("unknown instruction\n");
                break;
            }
        }

        // I-type instructions
        else{

            unsigned char rs = (uLE_inst >> (32 - 11)) & ((1 << 5) -1);
            unsigned char rt = (uLE_inst >> (32 - 16)) & ((1 << 5) -1);
            short im = (uLE_inst & ((1 << 16) - 1));
            // printf("rt %u rs %u im %u\n", rt, rs, im );
            // addi rt, rs, im
            if (opcode == 0b001000) reg[rt] = (reg[rs] + (im & ((1 << 16) - 1)));
            // andi rt, rs, im
            else if (opcode == 0b001100) reg[rt] = (reg[rs] & (im & ((1 << 16) - 1)));
            // beq rs, rt, im
            else if (opcode == 0b000100) {
                if (reg[rs] == reg[rt]) reg[REG_NUM - 1] += 4 * im;
            }
            // bne rs, rt, im
            else if (opcode == 0b000101) {
                if (reg[rs] != reg[rt]) reg[REG_NUM - 1] += 4 * im;
            }
            // lb rt, im, rs
            else if (opcode == 0b100000) {
                int mem = reg[rs] + im;
                int remain = mem % 4;
                if (mem >= 0x10000000 && mem <= 0x10010000) {
                    mem -= 0x10000000;
                    reg[rt] = ((data_mem[mem / 4] << (8 * remain)) >> 24);
                }
                else if (mem >=0 && mem <= 0x00010000) reg[rt] = ((inst_mem[mem / 4] << (8 * remain)) >> 24);
            }
            // lbu rt, im, rs
            else if (opcode == 0b100100) {
                int mem = reg[rs] + im;
                int remain = mem % 4;
                if (mem >= 0x10000000 && mem <= 0x10010000) {
                    mem -= 0x10000000;
                    reg[rt] = ((data_mem[mem / 4] >> (8 * (3 - remain))) & ((1 << 8) - 1));
                }
                else if (mem >=0 && mem <= 0x00010000) reg[rt] = ((inst_mem[mem / 4] >> (8 * (3 - remain))) & ((1 << 8) - 1));
            }
            // lh rt, im, rs
            else if (opcode == 0b100001) {
                int mem = reg[rs] + im;
                int remain = mem % 4;
                if (mem >= 0x10000000 && mem <= 0x10010000) {
                    mem -= 0x10000000;
                    reg[rt] = ((data_mem[mem / 4] << (8 * remain)) >> 16);
                }
                else if (mem >=0 && mem <= 0x00010000) reg[rt] = ((inst_mem[mem / 4] << (8 * remain)) >> 16);
            }
            // lhu rt, im, rs
            else if (opcode == 0b100101) {
                int mem = reg[rs] + im;
                int remain = mem % 4;
                if (mem >= 0x10000000 && mem <= 0x10010000) {
                    mem -= 0x10000000;
                    reg[rt] = ((data_mem[mem / 4] << (8 * remain)) >> 24);
                }
                else if (mem >=0 && mem <= 0x00010000) reg[rt] = ((inst_mem[mem / 4] << (8 * remain)) >> 24);
            }
            // lui rt, im
            else if (opcode == 0b001111) reg[rt] = ((im << 16) & ((1 << 32) - (1 << 16)));
            // lw rt, im, rs
            else if (opcode == 0b100011) {
                int mem = reg[rs] + im;
                if (mem >= 0x10000000 && mem <= 0x10010000) {
                    mem -= 0x10000000;
                    reg[rt] = data_mem[mem / 4];
                }
                else if (mem >=0 && mem <= 0x00010000) reg[rt] = inst_mem[mem / 4];
            }
            // ori rt, rs, im
            else if (opcode == 0b001101) reg[rt] = (reg[rs] | (im & ((1 << 16) - 1)));
            // sb rt, im, rs
            else if (opcode == 0b101000) {
                int mem = reg[rs] + im;
                int remain = mem % 4;
                if (mem >= 0x10000000 && mem <= 0x10010000) {
                    mem -= 0x10000000;
                    data_mem[mem / 4] &= (~((1 << 8 * (4 - remain)) - (1 << 8 * (3 - remain))));
                    data_mem[mem / 4] += ((reg[rt] & ((1 << 8) - 1)) << 8 * (3 - remain));
                }
                else if (mem >=0 && mem <= 0x00010000) {
                    inst_mem[mem / 4] &= (~((1 << 8 * (4 - remain)) - (1 << 8 * (3 - remain))));
                    inst_mem[mem / 4] += ((reg[rt] & ((1 << 8) - 1)) << 8 * (3 - remain));
                }
            }
            // slti rt, rs, im
            else if (opcode == 0b001010) reg[rt] = (reg[rs] < im) ? 1 : 0;
            // sh rt, im, rs
            else if (opcode == 0b101001) {
                int mem = reg[rs] + im;
                int remain = mem % 4;
                if (mem >= 0x10000000 && mem <= 0x10010000) {
                    mem -= 0x10000000;
                    data_mem[mem / 4] &= (~((1 << 8 * (4 - remain)) - (1 << 8 * (2 - remain))));
                    data_mem[mem / 4] += ((reg[rt] & ((1 << 16) - 1)) << 8 * (2 - remain));
                }
                else if (mem >=0 && mem <= 0x00010000) {
                    inst_mem[mem / 4] &= (~((1 << 8 * (4 - remain)) - (1 << 8 * (2 - remain))));
                    inst_mem[mem / 4] += ((reg[rt] & ((1 << 16) - 1)) << 8 * (2 - remain));
                }
            }
            
            // sw rt, im, rs
            else if (opcode == 0b101011) {
                int mem = reg[rs] + im;
                if (mem >= 0x10000000 && mem <= 0x10010000) {
                    mem -= 0x10000000;
                    data_mem[mem / 4] = reg[rt];
                }
                else if (mem >=0 && mem <= 0x00010000) inst_mem[mem / 4] = reg[rt];
            }
            else {
                printf("unknown instruction\n");
                break;
            }
        }
    }

    // When third argument is "reg"
    if (!strncmp(command, "reg", 3)) {
        for (int i = 0; i < REG_NUM; i++) {
            if (i < (REG_NUM - 1)) printf("$%d: 0x%08x\n", i, reg[i]);
            else printf("PC: 0x%08x\n", reg[i]);
        }
    }

    // When third argument is "mem"
    else if (!strncmp(command, "mem", 3)) {
        
        // If fourth argument indicates instruction memory space
        if ((mem_loc >= 0) && (mem_loc < 0x10000))
            for (int i = (mem_loc / 4); i < (mem_loc / 4) + 4; i++) printf("0x%08x\n", inst_mem[i]);

        // If fourth argument indicates data memory space
        else if ((mem_loc >= 0x10000000) && (mem_loc < 0x10010000)) {
            mem_loc -= 0x10000000;
            for (int i = (mem_loc / 4); i < (mem_loc / 4) + 4; i++) printf("0x%08x\n", data_mem[i]);
        }
    }

    if (fclose(fp)) {
        perror("fclose error");
        exit(1);
    }
    return 0;
}