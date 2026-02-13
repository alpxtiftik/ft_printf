*This project has been created as part of the 42 curriculum by ahtiftik.*

# Libft - Your Very First Own Library

## Description
This project aims to create a C library that reimplements a set of standard C library functions (libc) and includes additional utility functions. C programming can be tedious without access to standard functions; this project allows us to understand how these functions work under the hood, manage memory efficiently, and build a reusable library (`libft.a`) for future 42 curriculum projects.

## Contents
The library is divided into three main sections:

1.  **Part 1 - Libc Functions:** Re-implementation of standard functions from the C library (e.g., `ft_strlen`, `ft_memset`, `ft_calloc`).
2.  **Part 2 - Additional Functions:** Utility functions that are either not in the libc or exist in a different form (e.g., `ft_split`, `ft_strjoin`, `ft_itoa`).
3.  **Part 3 - Linked List Functions:** Functions to manipulate linked lists using the `t_list` structure (e.g., `ft_lstnew`, `ft_lstadd_back`).

## Instructions

### 1. Compilation
To compile the mandatory part of the library, run:
```bash
make
```
### 2. Cleaning
To remove object files:

```bash
make clean
```
To remove object files and the library (libft.a):

```bash
make fclean
```
To rebuild the library:

```bash
make re
```

### 3. Usage
To use this library in your code, include the header file and link the library during compilation:

```c
#include "libft.h"

int main(void)
{
    ft_putstr_fd("Hello, 42!", 1);
    return (0);
}
```

Compile your project with:
```bash
cc main.c -L. -lft -o my_program
```
## Resources

### References
* **Man pages:** The primary source of information for standard function behaviors (e.g., `man strlen`, `man 3 malloc`).
* **C Reference:** Used for verifying edge cases and return values of standard functions.

### AI Utilization
As per the subject guidelines, AI tools were used in the following capacity:
* **Makefile & Structure:** AI was consulted to clarify Makefile syntax (specifically implicit rules) and to ensure the project structure complies with 42 norms.
* **Documentation:** AI assisted in generating the template for this README.md file to ensure all submission requirements were met.
* *Note: The logic and implementation of the C functions were written manually to ensure deep understanding of the algorithms.*