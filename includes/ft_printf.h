/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:06:55 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/04 18:42:12 by alzaynou         ###   ########.fr       */
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
	char *flg0_0;
}				t_flags;

# define SAFE(expr) if (!(expr)) exit (0)
int     ft_printf(const char *format, ...);
void    ft_print_flags(char c, unsigned int flag);
int         ft_read_flag(const char *format, int cnt, va_list ap, t_flags flags);
int     ft_check_flags(char c, t_flags flags);
t_flags ft_flags();
char    *ft_to_octal(unsigned int num);
char    *ft_to_hexa(unsigned int num, char c);
char    *ft_unsigned(unsigned int num);
char    *ft_decimal(int num);
void    ft_print_decimal(char c, int flag);
char	*ft_ptr(char c,unsigned long long int num);
void	ft_print_ptr(char c, unsigned long long int flag);
int      ft_check_flags2(const char *format, int cnt, va_list ap, t_flags flags);
char    *ft_long_long_octa(unsigned long long int num);
char    *ft_long_long_u(unsigned long long int num);
void    ft_print_long_long_di(long long int flag);
char    *ft_long_long_di(long long int num);
char    *ft_convert_long_di(long int num);
void    ft_print_long_di(long int flag);
char    *ft_convert_ulong_xX(char c, unsigned long int num);
void    ft_print_ulong(char c, unsigned long int flag);
char    *ft_cnvert_ulong_o(unsigned long int num);
char    *ft_convert_ulong_u(unsigned long int num);
void    ft_print_short_di(char c, short int flag);
char    *ft_convert_short_di(short int num);
void    ft_print_ushort(char c, unsigned short int flag);
char    *ft_convert_ushort_xX(char c, unsigned short int num);
char    *ft_convert_ushort_o(unsigned short int num);
char    *ft_convert_ushort_u(unsigned short int num);

#endif
