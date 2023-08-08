# Assembly# Language Specification

Assembly# is a 32-bit language with 8-bit instructions. The syntax is an amalgamation of C#, the MIPS 32-bit instruction encoding and my (possibly over the top) desire for super explicit and understandable code. 

| **Type** | **Encoding** |
|:---------|:-------------|
| Register | `op<7:5>, register<4:3>, result<2:1>, immediate<0>` |
| Jump     | `op<7:5>, address<4:0>` |
| Special  | `op<7:5>` |

### Register Instructions

| **Instruction** | **Description** |
|:----------------|:----------------|
| `add`           | `result = result + register + immediate` |
| `subtract`      | `result = result - register - immediate`  |
| `addImmediateToResult` | `result = register + immediate` |
| `conditionalJump` | Jump one line if `(result == register && immediate) || (result != register && !immediate)`. |

### Jump Instructions

| **Instruction** | **Description** |
|:----------------|:----------------|
| `jump`          | Jump `address` lines. |

### Special Instructions

| **Instruction** | **Description** |
|:----------------|:----------------|
| `consoleReadLine`         | Get integer value from standard input stream and store in `#inputOutput`. |
| `consoleWriteLine` | Write the value of `#inputOutput` to the standard output stream. |
| `environmentExit`     | Terminate program. |

## Registers

    There are four registers that can hold 32 bits of 
    data (integers). They are annotated by a US dollar sign ($) because money makes the world go round ($$$!!). Jokes aside, it's simply to stay congruent with the MIPS assembly convention of having the dollar sign as the intial token of a register name. 

    - $zero           // always equals 0
    - $inputOutput    // handles I/O
    - $temporary1     // general-purpose
    - $temporary2     // general-purpose