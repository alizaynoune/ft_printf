/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:09:51 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/08 00:19:04 by alzaynou         ###   ########.fr       */
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
	flags.flgx = "#+-0123456789.";
	flags.cnt = 0;
	flags.nbret = 0;
	flags.prec = 0;
	flags.chr = ' ';
	flags.nbr1 = 0;
	flags.nbr2 = -1;
	flags.sgn = 0;
	flags.isnl = 0;
	return (flags);
}

t_flags		ft_print_flags(t_flags flags, char c, unsigned int flag)
{
	char *str;

	if (c == 'o')
		str = ft_to_octal(flag);
	if (c == 'x' || c == 'X')
		str = ft_to_hexa(flag, c);
	if (c == 'u')
		str = ft_unsigned(flag);
	flags = ft_print_all(flags, str, ft_strlen(str));
	free(str);
	return (flags);
}

t_flags		ft_print_decimal(t_flags flags, char c, int flag)
{
	char *str;

	if (c == 'd' || c == 'i')
	{
		str = ft_decimal(flag);
		flags = ft_print_all(flags, str, ft_strlen(str));
		free(str);
	}
	if (c == 'c')
	{
		SAFE(str = (char *)malloc(sizeof(char) * 2));
		str[0] = flag;
		str[1] = '\0';
		flags = ft_print_all(flags, str, ft_strlen(str));
		free (str);

	}
	return (flags);
}

t_flags		ft_print_ptr(t_flags flags, char c, unsigned long long int flag)
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
	}
	if (c == 'o')
		str = ft_long_long_octa(flag);
	if (c == 'u')
		str = ft_long_long_u(flag);
	flags = ft_print_all(flags, str, ft_strlen(str));
	free(str);
	return (flags);
}

t_flags		ft_print_long_long_di(t_flags flags, long long int flag)
{
	char	*str;

	str = ft_long_long_di(flag);
	flags = ft_print_all(flags, str, ft_strlen(str));
	free(str);
	return (flags);
}

t_flags		ft_print_long_di(t_flags flags, long int flag)
{
	char	*str;

	str = ft_convert_long_di(flag);
	flags = ft_print_all(flags, str, ft_strlen(str));
	free(str);
	return (flags);
}

t_flags		ft_print_ulong(t_flags flags, char c, unsigned long int flag)
{
	char	*str;

	if (c == 'x' || c == 'X')
		str = ft_convert_ulong_xX(c, flag);
	if (c == 'o')
		str = ft_cnvert_ulong_o(flag);
	if (c == 'u')
		str = ft_convert_ulong_u(flag);
	flags = ft_print_all(flags, str, ft_strlen(str));
	free(str);
	return (flags);
}

t_flags		ft_print_short_di(t_flags flags, short int flag)
{
	char	*str;

	str = ft_convert_short_di(flag);
	flags = ft_print_all(flags, str, ft_strlen(str));
	free(str);
	return (flags);
}

t_flags		ft_print_ushort(t_flags flags, char c, unsigned short int flag)
{
	char	*str;

	if (c == 'x' || c == 'X')
		str = ft_convert_ushort_xX(c, flag);
	if (c == 'o')
		str = ft_convert_ushort_o(flag);
	if (c == 'u')
		str = ft_convert_ushort_u(flag);
	flags = ft_print_all(flags, str, ft_strlen(str));
	free(str);
	return (flags);
}

t_flags		ft_print_str(t_flags flags, char *str)
{
	if (!str)
	{
		str = "(null)";
		flags.isnl = 1;
	}
	flags = print_s(flags, str, ft_strlen(str));
	return (flags);
}

t_flags		ft_print_uchar(t_flags flags, char c, unsigned char flag)
{
	char    *str;

	if (c == 'x' || c == 'X')
		str = ft_convert_uchar_xX(c, flag);
	if (c == 'o')
		str = ft_convert_uchar_o(flag);
	if (c == 'u')
		str = ft_convert_uchar_u(flag);
	flags = ft_print_all(flags, str, ft_strlen(str));
	free(str);
	return (flags);
}

t_flags		ft_print_schar_di(t_flags flags, signed char flag)
{
	char	*str;

	str = ft_convert_schar_di(flag);
	flags = ft_print_all(flags, str, ft_strlen(str));
	free(str);
	return (flags);
}
/*
#include <stdio.h>
#include <limits.h>
int		main()
  {
	  static char *s = "hi low\0don't print me lol\0";
ft_printf("%d\n", ft_printf("|%-12.2s|\n", NULL));
   printf("%d\n",    printf("|%-12.2s|\n", NULL));


return (0);
}*/
