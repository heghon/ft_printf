/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:54:20 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/06 17:25:48 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				count(long double x)
{
	int ret;

	ret = 0;
	while (x && ++ret)
		x /= 10;
	return (ret);
}

long double		round_f(t_data *data, long double x)
{
	long double	tmp;
	long double precision;
	long double	copy;
	long double	cop;

	tmp = (x < 0 ? -x : x);
	precision = 1;
	copy = (data->t[6] == -1 ? 7 : data->t[6] + 1);
	while (copy--)
		precision *= 10;
	tmp *= precision;
	copy = ((unsigned long long int)tmp) % 10;
	cop = ((unsigned long long int)(tmp * 10)) % 10;
	tmp /= 10;
	if (copy > 4 && cop > 4)
		tmp += 1;
	tmp /= (precision / 10);
	return (x < 0 ? -tmp : tmp);
}
