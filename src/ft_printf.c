/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:09:51 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/04 18:44:40 by alzaynou         ###   ########.fr       */
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
	flags.flg0_0 = "hlL";
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

void	ft_print_ptr(char c, unsigned long long int flag)
{
	char *str;
	char *ptr;

	if (c == 'p' || c == 'x' || c == 'X')
	{
		str = ft_ptr(c, flag);
		if (c == 'p')
		{
			ptr = str;
			str = ft_strjoin("0x", str);
			free(ptr);
		}
		ft_putstr(str);
		free(str);
	}
	if (c == 'o' || c == 'u')
	{
		if (c == 'o')
			str = ft_long_long_octa(flag);
		if (c == 'u')
			str = ft_long_long_u(flag);
		ft_putstr(str);
		free(str);
	}
}

void	ft_print_long_long_di(long long int flag)
{
	char	*str;

	str = ft_long_long_di(flag);
	ft_putstr(str);
	free(str);
}

void	ft_print_long_di(long int flag)
{
	char	*str;

	str = ft_convert_long_di(flag);
	ft_putstr(str);
	free(str);
}

void	ft_print_ulong(char c, unsigned long int flag)
{
	char	*str;

	if (c == 'x' || c == 'X' || c == 'o' || c == 'u')
	{
		if (c == 'x' || c == 'X')
			str = ft_convert_ulong_xX(c, flag);
		if (c == 'o')
			str = ft_cnvert_ulong_o(flag);
		if (c == 'u')
			str = ft_convert_ulong_u(flag);
		ft_putstr(str);
		free(str);
	}
}

void	ft_print_short_di(char c, short int flag)
{
	char	*str;

	if (c == 'd' || c == 'i')
	{
		str = ft_convert_short_di(flag);
		ft_putstr(str);
		free(str);
	}
}

void	ft_print_ushort(char c, unsigned short int flag)
{
	char	*str;

	if (c == 'x' || c == 'X')
		str = ft_convert_ushort_xX(c, flag);
	if (c == 'o')
		str = ft_convert_ushort_o(flag);
	if (c == 'u')
		str = ft_convert_ushort_u(flag);
	ft_putstr(str);
	free(str);
}

#include <stdio.h>
#include <limits.h>
int		main()
{
	void *a = "microb";
	//ft_printf("%")
	unsigned short int x = 65535;
	ft_printf("ali|%hu| %%|%p|ali|\n", x, &a);
	   printf("ali|%hu| %%|%p|ali|\n", x, &a);
	return (0);
}
