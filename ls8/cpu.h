#ifndef _CPU_H_
#define _CPU_H_

// Holds all information about the CPU
struct cpu
{
  // TODO
  // PC
  unsigned int PC;
  // registers (array) // R0 - R7
  unsigned char registers[8];
  // ram (array) // 8 bit address
  // that can hold up to 256 bytes of RAM total
  unsigned char ram[256];
};

// ALU operations
enum alu_op
{
  ALU_MUL, // what is this???
  ALU_NOP,
  ALU_NOT,
  ALU_POP,
  ALU_PRA,
  ALU_PRN,
  ALU_PUSH,
  ALU_RET,
  ALU_ADD // Add more here
};

// Instructions

// These use binary literals. If these aren't available with your compiler, hex
// literals should be used.

#define LDI 0b10000010
#define HLT 0b00000001
#define PRN 0b01000111
// TODO: more instructions here. These can be used in cpu_run().
#define MUL 0b10100010
#define PUSH 0b01000101
//POP register - pop the value at the top of the stack into the given reg.
// 1 copy the value from the address pointed to by `SP` to the given registrer
// 2 Increment `SP`
#define POP 0b01000110
#define CALL 0b01010000
#define RET 0b00010001
#define ADD 0b10100000

// Function declarations

extern void cpu_load(struct cpu *cpu);
extern void cpu_init(struct cpu *cpu);
extern void cpu_run(struct cpu *cpu);

#endif
