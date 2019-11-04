/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:06:01 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/04 17:39:49 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_convert_short_di(short int num)
{
	unsigned short int	num1;
	char				*str;
	int					cnt;

	num1 = num < 0 ? num * - 1 : num;
	cnt = num <= 0 ? 1 : 0;
	while (num1 > 0)
	{
		num1 /= 10;
		cnt++;
	}
	SAFE(str = (char *)malloc(sizeof(char) * (cnt + 1)));
	str[cnt--] = '\0';
	num1 = num < 0 ? num * - 1 : num;
	while (cnt >= 0)
	{
		str[cnt] = (num1 % 10) + '0';
		num1 /= 10;
		cnt--;
	}
	if (num < 0)
		str[0] = '-';
	return (str);
}

/*char	*ft_convert_ushort_xX(char c, unsigned short int num)
{
	unsigned short int	num1;
	char				*str;
	int					cnt;

	num1 = 
}*/
