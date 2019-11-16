/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:36:31 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/16 20:34:19 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		ft_print_has_xX(t_flags flags, char c)
{
	if (c == 'x' || c == 'p')
		ft_putstr("0x");
	if (c == 'X')
		ft_putstr("0X");
	RTN += 2;
	return (flags);
}

int        print_space(t_flags flags, int len, char c)
{
	int cnt;

	cnt = 0;
	while (cnt++ < len)
	{
		ft_putchar(c);
		RTN++;
	}
	return(RTN);
}

t_flags     print_s(t_flags flags, char *str, int len, char c)
{
	int cnt;

	cnt = 0;
//	ft_putnbr(len);
//	ft_putstr(str);
	if (c != '%')
		len = len >= flags.nbr2 && flags.isprec && flags.nbr2 >= 0 ? flags.nbr2 : len;
	if (flags.sgn == 1 && !flags.is0)
		RTN = print_space(flags, flags.nbr1 - len, ' ');
	if (flags.sgn == 1 && flags.is0)
		RTN = print_space(flags, flags.nbr1 - len, '0');
	while (cnt < len)
		ft_putchar(str[cnt++]);
	if (flags.sgn == -1)
		RTN = print_space(flags, flags.nbr1 - len, ' ');
	RTN += len;
	flags = ft_reset_precision(flags);
	return (flags);
}

t_flags		print_di(t_flags flags, char *str, int len, char c)
{
	int cnt;

	cnt = 0;
	if (flags.isprec)
	{
		if ((str[0] != '0' && flags.hash && (c == 'x' || c == 'X')) || c == 'p')
		{
			flags.nbr1--;
			if (flags.nbr2 < len && !flags.sgn)
				flags.nbr1--;
			if (flags.is0)
				flags.nbr2 -= 2;
			cnt++;
		}
		flags.spc = flags.prec || str[0] == '-' ? 0 : flags.spc;
		RTN = print_space(flags, flags.spc , ' ');
		flags.prec = str[0] == '-'  || (c != 'd' && c != 'i') ? 0 : flags.prec;
		if (str[0] == '-' && !flags.is0)
			cnt++;
		if (flags.is0)
			flags.nbr2 = flags.spc || flags.prec ? flags.nbr2 - 1 : flags.nbr2;
		flags.nbr1 = flags.spc || flags.prec ? flags.nbr1 - 1 : flags.nbr1;
		if (str[0] == '0' && !flags.is0 && !flags.nbr2 && !flags.isnb2)
			len--;
		if (!len && c == 'p')
			flags.nbr1++;
		if (!flags.sgn && flags.nbr2 >= len)
			RTN = print_space(flags, flags.nbr1 - (flags.nbr2 + cnt) , ' ');
		else if (!flags.sgn && flags.nbr2 < len)
			RTN = print_space(flags, flags.nbr1 - len , ' ');
		if  (str[0] == '-' && !flags.is0)
		{
			len--;
			RTN++;
		}
		if (str[0] == '-')
			print_space(flags, 1 , '-');
		RTN = print_space(flags, flags.prec , '+');
		if (cnt && ((flags.hash && (c == 'x' || c == 'X')) || c == 'p'))
			flags = ft_print_has_xX(flags, c);
		if (flags.nbr2 > len)
			RTN = print_space(flags, flags.nbr2 - len , '0');
		if (str[0] == '-')
			str++;
		if (len)
			ft_putstr(str);
		if (flags.sgn && flags.nbr2 >= len)
			RTN = print_space(flags, flags.nbr1 - (flags.nbr2 + cnt) , ' ');
		else if (flags.sgn && flags.nbr2 < len)
			RTN = print_space(flags, flags.nbr1 - (len + cnt) , ' ');
	}
	else
	{
		if (str[0] != '-')
			RTN = print_space(flags, flags.spc , ' ');
		if (c == 'p')
			flags = ft_print_has_xX(flags, c);
		ft_putstr(str);
	}
	RTN += len;
	flags = ft_reset_precision(flags);
	return (flags);
}

t_flags		print_c(t_flags flags, char c)
{
	if (!flags.sgn)
		RTN = print_space(flags, flags.nbr1 - 1 , ' ');
	ft_putchar(c);
	if (flags.sgn)
		RTN = print_space(flags, flags.nbr1 - 1 , ' ');
	RTN++;
	return (flags);
}
