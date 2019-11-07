/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:25:26 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/07 23:45:39 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		ft_get_precision(t_flags flags, char *sflg)
{
	int	cnt;

	cnt = 0;
	flags.nbr1 = ft_atoi(sflg);
	while (sflg[cnt] && sflg[cnt] != '.')
		cnt++;
	if (sflg[cnt] == '.')
		flags.nbr2 = ft_atoi(&sflg[cnt + 1]);
	flags.sgn = flags.nbr1 < 0 ? 1 : 2;
	flags.nbr1 = flags.nbr1 < 0 ? flags.nbr1 * -1 : flags.nbr1;
	return (flags);
}
