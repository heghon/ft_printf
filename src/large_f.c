/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:17:57 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/06 17:44:50 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*loop(long double x, int s, char *str_copy)
{
	int			i;
	long double c;

	while (s--)
	{
		i = s;
		c = (x < 0 ? -x : x);
		while (i--)
			c /= 10;
		c = (int)c;
		*str_copy++ = c + '0';
		while (++i < s)
			c *= 10;
		x -= (x < 0 ? -c : c);
	}
	return (str_copy);
}

char		*large_f(t_data *data, long double x)
{
	long double	copy;
	char		*str;
	char		*str_copy;
	int			size;

	copy = (x < 0 ? -x : x);
	size = 0;
	while (copy > 1 && ++size)
		copy /= 10;
	if (size == 0)
		size++;
	if (!(str = (char *)ft_memalloc(size + 1)))
		return (NULL);
	str_copy = str;
	copy = (data->t[6] == 0 && x != 0 &&
			(ft_absolute((unsigned long long int)(x * 10)) % 10) > 5 ? 1 : 0);
	copy = (x > 0 ? copy : -copy);
	str_copy = loop(x + copy, size, str_copy);
	return (str);
}
