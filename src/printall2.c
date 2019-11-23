/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printall2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2019/11/23 17:02:34 by ybolles           #+#    #+#             */
/*   Updated: 2019/11/23 17:30:42 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags		ft_print_has_xx(t_flags flags, char c)
{
	if (c == 'x' || c == 'p')
		ft_putstr("0x");
	if (c == 'X')
		ft_putstr("0X");
	RTN += 2;
	return (flags);
}

int			print_space(t_flags flags, int len, char c)
{
	int cnt;

	cnt = 0;
	while (cnt++ < len)
	{
		ft_putchar(c);
		RTN++;
	}
	return (RTN);
}

t_flags		print_s(t_flags flags, char *str, int len, char c)
=======
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
>>>>>>> cf035796e6e081e24719fc69361926f60606ff59
{
	int cnt;

	cnt = 0;
<<<<<<< HEAD
	if (c != '%')
		len = len >= flags.nbr2 && flags.isprec && flags.nbr2 >= 0 ?
			flags.nbr2 : len;
	if (flags.sgn == 1 && !flags.is0)
		RTN = print_space(flags, flags.nbr1 - len, ' ');
	if (flags.sgn == 1 && flags.is0)
		RTN = print_space(flags, flags.nbr1 - len, '0');
	while (cnt < len)
		ft_putchar(str[cnt++]);
	if (flags.sgn == -1)
		RTN = print_space(flags, flags.nbr1 - len, ' ');
=======
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
>>>>>>> cf035796e6e081e24719fc69361926f60606ff59
	RTN += len;
	flags = ft_reset_precision(flags);
	return (flags);
}
