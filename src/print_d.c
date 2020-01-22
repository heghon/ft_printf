/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:04:58 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/06 17:46:39 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data			*organize_the_flags(t_data *data, long long int x)
{
	if (data->t[0] || (x == 0 && data->t[6] == 0))
		data->t[2] = 0;
	if (data->t[1])
		data->t[3] = 0;
	if (data->t[1] || data->t[3] || x < 0)
		data->t[13] = 1;
	data->t[11] = data->t[10] + data->t[13];
	if (data->t[5] > data->t[11] && data->t[2])
		data->t[11] = data->t[5];
	if (data->t[6] >= data->t[10])
		data->t[11] = data->t[6] + data->t[13];
	data->t[12] = (data->t[5] > data->t[11] ? data->t[5] : data->t[11]);
	return (data);
}

static char				*stock_the_number(long long int nbr)
{
	unsigned long long int	copy;
	char					*str;
	int						i;

	i = 0;
	copy = (nbr > 0 ? nbr : -nbr);
	if (nbr == 0)
		i = 1;
	else
		while (nbr != 0 && ++i)
			nbr /= 10;
	if (!(str = (char *)ft_memalloc(i + 1)))
		return (NULL);
	if (copy == 0)
		str[0] = '0';
	while (copy)
	{
		str[--i] = (copy % 10) + '0';
		copy /= 10;
	}
	return (str);
}

static long long int	look_for_length(t_data *data)
{
	if (data->t[7] == 1)
		return ((short int)va_arg(data->arg, int));
	else if (data->t[7] == 2)
		return ((char)va_arg(data->arg, int));
	else if (data->t[7] == 3)
		return (va_arg(data->arg, long int));
	else if (data->t[7] == 4)
		return (va_arg(data->arg, long long int));
	else
		return ((int)va_arg(data->arg, int));
}

t_data					*print_d(t_data *data)
{
	long long int	x;
	char			*str;
	char			sign;

	x = look_for_length(data);
	str = stock_the_number(x);
	data->t[10] = ft_strlen(str);
	data = organize_the_flags(data, x);
	sign = (data->t[3] ? ' ' : '+');
	sign = (x < 0 ? '-' : sign);
	data = check_space(data, 1);
	if ((x < 0 || data->t[1] || data->t[3]) && ++data->len)
		write(1, &sign, 1);
	if (!(data->t[6] == 0 && ft_atoi(str) == 0))
	{
		data = check_space(data, 0);
		data->len += (int)ft_strlen(str);
		write(1, str, (int)ft_strlen(str));
	}
	else if (data->t[6] == 0 && ft_atoi(str) == 0
			&& data->t[5] != 0 && ++data->len)
		write(1, " ", 1);
	data = check_space(data, 2);
	free(str);
	return (init(data));
}
