#include "instructions.hpp"

#include <stdint.h>
#include <iostream>
#include "main.hpp"

void set_instptrs()
{
    instruction_pointers[NOP] = &nop;
    instruction_pointers[MOVE_BYTE_TO_REG] = &move_byte_to_register;
    instruction_pointers[MOVE_WORD_TO_REG] = &move_word_to_register;
    instruction_pointers[MOVE_DWORD_TO_REG] = &move_dword_to_register;
    instruction_pointers[HALT] = &halt;


    instruction_pointers[inst_unsigned_add_reg_imm8] = &unsigned_add_reg_imm8;
}

void nop()
{
    return;
}

void move_byte_to_register()
{
    uint8_t destination_register = fetch_byte();
    uint8_t source_immediate = fetch_byte();

    *gp_Registers[destination_register] = source_immediate;

    return;
}

void move_word_to_register()
{
    uint8_t destination_register = fetch_byte();
    uint16_t source_immediate = fetch_word();

    *gp_Registers[destination_register] = source_immediate;

    return;
}

void move_dword_to_register()
{
    uint8_t destination_register = fetch_byte();
    uint32_t source_immediate = fetch_dword();

    *gp_Registers[destination_register] = source_immediate;

    return;
}

void unsigned_add_reg_imm8()
{
    uint8_t source_register = fetch_byte();
    uint8_t source_destination = fetch_byte();

    *gp_Registers[0] = *gp_Registers[source_register] + source_destination;

    return;
}

void halt()
{
    std::cout << "The halt has been raised.\n";

    is_halted = true;
    return;
}