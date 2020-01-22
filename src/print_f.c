/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:16:08 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/06 17:48:11 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data		*organize_the_flags(t_data *data, long double x)
{
	int		p;

	p = 0;
	if ((!(x == x)) || (x == (1.0 / 0.0) || x == -(1.0 / 0.0)))
	{
		data->t[6] = 0;
		p = 1;
		data->t[2] = 0;
		data->t[4] = 0;
		if (!(x == x))
			data->t[1] = 0;
	}
	if (data->t[0])
		data->t[2] = 0;
	if (data->t[1] || (x == 0 && (1 / x) < 0))
		data->t[3] = 0;
	if (data->t[6] == -1 && !p)
		data->t[6] = 6;
	data->t[13] = (data->t[1] || data->t[3] || x < 0
			|| (x == 0 && (1 / x) < 0) ? 1 : 0);
	return (data);
}

static t_data		*organize_the_lengths(t_data *data, char *l, long double x)
{
	int	y;

	if (!(x == x) || ((x == (1.0 / 0.0)) || (x == -(1.0 / 0.0))))
	{
		data->t[10] = 3;
		data->t[10] += (x == -(1.0 / 0.0) ? 1 : 0);
		data->t[11] = 0;
		data->t[12] = (data->t[5] > data->t[10] ? data->t[5] : data->t[10]);
		data->t[3] = (!(1 / x > 0) ? 0 : data->t[3]);
		data->t[1] = (!(1 / x > 0) ? 0 : data->t[1]);
		data->t[12] += (data->t[1] || data->t[3] ? 1 : 0);
		return (data);
	}
	y = (data->t[4] || data->t[6] ? 1 : 0);
	data->t[10] = ft_strlen(l) + data->t[13];
	if (data->t[5] > data->t[10] && data->t[2])
		data->t[10] = data->t[5] - data->t[6] - y;
	data->t[11] = data->t[6];
	data->t[12] = data->t[10] + y + data->t[11];
	if (data->t[5] > data->t[12])
		data->t[12] = data->t[5];
	return (data);
}

static t_data		*write_f(t_data *data, long double x, char *s, char *l)
{
	char	sign;

	sign = (data->t[3] ? ' ' : '+');
	if (x < 0 || (x == 0 && (1 / x) < 0))
		sign = '-';
	data = organize_the_lengths(data, l, x);
	data = check_space_f(data, l, 1);
	if ((data->t[1] || data->t[3] || x < 0
				|| (x == 0 && (1 / x) < 0)) && ++data->len)
		write(1, &sign, 1);
	data = check_space_f(data, l, 0);
	data->len += ft_strlen(l);
	write(1, l, ft_strlen(l));
	if ((data->t[4] || data->t[6] > 0) && ++data->len)
		write(1, ".", 1);
	data->len += ft_strlen(s);
	write(1, s, ft_strlen(s));
	data = check_space_f(data, l, 2);
	return (data);
}

static void			free_everything(char *large, char *small, long double x)
{
	if (!(!(x == x) || ((x == (1.0 / 0.0)) || (x == -(1.0 / 0.0)))))
	{
		free(large);
		free(small);
	}
	return ;
}

t_data				*print_f(t_data *data)
{
	long double	x;
	char		*large;
	char		*small;

	x = (data->t[7] == 5 ? va_arg(data->arg, long double) :
			va_arg(data->arg, double));
	data = organize_the_flags(data, x);
	if (!(!(x == x) || ((x == (1.0 / 0.0)) || (x == -(1.0 / 0.0)))))
	{
		x = round_f(data, x);
		large = large_f(data, x);
		small = small_f(data, x, large);
		data = write_f(data, x, small, large);
		free_everything(large, small, x);
	}
	else
	{
		large = ((x == 1.0 / 0.0 || x == -(1.0 / 0.0)) ? "inf" : "nan");
		small = "";
		data = write_f(data, x, small, large);
	}
	return (init(data));
}
