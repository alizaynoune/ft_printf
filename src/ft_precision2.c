/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 23:00:17 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/14 23:24:47 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		ft_get_prec_c(t_flags flags, char *sflg)
{
	int cnt;

	cnt = 0;
	flags.sgn = ft_strchr(sflg, '-') ? 1 : 0;
	while (sflg[cnt] && !ft_isdigit(sflg[cnt]))
		cnt++;
	flags.nbr1 = ft_atoi(&sflg[cnt]);
	free(sflg);
	return(flags);
}
