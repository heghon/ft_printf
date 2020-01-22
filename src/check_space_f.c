/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:18:17 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/03 17:32:10 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** modes :
** 0 : "0" printed at the beginning
** 1 : " " printed at the beginning
** 2 : " " printed at the end
*/

t_data	*check_space_f(t_data *data, char *l, int mode)
{
	int		x;
	int		y;

	y = (data->t[4] || data->t[6] ? 1 : 0);
	x = data->t[5] - data->t[10] - data->t[11] - y;
	if (!data->t[0] && !data->t[2] && x > 0 && mode == 1)
		while (x-- && ++data->len)
			write(1, " ", 1);
	else if (data->t[0] && !data->t[2] && x > 0 && mode == 2)
	{
		while (x-- && ++data->len)
			write(1, " ", 1);
	}
	else if (mode == 0)
	{
		x = data->t[12] - ft_strlen(l) - data->t[13] - data->t[11] - y;
		if (data->t[2] && data->t[5])
			while (x-- > 0 && ++data->len)
				write(1, "0", 1);
	}
	return (data);
}
