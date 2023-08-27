#ifndef instructions_hpp
#define instructions_hpp

#include <stdint.h>
// ...



extern int memory_size;
extern uint8_t* memory;
extern long pc, sp;
extern long a, b, c, d;
extern long* gp_Registers[];
extern long is_halted;
extern void (*instruction_pointers[512])();

#define NOP 0
#define MOVE_BYTE_TO_REG 1
#define HALT 2
#define MOVE_WORD_TO_REG 3
#define MOVE_DWORD_TO_REG 4
#define inst_unsigned_add_reg_imm8 5
#define inst_signed_add_reg_imm8 6
#define inst_unsigned_add_reg_imm16 7
#define inst_signed_add_reg_imm16 8
#define inst_unsigned_add_reg_imm32 9
#define inst_signed_add_reg_imm32 10

void set_instptrs();

void nop();

void move_byte_to_register();
void move_word_to_register();
void move_dword_to_register();

void unsigned_add_reg_imm8();
void signed_add_reg_imm8();

void unsigned_add_reg_imm16();
void signed_add_reg_imm16();

void unsigned_add_reg_imm32();
void signed_add_reg_imm32(); 

void unsigned_add_reg_reg();
void signed_add_reg_reg();

void halt();

#endif