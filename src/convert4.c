/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:46:03 by ybolles           #+#    #+#             */
/*   Updated: 2019/11/23 17:28:57 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_long_long_u(unsigned long long int num)
{
	unsigned long long int	num1;
	int						cnt;
	char					*str;

	num1 = num;
	cnt = 1;
	while (num1 > 9)
	{
		num1 /= 10;
		cnt++;
	}
	SAFE(str = (char *)malloc(sizeof(char) * (cnt + 1)));
	str[cnt--] = '\0';
	while (cnt >= 0)
	{
		str[cnt] = (num % 10) + '0';
		num /= 10;
		cnt--;
	}
	return (str);
}

char	*ft_long_long_di(long long int num)
{
	unsigned long long int	num1;
	int						cnt;
	char					*str;

	cnt = num > 0 ? 0 : 1;
	num1 = num < 0 ? num * -1 : num;
	while (num1 != 0)
	{
		num1 /= 10;
		cnt++;
	}
	SAFE(str = (char *)malloc(sizeof(char) * (cnt + 1)));
	str[cnt--] = '\0';
	num1 = num > 0 ? num : num * -1;
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

char	*ft_convert_uchar_xx(char c, unsigned char num)
{
	unsigned char	num1;
	char			*str;
	int				cnt;

	num1 = num;
	cnt = 1;
	while (num1 > 15)
	{
		num1 /= 16;
		cnt++;
	}
	SAFE(str = (char *)malloc(sizeof(char) * (cnt + 1)));
	str[cnt--] = '\0';
	while (cnt >= 0)
	{
		if (num % 16 > 9 && c == 'x')
			str[cnt--] = ((num % 16) % 10) + 'a';
		else if (num % 16 > 9 && c == 'X')
			str[cnt--] = ((num % 16) % 10) + 'A';
		else
			str[cnt--] = (num % 16) + '0';
		num /= 16;
	}
	return (str);
}

char	*ft_convert_uchar_o(unsigned char num)
{
	unsigned char	num1;
	char			*str;
	int				cnt;

	num1 = num;
	cnt = 1;
	while (num1 > 7)
	{
		num1 /= 8;
		cnt++;
	}
	SAFE(str = (char *)malloc(sizeof(char) * (cnt + 1)));
	str[cnt--] = '\0';
	while (cnt >= 0)
	{
		str[cnt--] = (num % 8) + '0';
		num /= 8;
	}
	return (str);
}

char	*ft_convert_schar_di(signed char num)
{
	int			num1;
	char		*str;
	int			cnt;

	num1 = (int)(num);
	cnt = num1 <= 0 ? 1 : 0;
	num1 = num1 <= 0 ? num1 * -1 : num1;
	while (num1 > 0)
	{
		num1 /= 10;
		cnt++;
	}
	SAFE(str = (char *)malloc(sizeof(char) * (cnt + 1)));
	str[cnt--] = '\0';
	num1 = (int)(num);
	num1 = num1 < 0 ? num1 * -1 : num1;
	while (cnt >= 0)
	{
		str[cnt--] = (num1 % 10) + '0';
		num1 /= 10;
	}
	num1 = (int)(num);
	if (num1 < 0)
		str[0] = '-';
	return (str);
}
