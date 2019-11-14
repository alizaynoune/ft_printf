/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:36:31 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/14 22:23:24 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

t_flags     print_s(t_flags flags, char *str, int len)
{
	int cnt;

	cnt = 0;
	len = len >= flags.nbr2 && flags.isprec && flags.nbr2 >= 0 ? flags.nbr2 : len;
	if (flags.sgn == 1)
		RTN = print_space(flags, flags.nbr1 - len, ' ');
	while (cnt < len)
		ft_putchar(str[cnt++]);
	if (flags.sgn == -1)
		RTN = print_space(flags, flags.nbr1 - len, ' ');
	RTN += len;
	flags = ft_reset_precision(flags);
	return (flags);
}

t_flags		print_di(t_flags flags, char *str, int len)
{
	int cnt;

	cnt = 0;
/*
		ft_putchar('"');
		ft_putnbr(flags.nbr1);
		ft_putchar('.');
		ft_putnbr(flags.nbr2);
		ft_putchar('"');
		ft_putnbr(flags.is0);
		ft_putchar('"');
		ft_putnbr(flags.sgn);
		ft_putchar('"');
		ft_putnbr(flags.prec);*/
		//ft_putnbr(flags.is0);
	if (flags.isprec)
	{
		flags.spc = flags.prec || str[0] == '-' ? 0 : flags.spc;
		//if (flags.sgn)
			RTN = print_space(flags, flags.spc , ' ');
		flags.prec = str[0] == '-' ? 0 : flags.prec;
		if (str[0] == '-' && !flags.is0)
			cnt++;
		if (flags.is0)
			flags.nbr2 = flags.spc || flags.prec ? flags.nbr2 - 1 : flags.nbr2;
		flags.nbr1 = flags.spc || flags.prec ? flags.nbr1 - 1 : flags.nbr1;
		if (str[0] == '0' && !flags.is0 && !flags.nbr2 && !flags.isnb2)
			len--;
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
		ft_putstr(str);
	}
	RTN += len;
	flags = ft_reset_precision(flags);
	return (flags);
}
