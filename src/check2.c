/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:20:47 by ybolles           #+#    #+#             */
/*   Updated: 2019/11/17 23:21:15 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_many_flags(const char *format, t_flags flags)
{
	if (ft_strchr(flags.flg0_0, FORM1))
	{
		if (ft_strchr(flags.flg1, FORM2))
			return (1);
		if (ft_strchr(flags.flg0_0, FORM2) && ft_strchr(flags.flg1, FORM3))
			return (2);
	}
	return (0);
}

t_flags			ft_skip_space(const char *format, t_flags flags)
{
	int cnt;

	cnt = CNT;
	while (FORM1 == ' ')
		CNT++;
	if (ft_strchr(flags.flgx, FORM1))
		flags = ft_read_prec(format, flags);
	if (FORM1 == 'd' || FORM1 == 'i' || (ft_many_flags(format, flags) &&
				(FORM2 == 'd' || FORM2 == 'i' || FORM3 == 'd' || FORM3 == 'i')))
		flags.spc = 1;
	if (!(ft_strchr(flags.flgx, FORM1) || ft_strchr(flags.flg0_0, FORM1) ||
				ft_check_flags(FORM1, flags)))
		CNT = cnt;
	return (flags);
}

t_flags			ft_read_flag(const char *format, va_list ap, t_flags flags)
{
	if (FORM1 == ' ')
		flags = ft_skip_space(format, flags);
	else if (ft_strchr(flags.flgx, FORM1))
		flags = ft_read_prec(format, flags);
	if (ft_check_flags(FORM1, flags))
	{
		if (FORM1 == 'o' || FORM1 == 'x' || FORM1 == 'X' || FORM1 == 'u')
			flags = ft_print_flags(flags, FORM1, (va_arg(ap, unsigned int)));
		if (FORM1 == 's')
			flags = ft_print_str(flags, va_arg(ap, char*), FORM1);
		if (FORM1 == '%')
			flags = ft_print_str(flags, "%", FORM1);
		if (FORM1 == 'c' || FORM1 == 'd' || FORM1 == 'i')
			flags = ft_print_decimal(flags, FORM1, (va_arg(ap, int)));
		if (FORM1 == 'p')
			flags = ft_print_ptr(flags, FORM1,
					(va_arg(ap, unsigned long long int)));
		CNT++;
	}
	else if (ft_strchr(flags.flg0_0, FORM1))
		flags = ft_check_flags2(format, ap, flags);
	return (flags);
}

int				ft_check_flags(char c, t_flags flags)
{
	if (ft_strchr(flags.flg0, c))
		return (1);
	if (ft_strchr(flags.flg1, c))
		return (1);
	if (ft_strchr(flags.flg2, c))
		return (1);
	return (0);
}
