/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:32:12 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/06 18:06:38 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*small_f(t_data *data, long double x, char *large)
{
	char		*str;
	int			i;
	long double	j;

	i = 0;
	x = (x < 0 ? -x : x);
	j = 0;
	while (*large)
	{
		j *= 10;
		j += (long double)(*large - '0');
		large++;
	}
	x -= j;
	j = (data->t[6] == -1 ? 6 : data->t[6]);
	if (!(str = (char *)ft_memalloc(j + 1)))
		return (NULL);
	while (i < j)
	{
		x *= 10;
		str[i++] = (x > 0 ? (int)x + '0' : '0');
		x -= (int)x;
	}
	return (str);
}
