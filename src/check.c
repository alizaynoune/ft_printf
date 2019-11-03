/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:21:57 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/04 00:12:11 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_read_flag(const char *format, int cnt, va_list ap, t_flags flags)
{
	if (ft_check_flags(format[cnt + 1], flags))
	{
		if (format[cnt + 1] == 'o' || format[cnt + 1] == 'x' ||
				format[cnt + 1] == 'X' || format[cnt + 1] == 'u')
			ft_print_flags(format[cnt + 1], (va_arg(ap, unsigned int)));
		if (format[cnt + 1] == 's')
			ft_putstr(va_arg(ap, char*));
		if (format[cnt + 1] == 'c' || format[cnt + 1] == 'd' ||
				format[cnt + 1] == 'i')
			ft_print_decimal(format[cnt + 1], (va_arg(ap, int)));
		if(format[cnt + 1] == 'p')
			ft_print_ptr(format[cnt + 1], (va_arg(ap, unsigned long long int)));
		cnt ++;
	}
	else if (format[cnt + 1] == '%')
	{
			cnt++;
		ft_putchar(format[cnt]);
	}
	else if (ft_strchr(flags.flg0_0, format[cnt + 1]))
		cnt = ft_check_flags2(format, cnt + 1, ap, flags);
	return (cnt);
}

int			ft_check_flags(char c, t_flags flags)
{
	if (ft_strchr(flags.flg0, c))
		return (1);
	if (ft_strchr(flags.flg1, c))
		return (1);
	if (ft_strchr(flags.flg2, c))
		return (1);
	return (0);
}

int			ft_check_flags2(const char *format, int cnt, va_list ap, t_flags flags)
{
	if (format[cnt] == 'l' && format[cnt + 1] == 'l')
	{
		if (format[cnt + 2] == 'x' || format[cnt + 2] == 'X' || format[cnt + 2] == 'o' || format[cnt + 2] == 'u')
			ft_print_ptr(format[cnt + 2], (va_arg(ap, unsigned long long int)));
		if (format[cnt + 2] == 'i' || format[cnt + 2] == 'd')
			ft_print_long_long_di(va_arg(ap, long long int));
	}
	cnt += 2;
	return (cnt);
}
