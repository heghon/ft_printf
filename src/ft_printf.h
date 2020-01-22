/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:24:50 by bmenant           #+#    #+#             */
/*   Updated: 2020/01/05 18:15:47 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/src/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_data
{
	const char		*chain;
	va_list			arg;
	int				len;
	int				i;
	int				t[14];
}					t_data;

int					ft_printf(const char *format, ...);
int					check_all(t_data *data);
t_data				*check_flags(t_data *data);
t_data				*check_length(t_data *data);
t_data				*check_precision(t_data *data);
t_data				*check_space(t_data *data, int mode);
t_data				*check_space_f(t_data *data, char *l, int mode);
t_data				*check_type(t_data *data);
t_data				*check_width(t_data *data);
long double			ft_atof(char *str);
t_data				*init(t_data *data);
char				*large_f(t_data *data, long double x);
t_data				*manage_width_star(t_data *data);
t_data				*print_bx(t_data *data);
t_data				*print_call(t_data *data);
t_data				*print_c(t_data *data);
t_data				*print_d(t_data *data);
t_data				*print_f(t_data *data);
t_data				*print_nothing(t_data *data);
t_data				*print_o(t_data *data);
t_data				*print_p(t_data *data);
t_data				*print_percent(t_data *data);
t_data				*print_s(t_data *data);
t_data				*print_u(t_data *data);
t_data				*print_x(t_data *data);
long double			round_f(t_data *data, long double x);
char				*small_f(t_data *data, long double x, char *large);

/*
**	t[0] = flag - (0 or higher)
**	t[1] = flag + (0 or 1)
**	t[2] = flag 0 (0 or 1)
**	t[3] = flag space (0 or 1)
**	t[4] = flag # (0 or 1)
**	t[5] = width (an int can fit)
**	t[6] = precision (an int can fit)
**	t[7] = length :
**	| 1 | 2 | 3 | 4 | 5 |
**	| h | hh| l | ll| L |
**	t[8] = conversion type :
**	| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
**	| c | s | p |d/i| o | u | x | X | f | %  |
**	t[9] = flag * (0 or 1)
**	t[10] = strlen
**	        for f : len before the point
**	t[11] = len = length of the number/string (only characters)
**	        for f : len after the point
**	t[12] = totlen = length total of the conversion (with spaces)
**	t[13] = sign flag (0 if no sign to print, or 1 elsewhere)
*/

#endif
