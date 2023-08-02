/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:15:46 by myerturk          #+#    #+#             */
/*   Updated: 2023/08/03 01:32:33 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_nbr(int a);
int	ft_char(char c);
int	ft_str(const char *str);
int	ft_unbr(unsigned int a);
int	ft_bx(unsigned long long a);
int	ft_printf(const char *str, ...);
int	ft_point(unsigned long long a, int x);
int	ft_check(char symbol_result, va_list args);

#endif
