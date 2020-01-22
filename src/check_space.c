/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:14:55 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/06 17:43:39 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** modes :
** 0 : "0" printed at the beginning
** 1 : " " printed at the beginning
** 2 : " " printed at the end
*/

static int		diese_o(t_data *data)
{
	if (data->t[8] == 5 && data->t[4])
		return (1);
	return (0);
}

static int		diese(t_data *data)
{
	if ((data->t[8] == 7 || data->t[8] == 8) && data->t[4])
		return (2);
	else if (data->t[8] == 5 && data->t[4])
		return (1);
	else
		return (0);
}

t_data			*check_space(t_data *data, int mode)
{
	int		x;
	int		y;

	x = data->t[12] - data->t[11];
	if (!data->t[0] && x > 0 && mode == 1)
		while (x-- && ++data->len)
			write(1, " ", 1);
	else if (data->t[0] && x > 0 && mode == 2)
		while (x-- && ++data->len)
			write(1, " ", 1);
	else if (mode == 0)
	{
		x = data->t[6] - data->t[10] - diese_o(data);
		y = data->t[11] - data->t[10] - data->t[13] - diese(data);
		if (x > 0)
			while (x-- && ++data->len)
				write(1, "0", 1);
		else if (data->t[2] && y > 0)
		{
			while (y-- && ++data->len)
				write(1, "0", 1);
		}
	}
	return (data);
}
