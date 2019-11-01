/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:09:51 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/01 17:52:29 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int     ft_printf(const char *format, ...)
{
	int		cnt;
	int		carg;
	int		typ = 0;
	va_list ap;

	cnt = 0;
	carg = ft_read_format(format);
	va_start(ap, format);
	while (cnt < carg)
	{
		ft_print(typ, (va_arg(ap, int)));
		ft_putchar('\n');
		cnt++;
	}
	va_end(ap);
	return (0);
}

int     ft_read_format(const char *str)
{
	int		cnt;
	t_flags flags;

	cnt = 0;
	flags.carg = 0;

	while (str[cnt])
	{
		if (str[cnt] == '%' && (ft_check_flags(str[cnt + 1])))
			flags.carg++;
		cnt++;
	}

	return (flags.carg);
}

int		ft_check_flags(char c)
{
	if (C 'd' || C 'i' || C 'o' || C 'u' || C 'x' || C 'c' || C 's' || C 'p'||
			C 'l' || C 'L' || C 'h' || C 'f' || C '%')
		return (1);
	return (0);
}

void	ft_print(int a, int typ)
{
	if (a == 0)
		ft_putnbr(typ);
	if (a == 1)
		ft_putchar(typ);
}
int		main()
{
//	float a = 1.8888888;    
//	size_t s = 9;
//	void *a = &s;
	ft_printf(" %s %s %s %s %s %s", 9, 2, 5, 6,10 , 221);
//	printf("");
	return (0);
}
