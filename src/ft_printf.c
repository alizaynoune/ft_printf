/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:09:51 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/01 14:22:07 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

//void	ft_list_arg(const char *format)

int     ft_printf(const char *format, ...)
{
	int		cnt;
	int		carg;
	va_list ap;

	cnt = 0;
	carg = ft_read_format(format);
	va_start(ap, format);
	while (cnt < carg)
	{
		ft_putnbr(va_arg(ap, int));
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
		if (str[cnt] == '%' && (CNTT 'c' || CNTT 's' || CNTT 'p' || CNTT 'h' ||
					CNTT 'l' || CNTT 'L'))
			flags.carg++;
	/*	if (str[cnt] '%' && (CNTT ' ' || CNTT '	'))
		{
			if (cnt > 0 && (
	*/	cnt++;
	}

	return (flags.carg);
}
int		main()
{
//	float a = 1.8888888;    
	size_t s = 9;
	void *a = &s;
	ft_printf(" %s %s %s %s %s %s %s %s %d", 9, 2, 5, 6,10 , 221);
	printf(" |%19p|\n",a);
	return (0);
}
