# Assembly# Language Specification

Syntax is an amalgamation of C# and my wackiness 


## Instructions

| **Type** | **Encoding** |
|:---------|:-------------|
| Register | `op<7:5>, register<4:3>, result<2:1>, immediate<0>` |
| Jump     | `op<7:5>, address<4:0>` |
| Special  | `op<7:5>` |

### Register Instructions

| **Instruction** | **Description** |
|:----------------|:----------------|
| `plus`           | `result = result + register + immediate` |
| `minus`           | `result = result - register - immediate`  |
| `addImmediate`           | `result = register + immediate` |
| `jumpIfEqual`           | Jump one line if `(result == register && immediate) || (result != register && !immediate)`. |

### Jump Instructions

| **Instruction** | **Description** |
|:----------------|:----------------|
| `jump`             | Jump `address` lines. |

### Special Instructions

| **Instruction** | **Description** |
|:----------------|:----------------|
| `input`         | Get integer value from standard input stream and store in `#io`. |
| `consolewriteline`         | Write the value of `#io` to the standard output stream. |
| `terminate`          | Terminate program. |

## Registers

    There are four registers that can hold 32 bits of 
    data (integers). They are annotated by an octothorpe, aka a number sign (#) 

    - #zero    // always equals 0
    - #io    // handles I/O
    - #int1                                    
    - #int2