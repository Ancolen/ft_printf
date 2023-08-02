/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:15:14 by myerturk          #+#    #+#             */
/*   Updated: 2023/08/03 01:31:52 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr(int a)
{
	int		i;

	i = 0;
	if (a < 0)
	{
		ft_char("-");
		a *= -1;
		i++;
	}
	if (a > 9)
	{
		i += ft_nbr(a / 10);
		write(1, &"0123456789"[a % 10], 1);
	}
	else
		write(1, &"0123456789"[a], 1);
	return (i);
}

int	ft_unbr(unsigned int a)
{
	int		i;

	i = 0;
	if (a > 9)
	{
		i += ft_unbr(a / 10);
		write(1, &"0123456789"[a % 10], 1);
	}
	else
		write(1, &"0123456789"[a], 1);
	return (i);
}

int	ft_bx(unsigned long long a)
{
	int		i;

	i = 0;
	if (a > 15)
	{
		i += ft_bx(a / 16);
		write(1, &"0123456789ABCDEF"[a % 16], 1);
	}
	else
		write(1, &"0123456789ABCDEF"[a], 1);
	return (i);
}

int	ft_point(unsigned long long a, int x)
{
	int		i;

	i = 0;
	if (x == 1)
	{
		write(1, "0x", 2);
		x = 0;
		i += 2;
	}
	if (a > 15)
	{
		i += ft_point(a / 16, 0);
		write(1, &"0123456789abcdef"[a % 16], 1);
	}
	else
		write(1, &"0123456789abcdef"[a], 1);
	return (i);
}
