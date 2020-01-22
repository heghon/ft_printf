/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:30:13 by bmenant           #+#    #+#             */
/*   Updated: 2019/04/30 14:05:26 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*print_percent(t_data *data)
{
	int		x;

	x = 0;
	if (data->t[5] != 0 && data->t[0] == 0 && ++data->len)
	{
		while (++x < data->t[5] && data->len++)
			write(1, " ", 1);
		write(1, "%", 1);
	}
	else if (data->t[5] != 0 && data->t[0] != 0 && ++data->len)
	{
		write(1, "%", 1);
		while (++x < data->t[5] && data->len++)
			write(1, " ", 1);
	}
	else if (data->t[5] == 0 && ++data->len)
		write(1, "%", 1);
	return (init(data));
}
