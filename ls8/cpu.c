#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpu.h"

#define DATA_LEN 6
#define LDI 0b10000010
#define NOP 0b00000000
#define PRN 0b01000111
#define HLT 0b00000001
#define STR 0b00001000 // store the next value to reg

// read what is in the ram
// `MAR`: Memory Address Register, holds the memory address we're reading or writing
int cpu_ram_read(struct cpu *cpu, unsigned char mar)
{
  return cpu->ram[mar];
};

// write to the ram
// * `MDR`: Memory Data Register, holds the value to write or the value just read
void cpu_ram_write(struct cpu *cpu, unsigned char mdr)
{
  cpu->ram[mdr] = mdr;
};

/**
 * Load the binary bytes from a .ls8 source file into a RAM array
 */
void cpu_load(struct cpu *cpu, char *filename)
{
  // open the file
  FILE *fp = fopen(filename, "r");
  // check if the file is empty and return error
  if (fp == NULL)
  {
    fprintf(stderr, "ls8: error opening file:  %s\n", filename);
    exit(2);
  }

  char line[9999]; // hold lines
  int address = 0;
  // while fgets still has stuff
  while (fgets(line, sizeof(line), fp) != NULL)
  {
    char *endptr; // grabs none int lines
    // converts string to ints
    unsigned char val = strtoul(line, &endptr, 2);
    // prevents collecting none int lines
    if (line == endptr)
    {
      continue;
    }
    // store in memory
    cpu->ram[address++] = val;
  }
  fclose(fp);
}

/**
 * ALU
 */
void alu(struct cpu *cpu, enum alu_op op, unsigned char regA, unsigned char regB) // what are these?
{
  switch (op)
  {
  case ALU_MUL:
    //Multiply the values in two registers together and store the result in registerA.
    cpu->reg[regA] = regA * regB;
    break;
  case ALU_NOP:
    // No operation. Do nothing for this instruction
    break;
  case ALU_NOT:
    break;
    // TODO: implement more ALU ops
  case ALU_POP:
    // Pop the value at the top of the stack into the given register.
    // 1. Copy the value from the address pointed to by `SP` to the given register.2. Increment `SP`.
    break;
  case ALU_PRA:
    // `PRA register` pseudo - instruction
    //Print alpha character value stored in the given register.
    //Print to the console the ASCII character corresponding to the value in the register.
    break;
  case ALU_PRN:
    /* `PRN register` pseudo-instruction

    Print numeric value stored in the given register.
Print to the console the decimal integer value that is stored in the given register.

Machine code :
``` 01000111 00000rrr 47 0r
```*/
    break;
  case ALU_PUSH:
    /*`PUSH register`

Push the value in the given register on the stack.

1. Decrement the `SP`.
2. Copy the value in the given register to the address pointed to by
   `SP`.*/
    break;
  case ALU_RET:
    /*Pop the value from the top of the stack and store it in the `PC`.*/
    break;
  }
}

/**
 * Run the CPU
 */
void cpu_run(struct cpu *cpu)
{
  int running = 1; // True until we get a HLT instruction

  while (running)
  {
    // TODO
    // 1. Get the value of the current instruction (in address PC).
    // 2. Figure out how many operands this next instruction requires
    // 3. Get the appropriate value(s) of the operands following this instruction
    // 4. switch() over it to decide on a course of action.
    // 5. Do whatever the instruction should do according to the spec.
    // 6. Move the PC to the next instruction.
  }
}

/**
 * Initialize a CPU struct
 */
void cpu_init(struct cpu *cpu)
{
  // TODO: Initialize the PC and other special registers
  // R0 - R6 are cleared to 0
  for (int i = 0; i < 6; i++)
  {
    // cpu->PC = '0';
    cpu->registers[i] = 0;
  }
  // R7 is set to 0xF4
  cpu->registers[7] = '0xF4';
  // PC is set to 0
  cpu->PC = 0;
  // RAM is set to 0
  void memset(cpu->ram, 0, sizeof(cpu->ram));
}
