/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:06:55 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/02 23:02:39 by alzaynou         ###   ########.fr       */
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
	char *flg0;
	char *flg1;
	char *flg2;
}				t_flags;

# define SAFE(expr) if (!(expr)) exit (0)
int     ft_printf(const char *format, ...);
void    ft_print_flags(char c, int flag);
int         ft_read_flag(const char *format, int cnt, va_list ap, t_flags flags);
int     ft_check_flags(char c, t_flags flags);
t_flags ft_flags();

#endif
