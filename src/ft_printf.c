/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:09:51 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/03 19:13:52 by alzaynou         ###   ########.fr       */
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
//	flags.flg1_0 = "hl";
	return (flags);
}

void	ft_print_flags(char c, unsigned int flag)
{
	char *str;

	if (c == 'o' || c == 'x' || c == 'X' || c == 'u')
	{
		if (c == 'o')
			str = ft_to_octal(flag);
		if (c == 'x' || c == 'X')
			str = ft_to_hexa(flag, c);
		if (c == 'u')
			str = ft_unsigned(flag);
		ft_putstr(str);
		free(str);
	}
}

void	ft_print_decimal(char c, int flag)
{
	char *str;

	if (c == 'd' || c == 'i')
	{
		str = ft_decimal(flag);
		ft_putstr(str);
		free(str);
	}
	if (c == 'c')
		ft_putchar(flag);
}

#include <stdio.h>
#include <limits.h>
int		main()
{
//	void *a = "ali";
	//ft_printf("%")
	int x =  INT_MIN;
	ft_printf("ali|%d|%i|%o|%u|%x|%X|%s|%c|%%|\n", x, x, x*2, x*2, x*2, x*2, "ali", x*2);
	   printf("ali|%d|%i|%o|%u|%x|%X|%s|%c|%%|\n", x, x, x*2, x*2, x*2, x*2, "ali", x*2);
	return (0);
}
