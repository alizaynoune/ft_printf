/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:06:55 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/01 12:02:47 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
# include "../libft/libft.h"
# include<stdarg.h>
#define CNTT str[cnt + 1] ==

typedef struct s_flags
{
	int		carg;
	char	*arg;
}				t_flags;

int     ft_printf(const char *format, ...);
int     ft_read_format(const char *str);
void    ft_list_arg(const char *format);
#endif
