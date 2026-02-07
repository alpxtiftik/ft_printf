/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:45:36 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/02/07 18:45:29 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int ft_formats(va_list args, const char format);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_nbr(int n);
int ft_print_unsigned(unsigned int n);
int ft_print_hex(unsigned int num, const char format);
int ft_print_ptr(unsigned long long ptr);

#endif