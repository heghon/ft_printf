/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:13:11 by bmenant           #+#    #+#             */
/*   Updated: 2019/04/30 14:04:35 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*print_c_wint(t_data *data)
{
	wint_t	c;
	int		x;

	c = va_arg(data->arg, wint_t);
	x = 0;
	if (data->t[5] != 0 && data->t[0] == 0 && ++data->len)
	{
		while (++x < data->t[5] && data->len++)
			write(1, " ", 1);
		write(1, &c, 1);
	}
	else if (data->t[5] != 0 && data->t[0] != 0 && ++data->len)
	{
		write(1, &c, 1);
		while (++x < data->t[5] && data->len++)
			write(1, " ", 1);
	}
	else if (data->t[5] == 0 && data->len++)
		write(1, &c, 1);
	data = init(data);
	return (data);
}

t_data			*print_c(t_data *data)
{
	int		c;
	int		x;

	if (data->t[7] != 3)
	{
		c = va_arg(data->arg, int);
		x = 0;
		if (data->t[5] != 0 && data->t[0] == 0 && ++data->len)
		{
			while (++x < data->t[5] && data->len++)
				write(1, " ", 1);
			write(1, &c, 1);
		}
		else if (data->t[5] != 0 && data->t[0] != 0 && ++data->len)
		{
			write(1, &c, 1);
			while (++x < data->t[5] && data->len++)
				write(1, " ", 1);
		}
		else if (data->t[5] == 0 && ++data->len)
			write(1, &c, 1);
	}
	else
		data = print_c_wint(data);
	return (init(data));
}
