#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void compare(int ret_std, int ret_ft)
{
    if (ret_std == ret_ft)
        printf(" -> [OK] Return: %d\n\n", ret_ft);
    else
        printf(" -> [KO] STD: %d | FT: %d\n\n", ret_std, ret_ft);
}

int main(void)
{
    int std;
    int ft;
    char *null_str = NULL;

    printf("========== SIMPLE CONVERSION MANAGEMENT ==========\n\n");

    printf("--- Test 1: %%c ---\n");
    std = printf("STD: %c %c %c\n", 'a', 'Z', 0);
    ft = ft_printf("FT : %c %c %c\n", 'a', 'Z', 0);
    compare(std, ft);

    printf("--- Test 2: %%s (Normal, Empty, NULL) ---\n");
    std = printf("STD: [%s] [%s] [%s]\n", "hello", "", null_str);
    ft = ft_printf("FT : [%s] [%s] [%s]\n", "hello", "", null_str);
    compare(std, ft);

    printf("--- Test 3: %%p (Pointer and NULL pointer) ---\n");
    std = printf("STD: %p %p\n", &std, null_str);
    ft = ft_printf("FT : %p %p\n", &std, null_str);
    compare(std, ft);

    printf("--- Test 4: %%d & %%i (0, Positive, Negative, MIN, MAX) ---\n");
    std = printf("STD: %d %i %d %i %d\n", 0, 42, -42, INT_MIN, INT_MAX);
    ft = ft_printf("FT : %d %i %d %i %d\n", 0, 42, -42, INT_MIN, INT_MAX);
    compare(std, ft);

    printf("--- Test 5: %%u (0, Positive, MAX) ---\n");
    std = printf("STD: %u %u %u\n", 0, 42, UINT_MAX);
    ft = ft_printf("FT : %u %u %u\n", 0, 42, UINT_MAX);
    compare(std, ft);

    printf("--- Test 6: %%x & %%X (0, Normal, MAX) ---\n");
    std = printf("STD: %x %X %x %X\n", 0, 0, UINT_MAX, UINT_MAX);
    ft = ft_printf("FT : %x %X %x %X\n", 0, 0, UINT_MAX, UINT_MAX);
    compare(std, ft);

    printf("--- Test 7: %% ---\n");
    std = printf("STD: %% %%%% %%%%%%\n");
    ft = ft_printf("FT : %% %%%% %%%%%%\n");
    compare(std, ft);

    printf("========== GET CRAZY ==========\n\n");

    printf("--- Test 8: Multiple identical conversions ---\n");
    std = printf("STD: %d %d %d %d %d\n", 1, 2, 3, 4, 5);
    ft = ft_printf("FT : %d %d %d %d %d\n", 1, 2, 3, 4, 5);
    compare(std, ft);

    printf("--- Test 9: Various conversions within a sentence ---\n");
    std = printf("STD: String: %s, Char: %c, Int: %d, Hex: %x, Ptr: %p, Pct: %%\n", "test", 'X', -123, 255, &ft);
    ft = ft_printf("FT : String: %s, Char: %c, Int: %d, Hex: %x, Ptr: %p, Pct: %%\n", "test", 'X', -123, 255, &ft);
    compare(std, ft);

    printf("========== EDGE CASES (Tanımsız/Hata Durumları) ==========\n\n");

    printf("--- Test 10: Sadece %% (Return -1 olmalı) ---\n");
    std = printf("%");
    printf("\n");
    ft = ft_printf("%");
    printf("\n");
    compare(std, ft);

    printf("--- Test 11: Tanınmayan Specifier (%%y) ---\n");
    std = printf("STD: %y\n");
    ft = ft_printf("FT : %y\n");
    compare(std, ft);

    return (0);
}