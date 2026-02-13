*This project has been created as part of the 42 curriculum by ahtiftik.*

# ft_printf - Because ft_putnbr() and ft_putstr() aren't enough

## Description
The goal of this project is to recreate the famous `printf()` function from the C standard library. This exercise provides a deep dive into **variadic functions** in C, requiring us to manage a variable number of arguments using the `<stdarg.h>` macros.

The result is a library (`libftprintf.a`) containing `ft_printf()`, which mimics the original function's behavior for specific conversions. It handles formatted output to the standard output and returns the total number of characters printed, just like the original.

## Algorithm and Data Structure
To achieve a modular and extensible design, the project is structured as follows:

### 1. The Core Logic (`ft_printf.c`)
The main function iterates through the format string character by character.
* **Text Processing:** Regular characters are printed immediately using `write` and counted.
* **Parsing:** When a `%` symbol is encountered, the flow is directed to a dispatcher function (`ft_formats`).

### 2. The Dispatcher (`ft_formats.c`)
This function acts as a switch-case handler. It identifies the conversion specifier (e.g., `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`) and calls the corresponding helper function. It utilizes `va_arg` to retrieve the next argument from the `va_list`.

### 3. Helper Functions & Recursion
Instead of complex buffer management, **recursion** was chosen for printing numbers (integers, unsigned, hexadecimal).
* **Why Recursion?** It simplifies the logic for printing digits in the correct order (most significant to least significant) without needing temporary string allocation or reversing arrays.
* **Memory Efficiency:** Since no dynamic allocation (`malloc`) is used for the printing logic itself (except for what is inherited from `libft` if applicable), the function is memory-safe and minimizes the risk of leaks.

### Supported Conversions
| Specifier | Description |
| :--- | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string (as defined by the common C convention). |
| `%p` | The void pointer argument is printed in hexadecimal format. |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a percent sign. |

## Instructions

### 1. Compilation
To compile the library, run the following command at the root of the repository:
```bash
make
```
This will generate the `libftprintf.a` file.

### 2. Cleaning
To keep your directory clean or reset the project:
* To remove object files (`.o`):
    ```bash
    make clean
    ```
* To remove object files and the library file (`.a`):
    ```bash
    make fclean
    ```
* To re-compile everything from scratch:
    ```bash
    make re

### 3. Usage
To integrate `ft_printf` into your own project, include the header file and link the static library during compilation.

**Code Example:**
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! The answer is %d.\n", "42", 42);
    return (0);
}
```
**Compilation Command:**
```bash
cc main.c libftprintf.a -o my_program
./my_program
```
## Resources

### References
* **Man pages:** `man 3 printf` and `man stdarg` were consulted to understand the behavior of variadic arguments and format specifiers.
* **C Standard:** Reviewed to ensure correct handling of edge cases like `INT_MIN` and `NULL` pointers.

### AI Utilization
As per the subject guidelines, AI tools were used in the following capacity:
* **Logic Verification:** AI was used to discuss edge cases (e.g., difference between `%p` output on Mac vs. Linux) and to verify the logic of recursive functions for hexadecimal conversion.
* **Norm Compliance:** AI assisted in checking the code against 42 Norm requirements (function length, variable naming, etc.).
* [cite_start]**Documentation:** AI helped generate the structure of this README to strictly follow the "Chapter V" requirements of the subject pdf[cite: 120].
* *Note: All implementation logic and code writing were performed manually to ensure a thorough understanding of the concepts.*
