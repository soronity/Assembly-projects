# Assembly# Language Specification

## Instructions

| **Type** | **Encoding** |
|:---------|:-------------|
| Register | `op<7:5>, reg<4:3>, res<2:1>, immediate<0>` |
| Jump     | `op<7:5>, address<4:0>` |
| Special  | `op<7:5>` |

### Register Instructions

| **Instruction** | **Description** |
|:----------------|:----------------|
| `+`           | `res = res + reg + immediate` |
| `-`           | `res = res - reg - immediate`  |
| `set`           | `res = reg + immediate` |
| `jifeq`           | Jump one line if `(res == reg && immediate) || (res != reg && !i)`. |

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

    - #zer0    // always equals 0
    - #io    // handles I/O
    - #int1                                    
    - #int2