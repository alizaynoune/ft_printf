/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:09:51 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/02 23:24:11 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_printf(const char *format, ...)
{
	int		cnt;
	t_flags flags;
	va_list ap;

	cnt = 0;
	flags = ft_flags();
	va_start(ap, format);
	while (format[cnt])
	{
		if (format[cnt] == '%')
			cnt = ft_read_flag(format, cnt, ap, flags);
		else
			ft_putchar(format[cnt]);
		//	ft_print_flags(flags.str[cnt], (va_arg(ap, int)));
	//	flags.carg--;
		cnt++;
	}
	va_end(ap);
	return (0);
}

t_flags ft_flags()
{
	t_flags flags;

	flags.flg0 = "csp";
	flags.flg1 = "diouxX";
	flags.flg2 = "f";
	return (flags);
}

void	ft_print_flags(char c, int flag)
{
	if (c == 'd')
		ft_putnbr(flag);
	if (c == 'c')
		ft_putchar(flag);
}

#include <stdio.h>
int		main()
{
	char *a = "zaynoune";
//	printf("ali| %%%d  %d%d    |%c\n", 9,1, 'c');
	ft_printf("ali|%d % %d|%c  |%s|\n", 9,1, 'c', a);
	ft_printf("ali|%d % %d|%c  |%s|\n", 9,1, 'c', a);
	return (0);
}
