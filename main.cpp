#include <iostream>
#include <stdlib.h>
#include <cstring>

int memory_size = 0x10000;
uint8_t* memory = new uint8_t[memory_size];

long pc, sp;
long a, b, c, d;

long* gp_Registers[] = {&a, &b, &c, &d, &sp};

bool f_Halted = false;

uint8_t fetch_byte()
{
    if (pc >= memory_size) return 0;
    uint8_t v = memory[pc];
    pc ++;
    return v;
}

#define NOP 0
#define MOVE_BYTE_TO_REG 1
#define HALT 2

int main(int argc, char** argv)
{
    memset(memory, 0, memory_size);

    pc = 0;
    a = b = c = d = sp = 0;

    memory[0] = MOVE_BYTE_TO_REG;
    memory[1] = 0;
    memory[2] = 'i';
    memory[3] = HALT;

    uint8_t tr1, tr2;
    while (!f_Halted)
    {
        uint8_t opcode = fetch_byte();

        switch (opcode){
            case NOP:
                break;
            case MOVE_BYTE_TO_REG:
                tr1 = fetch_byte();
                tr2 = fetch_byte();

                *gp_Registers[tr1] = tr2;
                break;
            case HALT:
                f_Halted = true;
                break;
            default:
                printf("Unknown instruction 0x%X at 0x%lX", opcode, pc);
            break;
        }
    }

    std::cout << a;

    delete[] memory;
    return 0;
}