#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "instructions.hpp"
#include <byteswap.h>

int memory_size = 0x10000;
uint8_t* memory = new uint8_t[memory_size];

long pc, sp;
long a, b, c, d;
long* gp_Registers[] = {&a, &b, &c, &d, &sp};
long is_halted = false;


uint8_t fetch_byte()
{
    if (pc >= memory_size)
    {
        std::cout << "Program counter is greater or equal to memory size.\n";

        return 0;
    }
    uint8_t v = memory[pc];
    pc ++;
    return v;
}

uint16_t fetch_word()
{
    uint16_t p_A = fetch_byte();
    uint16_t p_B = fetch_byte() << 8; 

    uint16_t v = p_A | p_B;

    v = __bswap_16(v);

    return v;
}

uint32_t fetch_dword()
{
    uint32_t p_A = __bswap_16(fetch_word());
    uint32_t p_B = __bswap_16(fetch_word()) << 16;

    uint32_t v = p_A | p_B;

    v = __bswap_32(v);

    return v;
}

void reset()
{
    std::cout << "[info] CPU Reset.\n";

    pc = a = b = c = d = sp = 0;
    is_halted = false;
}

void (*instruction_pointers[512])() = { NULL };

void registers_decor_print()
{
    for (int i = 0; 5 > i; i++)
    {
        printf("Reg [%x]: 0x%lX\n", i, *gp_Registers[i]);
    }
}

int main(int argc, char** argv)
{
    memset(memory, 0, memory_size);

    memory[0] = inst_unsigned_add_reg_imm8;
    memory[1] = 0;
    memory[2] = 10;
    memory[3] = HALT;

    set_instptrs();
    reset();

    while (!is_halted)
    {
        uint8_t instruction = fetch_byte();
        void (*p)() = instruction_pointers[instruction];

        if (p == NULL)
        {
            printf("[error] Invalid instruction at: 0x%lX. (Inst: 0x%x)\n", pc, instruction);

            break;
        }

        p();
    }

    registers_decor_print();

    delete[] memory;
    return 0;
}