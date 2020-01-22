/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:04:58 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/06 17:56:12 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data					*organize_the_flags(t_data *data,
		unsigned long long x)
{
	if (data->t[0] || (data->t[5] > data->t[6] && data->t[6] > -1
				&& data->t[7] == 1))
		data->t[2] = 0;
	if (data->t[1])
		data->t[3] = 0;
	data->t[11] = (x == 0 && data->t[5] < 2 && data->t[6] < 2 ?
			data->t[10] : data->t[10] + data->t[4]);
	if (x == 0 && data->t[6] == 0 && data->t[5] && data->t[4])
		data->t[11] = data->t[10];
	if (data->t[5] > data->t[11] && data->t[2])
		data->t[11] = data->t[5];
	if (data->t[6] >= data->t[10])
		data->t[11] = data->t[6];
	data->t[12] = (data->t[5] > data->t[11] ? data->t[5] : data->t[11]);
	return (data);
}

static char						*stock_the_number(unsigned long long int nbr)
{
	unsigned long long int	copy;
	char					*str;
	int						i;

	i = 0;
	copy = nbr;
	if (nbr == 0)
		i = 1;
	else
		while (copy != 0 && ++i)
			copy /= 8;
	if (!(str = (char *)ft_memalloc(i + 1)))
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	else
	{
		while (nbr)
		{
			str[--i] = ((nbr % 8) > 9 ? (nbr % 8) - 10 + '0' : (nbr % 8) + '0');
			nbr /= 8;
		}
	}
	return (str);
}

static unsigned long long int	look_for_length(t_data *data)
{
	if (data->t[7] == 1)
		return ((unsigned short int)va_arg(data->arg, unsigned int));
	else if (data->t[7] == 2)
		return ((unsigned char)va_arg(data->arg, unsigned int));
	else if (data->t[7] == 3)
		return (va_arg(data->arg, unsigned long int));
	else if (data->t[7] == 4)
		return (va_arg(data->arg, unsigned long long int));
	else
		return ((unsigned int)va_arg(data->arg, unsigned int));
}

t_data							*print_o(t_data *data)
{
	unsigned long long int	x;
	char					*str;

	x = look_for_length(data);
	str = stock_the_number(x);
	data->t[10] = ft_strlen(str);
	data = organize_the_flags(data, x);
	data = check_space(data, 1);
	if (!(data->t[6] == 0 && x == 0))
	{
		if (data->t[4] && ++data->len)
			write(1, "0", 1);
		data = check_space(data, 0);
		if (!(x == 0 && data->t[4] && data->t[11] == 1))
		{
			data->len += (int)ft_strlen(str);
			write(1, str, (int)ft_strlen(str));
		}
	}
	else if (data->t[6] == 0 && x == 0)
		if (!(!data->t[6] && !data->t[5] && !data->t[4]) && ++data->len)
			data->t[4] ? write(1, "0", 1) : write(1, " ", 1);
	data = check_space(data, 2);
	free(str);
	return (init(data));
}
