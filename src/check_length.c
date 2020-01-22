/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:08:37 by bmenant           #+#    #+#             */
/*   Updated: 2019/04/30 11:34:54 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*check_length(t_data *data)
{
	if (data->chain[data->i] == 'h' && ++data->i)
	{
		if (data->chain[data->i] == 'h' && data->i++)
			data->t[7] = 2;
		else
			data->t[7] = 1;
	}
	else if (data->chain[data->i] == 'l' && ++data->i)
	{
		if (data->chain[data->i] == 'l' && data->i++)
			data->t[7] = 4;
		else
			data->t[7] = 3;
	}
	else if (data->chain[data->i] == 'L' && ++data->i)
		data->t[7] = 5;
	return (check_type(data));
}
