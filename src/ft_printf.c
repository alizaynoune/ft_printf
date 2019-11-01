/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:09:51 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/01 18:35:45 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
		ft_print_str(typ, (va_arg(ap, int)));
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
	SAFE(flags.str = (char *)malloc(sizeof(char) * (flags.carg + 1)));
	ft_copy_flags(flags, str);

	return (flags.carg);
}

int		ft_check_flags(char c)
{
	if (C 'd' || C 'i' || C 'o' || C 'u' || C 'x' || C 'c' || C 's' || C 'p'||
			C 'l' || C 'L' || C 'h' || C 'f' || C '%')
		return (1);
	return (0);
}

void	ft_copy_flags(t_flags flags, const char *str)
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
	ft_putstr(flags.str);
	ft_putchar('\n');
}

void	ft_print_str(int a, int typ)
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
	ft_printf(" %s %d %s %s %s %s", 9, 2, 5, 6,10 , 221);
//	printf("");
	return (0);
}
