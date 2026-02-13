/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:25:42 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/02/10 19:25:51 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uns(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_print_uns(n / 10);
		count += ft_print_uns(n % 10);
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
		count = 1;
	}
	return (count);
}
