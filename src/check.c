/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:21:57 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/03 19:03:17 by alzaynou         ###   ########.fr       */
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
		cnt ++;
	}
	else if (format[cnt + 1] == '%')
	{
			cnt++;
		ft_putchar(format[cnt]);
	}
/*	else if (ft_strchr(flags.flg1_0, format[cnt + 1]))
		cnt = ft_check_flags2(format, cnt, ap, flags);
*/	return (cnt);
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

