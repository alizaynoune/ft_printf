/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:21:57 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/17 23:31:01 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags			ft_check(const char *format, t_flags flags, va_list ap)
{
	if (FORM1 == 'l' && ft_strchr(flags.flg1, FORM2))
	{
		if (FORM2 == 'd' || FORM2 == 'i')
			flags = ft_print_long_di(flags, va_arg(ap, long int));
		if (FORM2 == 'x' || FORM2 == 'X' || FORM2 == 'o' || FORM2 == 'u')
			flags = ft_print_ulong(flags, FORM2, va_arg(ap, unsigned long int));
		CNT += 2;
	}
	if (FORM1 == 'l' && FORM2 == 'l' && ft_strchr(flags.flg1, FORM3))
	{
		if (FORM3 == 'x' || FORM3 == 'X' || FORM3 == 'o' || FORM3 == 'u')
			flags = ft_print_ptr(flags, FORM3,
					(va_arg(ap, unsigned long long int)));
		if (FORM3 == 'i' || FORM3 == 'd')
			flags = ft_print_long_long_di(flags, va_arg(ap, long long int));
		CNT += 3;
	}
	return (flags);
}

t_flags			ft_check_flags2(const char *format, va_list ap, t_flags flags)
{
	flags = ft_check(format, flags, ap);
	if (FORM1 == 'h' && ft_strchr(flags.flg1, FORM2))
	{
		if (FORM2 == 'd' || FORM2 == 'i')
			flags = ft_print_short_di(flags, (short int)(va_arg(ap, int)));
		if (FORM2 == 'x' || FORM2 == 'X' || FORM2 == 'o' || FORM2 == 'u')
			flags = ft_print_ushort(flags, FORM2,
					(unsigned short int)(va_arg(ap, unsigned int)));
		CNT += 2;
	}
	else if (FORM1 == 'h' && FORM2 == 'h' && ft_strchr(flags.flg1, FORM3))
	{
		if (FORM3 == 'd' || FORM3 == 'i')
			flags = ft_print_schar_di(flags, (char)(va_arg(ap, int)));
		if (FORM3 == 'x' || FORM3 == 'X' || FORM3 == 'o' || FORM3 == 'u')
			flags = ft_print_uchar(flags, FORM3, (unsigned char)
					((va_arg(ap, unsigned int))));
		CNT += 3;
	}
	return (flags);
}
