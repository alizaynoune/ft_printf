/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printall2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:47:14 by ybolles           #+#    #+#             */
/*   Updated: 2019/11/17 23:10:51 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		print_di3(t_flags flags, int cnt, int len, char c)
{
	if (!flags.sgn && flags.nbr2 >= len)
		RTN = print_space(flags, flags.nbr1 - (flags.nbr2 + cnt), ' ');
	else if (!flags.sgn && flags.nbr2 < len)
		RTN = print_space(flags, flags.nbr1 - len, ' ');
	if (flags.str[0] == '-' && !flags.is0)
	{
		len--;
		RTN++;
	}
	if (flags.str[0] == '-')
		print_space(flags, 1, '-');
	RTN = print_space(flags, flags.prec, '+');
	if (cnt && ((flags.hash && (c == 'x' || c == 'X')) || c == 'p'))
		flags = ft_print_has_x(flags, c);
	if (flags.nbr2 > len)
		RTN = print_space(flags, flags.nbr2 - len, '0');
	if (flags.str[0] == '-')
		flags.str++;
	if (len)
		ft_putstr(flags.str);
	if (flags.sgn && flags.nbr2 >= len)
		RTN = print_space(flags, flags.nbr1 - (flags.nbr2 + cnt), ' ');
	else if (flags.sgn && flags.nbr2 < len)
		RTN = print_space(flags, flags.nbr1 - (len + cnt), ' ');
	return (flags);
}

t_flags		print_di2(t_flags flags, int cnt, int len, char c)
{
	if ((flags.str[0] != '0' && flags.hash && (c == 'x' || c == 'X'))
			|| c == 'p')
	{
		flags.nbr1--;
		if (flags.nbr2 < len && !flags.sgn)
			flags.nbr1--;
		if (flags.is0)
			flags.nbr2 -= 2;
		cnt++;
	}
	flags.spc = flags.prec || flags.str[0] == '-' ? 0 : flags.spc;
	RTN = print_space(flags, flags.spc, ' ');
	flags.prec = flags.str[0] == '-' || (c != 'd' && c != 'i') ? 0 : flags.prec;
	if (flags.str[0] == '-' && !flags.is0)
		cnt++;
	if (flags.is0)
		flags.nbr2 = flags.spc || flags.prec ? flags.nbr2 - 1 : flags.nbr2;
	flags.nbr1 = flags.spc || flags.prec ? flags.nbr1 - 1 : flags.nbr1;
	if (flags.str[0] == '0' && !flags.is0 && !flags.nbr2 && !flags.isnb2)
		len--;
	if (!len && c == 'p')
		flags.nbr1++;
	flags = print_di3(flags, cnt, len, c);
	return (flags);
}

t_flags		print_di(t_flags flags, char *str, int len, char c)
{
	int cnt;

	cnt = 0;
	flags.str = str;
	if (flags.isprec)
	{
		flags = print_di2(flags, cnt, len, c);
	}
	else
	{
		if (flags.str[0] != '-')
			RTN = print_space(flags, flags.spc, ' ');
		if (c == 'p')
			flags = ft_print_has_x(flags, c);
		ft_putstr(str);
	}
	RTN += len;
	flags = ft_reset_precision(flags);
	return (flags);
}
