/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:25:26 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/15 18:54:44 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags     ft_read_prec(const char *format, t_flags flags)
{
	int     cnt;
	char    *sflg;

	cnt = CNT;
	while (ft_strchr(flags.flgx, FORM1))
		CNT++;
	if (ft_strchr(flags.flg1, FORM1) || ft_strchr(flags.flg0, FORM1) ||
			ft_many_flags(format, flags))
	{
		SAFE(sflg = (char *)malloc(sizeof(char) * ((CNT - cnt) + 1)));
		sflg[CNT - cnt] = '\0';
		CNT = cnt;
		while (ft_strchr(flags.flgx, FORM1))
			sflg[(CNT++) - cnt] = FORM1;
		if (ft_strchr(flags.flg1, FORM1) || ft_strchr(flags.flg0, FORM1))
		flags = ft_get_precision(flags, sflg, FORM1);
		else if (ft_many_flags(format, flags) == 1)
			flags = ft_get_precision(flags, sflg, FORM2);
		else if (ft_many_flags(format, flags) == 2)
			flags = ft_get_precision(flags, sflg, FORM3);
	}
	else
		CNT = cnt;
	return (flags);
}


t_flags		ft_get_precision(t_flags flags, char *sflg, char c)
{
	if (c == 's')
		flags = ft_get_precision_s(flags, sflg);
	else if (ft_strchr(flags.flg1, c))
		flags = ft_get_prec_di(flags, sflg);
	else if (c == 'c')
		flags = ft_get_prec_c(flags, sflg);
	return (flags);
}

t_flags     ft_get_precision_s(t_flags flags, char *sflg)
{
	int	cnt;

	cnt = 0;
	flags.nbr2 = -1;
	flags.nbr1 = ft_atoi(sflg);
	while (sflg[cnt] && sflg[cnt] != '.')
		cnt++;
	if (sflg[cnt] == '.')
		flags.nbr2 = ft_atoi(&sflg[cnt + 1]);
	flags.sgn = flags.nbr1 < 0 ? -1 : 1;
	flags.nbr1 = flags.nbr1 < 0 ? flags.nbr1 * -1 : flags.nbr1;
	free(sflg);
	flags.isprec = 1;
	return (flags);
}

char		*ft_get_hash(char *str)
{
	char 	*nstr;
	int		cnt;
	int		cnt1;

	cnt = ft_strlen(str);
	cnt1 = 0;
	SAFE(nstr = (char *)malloc(sizeof(char) * (cnt)));
	cnt = 0;
	while (str[cnt])
	{
		if (str[cnt] != '#')
			nstr[cnt1++] = str[cnt];
		cnt++;
	}
	nstr[cnt1] = '\0';
	free(str);
	return (nstr);
}

t_flags		ft_get_prec_di(t_flags flags, char *sflg)
{
	int cnt;

	cnt = 0;
	if (ft_strchr(sflg, '#'))
	{
		sflg = ft_get_hash(sflg);
		flags.hash = 1;
	}
	if (!ft_strchr(sflg, '.') && !ft_strchr(sflg, '-'))
	{
		while (sflg[cnt] && !ft_isdigit(sflg[cnt]))
			cnt++;
		flags.is0 = sflg[cnt] == '0' ? 1 : 0;
		cnt = 0;
	}
	if (!ft_strchr(sflg, '.') && !ft_strchr(sflg, '-') && flags.is0)
	{
		while (sflg[cnt] && (!ft_isdigit(sflg[cnt]) || sflg[cnt] == '0'))
			cnt++;
		flags.nbr2 = ft_atoi(&sflg[cnt]);
		flags.nbr1 = 0;
	}
	else
	{
		if (ft_strchr(sflg, '.') && sflg[0] != '.')
		{
			while (sflg[cnt] && ((!ft_isdigit(sflg[cnt]) && sflg[cnt] != '.') ||
						sflg[cnt] == '-' || sflg[cnt] == '+' || sflg[cnt] == '0'))
				cnt++;
			flags.nbr1 = ft_atoi(&sflg[cnt]);
			while (sflg[cnt] && sflg[cnt] != '.')
				cnt++;
			flags.nbr2 = ft_atoi(&sflg[cnt + 1]);
		}
		else if (ft_strchr(sflg, '.') && sflg[0] == '.')
			flags.nbr2 = ft_atoi(&sflg[cnt + 1]);
		else
		{
			while (sflg[cnt] && (sflg[cnt] == '-' || sflg[cnt] == '+' || sflg[cnt] == '0'))
				cnt++;
			flags.nbr1 = ft_atoi(&sflg[cnt]);
			flags.isnb2 = 1;
		}
	}
	flags.prec = ft_strchr(sflg, '+') ? 1 : 0;
	flags.sgn = ft_strchr(sflg, '-') ? 1 : 0;
	flags.is0 = flags.sgn ? 0 : flags.is0;
	free(sflg);
	flags.isprec = 1;
	return (flags);
}

t_flags		ft_reset_precision(t_flags flags)
{
	flags.nbr1 = 0;
	flags.nbr2 = 0;
	flags.sgn = 0;
	flags.spc = 0;
	flags.is0 = 0;
	flags.isprec = 0;
	flags.prec = 0;
	flags.isnb2 = 0;
	flags.hash = 0;
	return (flags);
}
