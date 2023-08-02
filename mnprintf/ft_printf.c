/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:15:31 by myerturk          #+#    #+#             */
/*   Updated: 2023/08/03 01:28:39 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_str(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_char(str[i]);
		i++;
	}
	return (i);
}

int	ft_check(char symbol_result, va_list args)
{
	int		ret;

	ret = 0;
	if (symbol_result == 'c')
		ret += ft_char(va_arg(args, int));
	else if (symbol_result == 's')
		ret += ft_str(va_arg(args, const char *));
	else if (symbol_result == 'p')
		ret += (ft_point(va_arg(args, unsigned long long), 1));
	else if (symbol_result == 'X')
		ret += (ft_bx(va_arg(args, unsigned int)));
	else if (symbol_result == 'x')
		ret += (ft_point(va_arg(args, unsigned int), 0));
	else if (symbol_result == '%')
		ret += ft_char('%');
	else if (symbol_result == 'd' || symbol_result == 'i')
		ret += ft_nbr(va_arg(args, int *));
	else if (symbol_result == 'u')
		ret += ft_unbr(va_arg(args, unsigned int *));
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		ret;

	i = 0;
	va_start(args, str);
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ret += ft_check(str[i], args);
		}
		else
			ret += ft_char(str[i]);
		i++;
	}
	va_end(args);
	return (ret);
}
/*
int main() {
    char c = 'A';
    char str[] = "Hello, world!";
    int num = -42;
    unsigned int uns_num = 123456;
    void *ptr = (void *)0x12345678;

    ft_printf("%%c: %c\n", c);
    ft_printf("%%s: %s\n", str);
    ft_printf("%%p: %p\n", ptr);
    ft_printf("%%d: %d\n", num);
    ft_printf("%%i: %i\n", num);
    ft_printf("%%u: %u\n", uns_num);
    ft_printf("%%x: %x\n", uns_num);
    ft_printf("%%X: %X\n", uns_num);
    ft_printf("%%%%: %%\n");
    return 0;
}*/