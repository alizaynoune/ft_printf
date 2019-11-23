/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:21:57 by alzaynou          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/11/23 21:21:37 by alzaynou         ###   ########.fr       */
=======
/*   Updated: 2019/11/17 23:31:01 by ybolles          ###   ########.fr       */
>>>>>>> cf035796e6e081e24719fc69361926f60606ff59
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

<<<<<<< HEAD
int				ft_many_flags(const char *format, t_flags flags)
{
	if (ft_strchr(flags.flg0_0, FORM1))
	{
		if (ft_strchr(flags.flg1, FORM2) || (FORM2 == 'f' && FORM1 != 'h'))
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
		flags = ft_read_prec(format, flags, NULL, CNT);
	if (FORM1 == 'd' || FORM1 == 'i' || FORM1 == 'f')
		flags.spc = 1;
	else if ((ft_many_flags(format, flags) && (FORM2 == 'd' || FORM2 == 'i' ||
					FORM3 == 'd' || FORM3 == 'i' || FORM2 == 'f')))
		flags.spc = 1;
	else if (!(ft_strchr(flags.flgx, FORM1) || ft_strchr(flags.flg0_0, FORM1) ||
			ft_check_flags(FORM1, flags)))
		CNT = cnt;
	return (flags);
}

t_flags			ft_read_flag(const char *format, va_list ap, t_flags flags)
{
	if (FORM1 == ' ')
		flags = ft_skip_space(format, flags);
	else if (ft_strchr(flags.flgx, FORM1))
		flags = ft_read_prec(format, flags, NULL, CNT);
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
			flags = ft_print_ptr(flags, FORM1, (va_arg(ap, ULLINT)));
		if (FORM1 == 'f')
			flags = ft_print_double(flags, va_arg(ap, double));
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
=======
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
>>>>>>> cf035796e6e081e24719fc69361926f60606ff59
