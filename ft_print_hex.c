/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:25:58 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/02/10 19:26:53 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int num, const char format)
{
	int		count;
	char	*basestr;

	count = 0;
	if (format == 'x')
		basestr = "0123456789abcdef";
	else
		basestr = "0123456789ABCDEF";
	if (num >= 16)
		count += ft_print_hex(num / 16, format);
	ft_putchar_fd(basestr[num % 16], 1);
	count++;
	return (count);
}
