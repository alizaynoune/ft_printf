/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:09:51 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/03 00:26:37 by alzaynou         ###   ########.fr       */
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
	char *str;

	if (c == 'd')
		ft_putnbr(flag);
	if (c == 'c')
		ft_putchar(flag);
	if (c == 'o')
	{
		str = ft_to_octal(flag);
		ft_putstr(str);
		free(str);
	}
}

#include <stdio.h>
int		main()
{
	char *a = "zaynoune";
	int x = 0xFFFF;
	ft_printf("ali|%d %% %d|%c  |%s|%d|\n", 9,1, 'c', a, x);
	printf("ali|%d %% %d|%c  |%s|%o|%d|\n", 9, 1, 'c', a, x, x);
	return (0);
}
