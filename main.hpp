#ifndef main_h
#define main_h

#include <stdint.h>

extern int memory_size;
extern uint8_t* memory;
extern long pc, sp;
extern long a, b, c, d;
extern long* gp_Registers[];
extern long is_halted;
extern void (*instruction_pointers[512])();

void reset();
uint8_t fetch_byte();
uint16_t fetch_word();
uint32_t fetch_dword();

#endif