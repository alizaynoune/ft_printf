/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:06:55 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/01 17:47:39 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
# include "../libft/libft.h"
# include<stdarg.h>
/*
** Macros
*/
#define CNTP str[cnt + 1] ==
#define CNTN str[cnt - 1] ==
#define C c ==
#define TYP(typ)  typ > 0 ? char : int
//#define TYP int
/*
** Data stuct
*/

typedef struct s_flags
{
	int		carg;
	char	*str;
}				t_flags;

int     ft_printf(const char *format, ...);
int     ft_read_format(const char *str);
void    ft_list_arg(const char *format);
int     ft_check_flags(char c);
void    ft_print(int a, int typ);
#endif
