/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:11:03 by bmenant           #+#    #+#             */
/*   Updated: 2019/04/30 12:19:31 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*check_flags(t_data *data)
{
	while (++data->i && ft_strchri("-+0 #", data->chain[data->i]) != -1)
	{
		if (data->chain[data->i] == '-')
			data->t[0] = 1;
		else if (data->chain[data->i] == '+')
			data->t[1] = 1;
		else if (data->chain[data->i] == '0')
			data->t[2] = 1;
		else if (data->chain[data->i] == ' ')
			data->t[3] = 1;
		else if (data->chain[data->i] == '#')
			data->t[4] = 1;
	}
	return (check_width(data));
}
