/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:06:55 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/17 22:00:29 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
# include "../libft/libft.h"
# include<stdarg.h>
/*
** Macros
*/
#define CNT flags.cnt
#define RTN flags.nbret
#define FORM0 format[flags.cnt]
#define FORM1 format[flags.cnt + 1]
#define FORM2 format[flags.cnt + 2]
#define FORM3 format[flags.cnt + 3]
#define TYP(typ)  typ > 0 ? char : int
//#define TYP int
/*
** Data stuct
*/

typedef struct s_flags
{
	char	*flg0;
	char	*flg1;
	char	*flg2;
	char	*flg0_0;
	char	*flgx;
	int		cnt;
	int		nbret;
	int		prec;
	int		isprec;
	int		sgn;
	int		nbr1;
	int		nbr2;
	int		spc;
	int		is0;
	int		isnb2;
	int		hash;
	char	*str;
}				t_flags;

# define SAFE(expr) if (!(expr)) exit (0)
int     ft_printf(const char *format, ...);
t_flags    ft_print_flags(t_flags flags, char c, unsigned int flag);
t_flags   ft_read_flag(const char *format, va_list ap, t_flags flags);
int     ft_check_flags(char c, t_flags flags);
t_flags ft_flags();
char    *ft_to_octal(unsigned int num);
char    *ft_to_hexa(unsigned int num, char c);
char    *ft_unsigned(unsigned int num);
t_flags ft_print_decimal(t_flags flags, char c, int flag);
char	*ft_ptr(char c,unsigned long long int num);
t_flags	ft_print_ptr(t_flags flags, char c, unsigned long long int flag);
t_flags      ft_check_flags2(const char *format, va_list ap, t_flags flags);
char    *ft_long_long_octa(unsigned long long int num);
char    *ft_long_long_u(unsigned long long int num);
t_flags ft_print_long_long_di(t_flags flags, long long int flag);
char    *ft_long_long_di(long long int num);
char    *ft_convert_long_di(long int num);
t_flags ft_print_long_di(t_flags flags, long int flag);
char    *ft_convert_ulong_x(char c, unsigned long int num);
t_flags ft_print_ulong(t_flags flags, char c, unsigned long int flag);
char    *ft_cnvert_ulong_o(unsigned long int num);
char    *ft_convert_ulong_u(unsigned long int num);
t_flags ft_print_short_di(t_flags flags, short int flag);
char    *ft_convert_short_di(short int num);
t_flags ft_print_ushort(t_flags flags, char c, unsigned short int flag);
char    *ft_convert_ushort_x(char c, unsigned short int num);
char    *ft_convert_ushort_o(unsigned short int num);
char    *ft_convert_ushort_u(unsigned short int num);
t_flags     ft_print_str(t_flags flags, char *str, char c);
t_flags     ft_print_uchar(t_flags flags, char c, unsigned char flag);
t_flags     ft_print_schar_di(t_flags flags, signed char flag);
char    *ft_convert_uchar_u(unsigned char num);
char    *ft_convert_uchar_x(char c, unsigned char num);
char    *ft_convert_uchar_o(unsigned char num);
char    *ft_convert_schar_di(signed char num);
t_flags     ft_read_prec(const char *format, t_flags flags);
t_flags     ft_get_precision(t_flags flags, char *sflg, char c);
t_flags     print_s(t_flags flags, char *str, int len, char c);
void		print_pace(t_flags flags, int len);
t_flags     ft_reset_precision(t_flags flags);
t_flags     ft_get_precision_s(t_flags flags, char *sflg, char c);
t_flags     ft_get_prec_di(t_flags flags, char *sflg);
t_flags     print_di(t_flags flags, char *str, int len, char c);
t_flags         ft_skip_space(const char *format, t_flags flags);
int        print_space(t_flags flags, int len, char c);
int             ft_many_flags(const char *format, t_flags flags);
long long int   ft_atoi_llint(char *str);
t_flags     ft_get_prec_c(t_flags flags, char *sflg);
t_flags     print_c(t_flags flags, char c);
char        *ft_get_hash(char *str);
t_flags     ft_print_has_x(t_flags flags, char c);

#endif
