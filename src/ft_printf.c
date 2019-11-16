/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:09:51 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/16 20:54:15 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_printf(const char *format, ...)
{
	t_flags flags;
	va_list ap;

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

	flags.flg0 = "csp%";
	flags.flg1 = "diouxX";
	flags.flg2 = "f";
	flags.flg0_0 = "hl";
	flags.flgx = "#+-0123456789.";
	flags.cnt = 0;
	flags.nbret = 0;
	flags.prec = 0;
	flags.isprec = 0;
	flags.nbr1 = 0;
	flags.nbr2 = 0;
	flags.sgn = 0;
	flags.spc = 0;
	flags.is0 = 0;
	flags.hash = 0;
	return (flags);
}

t_flags		ft_print_flags(t_flags flags, char c, unsigned int flag)
{
	char *str;
	int		len;

	if (c == 'o')
		str = ft_to_octal(flag);
	if (c == 'x' || c == 'X')
		str = ft_to_hexa(flag, c);
	if (c == 'u')
		str = ft_unsigned(flag);
	len = ft_strlen(str);
	if (flags.hash && c == 'o' && flags.nbr2 <= len && str[0] != '0')
		flags.nbr2 = len + 1;
	else if (flags.hash && c == 'o' && flags.nbr2 == 0 && str[0] == '0')
		flags.nbr2++;
	flags = print_di(flags, str, ft_strlen(str), c);
	free(str);
	return (flags);
}

t_flags		ft_print_decimal(t_flags flags, char c, int flag)
{
	char *str;

	if (c == 'd' || c == 'i')
	{
		str = ft_itoa(flag);
		flags = print_di(flags, str, ft_strlen(str), c);
		free(str);
	}
	if (c == 'c')
		flags = print_c(flags, flag);

	return (flags);
}

t_flags		ft_print_ptr(t_flags flags, char c, unsigned long long int flag)
{
	char *str;
//	char *ptr;
	int		len;

	if (c == 'p' || c == 'x' || c == 'X')
		str = ft_ptr(c, flag);
	if (c == 'o')
		str = ft_long_long_octa(flag);
	if (c == 'u')
		str = ft_long_long_u(flag);
	//if (c == 'p')
	//	flags = ft_print_all(flags, str, ft_strlen(str));
	len = ft_strlen(str);
	if (flags.hash && c == 'o' && flags.nbr2 <= len && str[0] != '0')
		flags.nbr2 = len + 1;
	//if ( c != 'p')	
		flags = print_di(flags, str, len, c);
	free(str);
	return (flags);
}

t_flags		ft_print_long_long_di(t_flags flags, long long int flag)
{
	char	*str;

	str = ft_long_long_di(flag);
	flags = print_di(flags, str, ft_strlen(str), 'd');
	free(str);
	return (flags);
}

t_flags		ft_print_long_di(t_flags flags, long int flag)
{
	char	*str;

	str = ft_convert_long_di(flag);
	flags = print_di(flags, str, ft_strlen(str), 'd');
	free(str);
	return (flags);
}

t_flags		ft_print_ulong(t_flags flags, char c, unsigned long int flag)
{
	char	*str;
	int		len;

	if (c == 'x' || c == 'X')
		str = ft_convert_ulong_xX(c, flag);
	if (c == 'o')
		str = ft_cnvert_ulong_o(flag);
	if (c == 'u')
		str = ft_convert_ulong_u(flag);
	len = ft_strlen(str);
	if (flags.hash && c == 'o' && flags.nbr2 <= len && str[0] != '0')
		flags.nbr2 = len + 1;
	flags = print_di(flags, str, len, c);
	free(str);
	return (flags);
}

t_flags		ft_print_short_di(t_flags flags, short int flag)
{
	char	*str;

	str = ft_convert_short_di(flag);
	flags = print_di(flags, str, ft_strlen(str), 'd');
	free(str);
	return (flags);
}

t_flags		ft_print_ushort(t_flags flags, char c, unsigned short int flag)
{
	char	*str;
	int		len;

	if (c == 'x' || c == 'X')
		str = ft_convert_ushort_xX(c, flag);
	if (c == 'o')
		str = ft_convert_ushort_o(flag);
	if (c == 'u')
		str = ft_convert_ushort_u(flag);
	len = ft_strlen(str);
	if (flags.hash && c == 'o' && flags.nbr2 <= len && str[0] != '0')
		flags.nbr2 = len + 1;
	flags = print_di(flags, str, len, c);
	free(str);
	return (flags);
}

t_flags		ft_print_str(t_flags flags, char *str, char c)
{
	if (!str)
		str = "(null)";
	flags = print_s(flags, str, ft_strlen(str), c);
//	ft_putstr(str);
	return (flags);
}

t_flags		ft_print_uchar(t_flags flags, char c, unsigned char flag)
{
	char    *str;
	int		len;

	if (c == 'x' || c == 'X')
		str = ft_convert_uchar_xX(c, flag);
	if (c == 'o')
		str = ft_convert_uchar_o(flag);
	if (c == 'u')
		str = ft_convert_uchar_u(flag);
	len = ft_strlen(str);
	if (flags.hash && c == 'o' && flags.nbr2 <= len && str[0] != '0')
		flags.nbr2 = len + 1;
	flags = print_di(flags, str, len, c);
	free(str);
	return (flags);
}

t_flags		ft_print_schar_di(t_flags flags, signed char flag)
{
	char	*str;

	str = ft_convert_schar_di(flag);
	flags = print_di(flags, str, ft_strlen(str), 'd');
	free(str);
	return (flags);
}


#include <stdio.h>
#include <limits.h>
int		main()
{
	void *s = "%";// = "ali zaynoune";
	float a = 9.9999991;
ft_printf("%d\n", ft_printf("|%-9%|\n"));
      printf("%d\n", printf("|%-9%|\n"));
// printf("  %ld", (long)(a * 10000000000000000));
//  printf("%d", s[0]);



	return (0);
}

