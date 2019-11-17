/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:36:31 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/17 20:48:52 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		ft_print_has_x(t_flags flags, char c)
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
{
	int cnt;

	cnt = 0;
	if (c != '%')
		len = len >= flags.nbr2 && flags.isprec && flags.nbr2 >= 0
			? flags.nbr2 : len;
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

t_flags		print_c(t_flags flags, char c)
{
	if (!flags.sgn)
		RTN = print_space(flags, flags.nbr1 - 1, ' ');
	ft_putchar(c);
	if (flags.sgn)
		RTN = print_space(flags, flags.nbr1 - 1, ' ');
	RTN++;
	return (flags);
}
