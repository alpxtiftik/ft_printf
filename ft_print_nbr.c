/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:25:22 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/02/10 19:44:24 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', 1);
		ft_putchar_fd('2', 1);
		ft_putnbr_fd(147483648, 1);
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
		n = n * (-1);
		ft_putnbr_fd(n, 1);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, 1);
		ft_putnbr_fd(n % 10, 1);
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
		count++;
	}
	return (count);
}