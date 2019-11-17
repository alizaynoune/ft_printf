/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 23:00:17 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/17 20:22:48 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags			ft_get_prec_c(t_flags flags, char *sflg)
{
	int cnt;

	cnt = 0;
	flags.sgn = ft_strchr(sflg, '-') ? 1 : 0;
	while (sflg[cnt] && !ft_isdigit(sflg[cnt]))
		cnt++;
	flags.nbr1 = ft_atoi(&sflg[cnt]);
	free(sflg);
	return (flags);
}

t_flags			prec_di(t_flags flags, int cnt, char *sflg)
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
		while (sflg[cnt] && (sflg[cnt] == '-' || sflg[cnt] == '+'
					|| sflg[cnt] == '0'))
			cnt++;
		flags.nbr1 = ft_atoi(&sflg[cnt]);
		flags.isnb2 = 1;
	}
	return (flags);
}

t_flags			prec_di2(t_flags flags, int cnt, char *sflg)
{
	if (!ft_strchr(sflg, '.') && !ft_strchr(sflg, '-') && flags.is0)
	{
		while (sflg[cnt] && (!ft_isdigit(sflg[cnt]) || sflg[cnt] == '0'))
			cnt++;
		flags.nbr2 = ft_atoi(&sflg[cnt]);
		flags.nbr1 = 0;
	}
	else
	{
		flags = prec_di(flags, cnt, sflg);
	}
	return (flags);
}

t_flags			ft_get_prec_di(t_flags flags, char *sflg)
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
	flags = prec_di2(flags, cnt, sflg);
	flags.prec = ft_strchr(sflg, '+') ? 1 : 0;
	flags.sgn = ft_strchr(sflg, '-') ? 1 : 0;
	flags.is0 = flags.sgn ? 0 : flags.is0;
	free(sflg);
	flags.isprec = 1;
	return (flags);
}
