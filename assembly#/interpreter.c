#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int zero;
    int inputOutput;
    int temporary1;
    int temporary2;
} Registers;

typedef struct
{
    int data[1024]; // Define the size of your memory
} Memory;

typedef struct
{
    int op;
    int registerIndex;
    int resultIndex;
    int immediate;
} Instruction;

/*
Instruction Format:
- Bits 7-5: Operation code (op)
- Bits 4-3: Register index (registerIndex)
- Bits 2-1: Result index (resultIndex)
- Bit 0: Immediate value (immediate)
*/

void executeAdd(Registers *regs, Memory *mem, Instruction instr);
void executeAddImmediateToResult(Registers *regs, Instruction instr);
void executeSubtract(Registers *regs, Memory *mem, Instruction instr);
void executeConditionalJump(Registers *regs, Instruction instr, int *programCounter);

int main()
{
    FILE *file = fopen("factorial.asms", "r"); // Open your code file
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    Registers regs = {0, 0, 0, 0}; // Initialize registers
    Memory mem;                    // Initialize memory (you might need to initialize memory values)

    Instruction instructions[100]; // Array to store instructions
    int instructionCount = 0;

    // Read and decode instructions
    while (fscanf(file, "%d %d %d %d", &instructions[instructionCount].op,
                  &instructions[instructionCount].registerIndex,
                  &instructions[instructionCount].resultIndex,
                  &instructions[instructionCount].immediate) == 4)
    {
        instructionCount++;
    }

    fclose(file);

    // Instructions are stored in the 'instructions' array
    // Proceed to executing them

    int programCounter = 0; // Keep track of the current instruction index

    while (programCounter < instructionCount)
    {
        Instruction instr = instructions[programCounter];

        switch (instr.op)
        {
        case 0:
            executeAdd(&regs, &mem, instr);
            break;
        case 1:
            executeAddImmediateToResult(&regs, instr);
            break;
        case 2:
            executeSubtract(&regs, &mem, instr);
            break;
        case 3:
            executeConditionalJump(&regs, instr, &programCounter);
            break;
        }

        programCounter++; // Move to the next instruction
    }

    // ... (print result or do other processing)
    return 0;
}

void executeAdd(Registers *regs, Memory *mem, Instruction instr)
{
    int registerValue = mem->data[instr.registerIndex];
    int resultValue = regs->inputOutput;
    int sum = resultValue + registerValue + instr.immediate;

    switch (instr.resultIndex)
    {
    case 1:
        regs->inputOutput = sum;
        break;
    case 2:
        regs->temporary1 = sum;
        break;
    case 3:
        regs->temporary2 = sum;
        break;
        // Add cases for other result indices
    }
}

void executeAddImmediateToResult(Registers *regs, Instruction instr)
{
    int resultValue = regs->inputOutput;
    int sum = resultValue + instr.immediate;

    switch (instr.resultIndex)
    {
    case 1:
        regs->inputOutput = sum;
        break;
    case 2:
        regs->temporary1 = sum;
        break;
    case 3:
        regs->temporary2 = sum;
        break;
        // Add cases for other result indices
    }
}

void executeSubtract(Registers *regs, Memory *mem, Instruction instr)
{
    int registerValue = mem->data[instr.registerIndex];
    int resultValue = regs->inputOutput;
    int difference = resultValue - registerValue - instr.immediate;

    switch (instr.resultIndex)
    {
    case 1:
        regs->inputOutput = difference;
        break;
    case 2:
        regs->temporary1 = difference;
        break;
    case 3:
        regs->temporary2 = difference;
        break;
        // Add cases for other result indices
    }
}

void executeSubtract(Registers *regs, Memory *mem, Instruction instr)
{
    int registerValue = mem->data[instr.registerIndex];
    int resultValue = regs->inputOutput;
    int difference = resultValue - registerValue - instr.immediate;

    switch (instr.resultIndex)
    {
    case 1:
        regs->inputOutput = difference;
        break;
    case 2:
        regs->temporary1 = difference;
        break;
    case 3:
        regs->temporary2 = difference;
        break;
        // Add cases for other result indices
    }
}

void executeConditionalJump(Registers *regs, Instruction instr, int *programCounter)
{
    int conditionMet = (regs->inputOutput == mem->data[instr.registerIndex] && instr.immediate) ||
                       (regs->inputOutput != mem->data[instr.registerIndex] && !instr.immediate);

    if (conditionMet)
    {
        *programCounter += instr.resultIndex; // Jump to the specified address
    }
}
