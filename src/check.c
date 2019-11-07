/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:21:57 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/07 21:53:23 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags			ft_read_flag(const char *format, va_list ap, t_flags flags)
{
	if (ft_strchr(flags.flgx, FORM1))
		flags = ft_read_prec(format, flags);
	if (ft_check_flags(FORM1, flags))
	{
		if (FORM1 == 'o' || FORM1 == 'x' || FORM1 == 'X' || FORM1 == 'u')
			flags = ft_print_flags(flags, FORM1, (va_arg(ap, unsigned int)));
		if (FORM1 == 's')
			flags = ft_print_str(flags, va_arg(ap, char*));
		if (FORM1 == 'c' || FORM1 == 'd' || FORM1 == 'i')
			flags = ft_print_decimal(flags, FORM1, (va_arg(ap, int)));
		if(FORM1 == 'p')
			flags = ft_print_ptr(flags, FORM1, (va_arg(ap, unsigned long long int)));
		CNT++;
	}
	else if (FORM1 == '%')
	{
			CNT++;
			RTN++;
		ft_putchar(FORM0);
	}
	else if (ft_strchr(flags.flg0_0, FORM1))
		flags = ft_check_flags2(format, ap, flags);
	return (flags);
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

t_flags			ft_check_flags2(const char *format, va_list ap, t_flags flags)
{
	if (FORM1 == 'l' && ft_strchr(flags.flg1, FORM2))
	{
		if (FORM2 == 'd' || FORM2 == 'i')
			flags = ft_print_long_di(flags, va_arg(ap, long int));
		if (FORM2 == 'x' || FORM2 == 'X' || FORM2 == 'o' ||FORM2 == 'u')
			flags = ft_print_ulong(flags, FORM2, va_arg(ap, unsigned long int));
		CNT += 2;
	}
	if (FORM1 == 'l' && FORM2 == 'l' && ft_strchr(flags.flg1, FORM3))
	{
		if (FORM3 == 'x' || FORM3 == 'X' || FORM3 == 'o' || FORM3 == 'u')
			flags = ft_print_ptr(flags, FORM3, (va_arg(ap, unsigned long long int)));
		if (FORM3 == 'i' || FORM3 == 'd')
			flags = ft_print_long_long_di(flags, va_arg(ap, long long int));
		CNT += 3;
	}
	else if (FORM1 == 'h' && ft_strchr(flags.flg1, FORM2))
	{
		if (FORM2 == 'd' || FORM2 == 'i')
			flags = ft_print_short_di(flags, (short int)(va_arg(ap, int)));
		if (FORM2 == 'x' || FORM2 == 'X' || FORM2 == 'o' || FORM2 == 'u')
			flags = ft_print_ushort(flags, FORM2, (unsigned short int)(va_arg(ap, unsigned int)));
		CNT += 2;
	}
	else if (FORM1 == 'h' && FORM2 == 'h' && ft_strchr(flags.flg1, FORM3))
	{
		if (FORM3 == 'd' || FORM3 == 'i')
			flags = ft_print_schar_di(flags, (char)(va_arg(ap, int)));
		if (FORM3 == 'x' || FORM3 == 'X' || FORM3 == 'o' || FORM3 == 'u')
			flags = ft_print_uchar(flags, FORM3, (unsigned char)((va_arg(ap, unsigned int))));
		CNT += 3;
	}
	return (flags);
}

t_flags		ft_read_prec(const char *format, t_flags flags)
{
	int		cnt;
	char	*sflg;

	cnt = CNT;
	while (ft_strchr(flags.flgx, FORM1))
		CNT++;
	if (ft_strchr(flags.flg1, FORM1) || ft_strchr(flags.flg0, FORM1))
	{
		SAFE(sflg = (char *)malloc(sizeof(char) * ((CNT - cnt) + 1)));
		CNT = cnt;
		while (ft_strchr(flags.flgx, FORM1))
			sflg[(CNT++) - cnt] = FORM1;
		flags = ft_get_precision(flags, sflg);
	}
	else
		CNT = cnt;
	return (flags);
}

t_flags		ft_print_all(t_flags flags, char *str, int len)
{
	if (flags.prec < 0)
	{
		RTN += len;
		flags.prec = (flags.prec * -1) - len;
		ft_putstr(str);
		while (flags.prec > 0)
		{
			ft_putchar(flags.chr);
			flags.prec--;
			RTN++;
		}
	}
	else
	{
		RTN += len;
		flags.prec -= len;
		while (flags.prec > 0)
		{
			ft_putchar(flags.chr);
			flags.prec--;
			RTN++;
		}
		ft_putstr(str);
	}
	flags.prec = 0;
	return (flags);
}
#include <stdio.h>
t_flags		print_s(t_flags flags, char *str, int len)
{
	int cnt;
	char *dst;

	cnt = 0;
	dst = "(null)";
/*	if (flags.sgn == -1)
		ft_putstr(str);*/
		flags.nbr1 = flags.nbr1 < 0 ? flags.nbr1 * -1 : flags.nbr1;
	if (flags.nbr1 != 0 || flags.nbr2 != 0)
	{
		if(ft_strcmp(dst, str) == 0)
			len = 0;
		flags.nbr2 =  len == 0  && flags.nbr2 == 0 ? 0 : flags.nbr2;
		flags.nbr2 = flags.nbr2 == 0 ? len : flags.nbr2;
		while ((flags.nbr1 - flags.nbr2) > 0 && flags.sgn == 2)
		{
			ft_putchar(' ');
			flags.nbr1--;
			RTN++;
		}
		while (str[cnt] && flags.nbr2 > cnt && flags.nbr2 != 0)
			ft_putchar(str[cnt++]);
		if (flags.nbr2 != cnt)
			flags.nbr1 += flags.nbr2 - cnt;
		while ((flags.nbr1 - flags.nbr2) > 0 && flags.sgn == 1)
		{
			ft_putchar(' ');
			flags.nbr1--;
			RTN++;
		}
		RTN += cnt;
	}
	else
	{
		ft_putstr(str);
		RTN += len;
	}
	return (flags);
}
