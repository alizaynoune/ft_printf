/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:09:51 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/02 00:10:01 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_printf(const char *format, ...)
{
	int		cnt;
	t_flags flags;
	va_list ap;

	cnt = 0;
	flags = ft_read_format(format);
	va_start(ap, format);
	while (cnt < flags.carg)
	{
		if (flags.str[cnt] == 'd' || flags.str[cnt] == 'c' || flags.str[cnt] == 's')
		ft_print_str(flags.str[cnt], (va_arg(ap, int)));
		cnt++;
	}
	va_end(ap);
	return (0);
}

t_flags     ft_read_format(const char *str)
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
	SAFE(flags.str = (char *)malloc(sizeof(char) * (flags.carg + 1)));
	flags = ft_copy_flags(flags, str);

	return (flags);
}

int		ft_check_flags(char c)
{
	if (C 'd' || C 'i' || C 'o' || C 'u' || C 'x' || C 'c' || C 's' || C 'p'||
			C 'l' || C 'L' || C 'h' || C 'f' || C '%')
		return (1);
	return (0);
}

t_flags	ft_copy_flags(t_flags flags, const char *str)
{
	int cnt;
	int	cnt1;

	cnt = 0;
	cnt1 = 0;
	while (cnt1 < flags.carg)
	{
		if (str[cnt] == '%' && (ft_check_flags(str[cnt + 1])))
			flags.str[cnt1++] = str[cnt + 1];
		cnt++;
	}
	flags.str[cnt1] = '\0';
	return (flags);
}

void	ft_print_str(char c, int typ)
{
	if (C 'd')
		ft_putnbr(typ);
	if (C 'c')
		ft_putchar((char)typ);
}
#include <stdio.h>
int		main()
{
	int a = 120;
//	float a = 1.8888888;    
//	size_t s = 9;
//	void *a = &s;
	ft_printf("%d%d%d%c%d%d%c", 9, 2, 5, 'c',a , 221, 120);
	printf("\n%d%d%d%c%d%d%c", 9, 2, 5, 'c',a , 221, 120);
	return (0);
}
