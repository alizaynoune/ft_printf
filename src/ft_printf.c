/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:09:51 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/05 19:09:16 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_printf(const char *format, ...)
{
	//int		cnt;
	t_flags flags;
	va_list ap;

	//cnt = 0;
	flags = ft_flags();
	va_start(ap, format);
	while (format[CNT])
	{
		if (format[CNT] == '%')
			flags = ft_read_flag(format, ap, flags);
		else
		{
			ft_putchar(format[CNT]);
			RTN++;
		}
		CNT++;
	}
	va_end(ap);
	return (RTN);
}

t_flags ft_flags()
{
	t_flags flags;

	flags.flg0 = "csp";
	flags.flg1 = "diouxX";
	flags.flg2 = "f";
	flags.flg0_0 = "hlL";
	flags.flgx = "#+-";
	flags.cnt = 0;
	flags.nbret = 0;
	return (flags);
}

int		ft_print_flags(char c, unsigned int flag)
{
	char *str;
	int  rtn;

		if (c == 'o')
			str = ft_to_octal(flag);
		if (c == 'x' || c == 'X')
			str = ft_to_hexa(flag, c);
		if (c == 'u')
			str = ft_unsigned(flag);
		rtn = ft_strlen(str);
		ft_putstr(str);
		free(str);
	return (rtn);
}

int		ft_print_decimal(char c, int flag)
{
	char *str;
	int  rtn;

	rtn = 0;
	if (c == 'd' || c == 'i')
	{
		str = ft_decimal(flag);
		rtn = ft_strlen(str);
		ft_putstr(str);
		free(str);
	}
	if (c == 'c')
	{
		ft_putchar(flag);
		rtn++;
	}
	return (rtn);
}

int		ft_print_ptr(char c, unsigned long long int flag)
{
	char *str;
	char *ptr;
	int	 rtn;

	if (c == 'p' || c == 'x' || c == 'X')
	{
		str = ft_ptr(c, flag);
		if (c == 'p')
		{
			ptr = str;
			str = ft_strjoin("0x", str);
			free(ptr);
		}
	}
		if (c == 'o')
			str = ft_long_long_octa(flag);
		if (c == 'u')
			str = ft_long_long_u(flag);
		rtn = ft_strlen(str);
		ft_putstr(str);
		free(str);
	return (rtn);
}

int		ft_print_long_long_di(long long int flag)
{
	char	*str;
	int		rtn;

	str = ft_long_long_di(flag);
	rtn = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (rtn);
}

int		ft_print_long_di(long int flag)
{
	char	*str;
	int		rtn;

	str = ft_convert_long_di(flag);
	rtn = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (rtn);
}

int		ft_print_ulong(char c, unsigned long int flag)
{
	char	*str;
	int		rtn;

		if (c == 'x' || c == 'X')
			str = ft_convert_ulong_xX(c, flag);
		if (c == 'o')
			str = ft_cnvert_ulong_o(flag);
		if (c == 'u')
			str = ft_convert_ulong_u(flag);
		rtn = ft_strlen(str);
		ft_putstr(str);
		free(str);
	return (rtn);
}

int		ft_print_short_di(short int flag)
{
	char	*str;
	int		rtn;

	str = ft_convert_short_di(flag);
	rtn = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (rtn);
}

int		ft_print_ushort(char c, unsigned short int flag)
{
	char	*str;
	int		rtn;

	if (c == 'x' || c == 'X')
		str = ft_convert_ushort_xX(c, flag);
	if (c == 'o')
		str = ft_convert_ushort_o(flag);
	if (c == 'u')
		str = ft_convert_ushort_u(flag);
	rtn = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (rtn);
}

int		ft_print_str(char *str)
{
	int rtn;

	rtn = ft_strlen(str);
	ft_putstr(str);
	return (rtn);
}

int		ft_print_uchar(char c, unsigned char flag)
{
	char    *str;
	int		rtn;

	if (c == 'x' || c == 'X')
		str = ft_convert_uchar_xX(c, flag);
	if (c == 'o')
		str = ft_convert_uchar_o(flag);
	if (c == 'u')
		str = ft_convert_uchar_u(flag);
	rtn = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (rtn);
}

int		ft_print_schar_di(signed char flag)
{
	char	*str;
	int		rtn;

	str = ft_convert_schar_di(flag);
	rtn = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (rtn);
}

#include <stdio.h>
#include <limits.h>
int		main()
{
	char *a = "microbklsfjgklfa;dfk'skf';lf';lds'lfd'lds;'l'fd;";
	//ft_printf("%")
	unsigned short int x = 65535;
	unsigned char i = 255;
	ft_printf("%d\n", ft_printf("ali|%d | %%|%p|%s|ali|%hhX|\n", x, &a, a, i));
	   printf("%d\n",    printf("ali|%d | %%|%p|%s|ali|%hhX|\n", x, &a, a, i));
	return (0);
}
