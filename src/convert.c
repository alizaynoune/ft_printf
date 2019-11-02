/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:42:41 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/03 00:10:39 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/ft_printf.h"

char	*ft_to_octal(int num)
{
	int		num1;
	int		cnt;
	char	*str;

	num1 = num;
	cnt = 0;
	while (num1 > 0)
	{
		num1 /= 8;
		cnt++;
	}
	SAFE(str = (char *)malloc(sizeof(char) * (cnt + 1)));
	str[cnt--] = '\0';
	while (num > 0)
	{
		str[cnt] = (num % 8) + '0';
		num /= 8;
		cnt--;
	}
	return (str);
}
