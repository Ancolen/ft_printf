/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:46:00 by myerturk          #+#    #+#             */
/*   Updated: 2023/08/21 09:46:11 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_int(int number)
{
	int	len;
	int	value;

	len = 0;
	if (number == -2147483648)
		return (ft_string("-2147483648"));
	if (number < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
		number *= -1;
	}
	if (number >= 10)
	{
		value = ft_int(number / 10);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (ft_putchar("0123456789"[number % 10]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_unsigned(unsigned int number)
{
	int		len;
	int		value;

	len = 0;
	if (number >= 10)
	{
		value = ft_unsigned(number / 10);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (ft_putchar("0123456789"[number % 10]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
	{
		if (ft_string("(null)") == -1)
			return (-1);
		return (6);
	}
	while (str[++i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
	}
	return (i);
}

int	ft_hex(unsigned int number, char format)
{
	int	len;
	int	value;

	len = 0;
	if (number >= 16)
	{
		value = ft_hex(number / 16, format);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (format == 'X')
	{
		if (ft_putchar("0123456789ABCDEF"[number % 16]) == -1)
			return (-1);
	}
	if (format == 'x')
	{
		if (ft_putchar("0123456789abcdef"[number % 16]) == -1)
			return (-1);
	}
	return (len + 1);
}

int	ft_point(unsigned long int number, int mod)
{
	int	len;
	int	value;

	len = 0;
	if (mod == 1)
	{
		if (ft_string("0x") == -1)
			return (-1);
		mod = 0;
		len += 2;
	}
	if (number >= 16)
	{
		value = ft_point(number / 16, mod);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (ft_putchar("0123456789abcdef"[number % 16]) == -1)
		return (-1);
	return (len + 1);
}
