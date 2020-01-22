/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:16:39 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/07 14:12:59 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*check_type(t_data *data)
{
	if (data->chain[data->i] == 'c')
		data->t[8] = 1;
	else if (data->chain[data->i] == 's')
		data->t[8] = 2;
	else if (data->chain[data->i] == 'p')
		data->t[8] = 3;
	else if (data->chain[data->i] == 'd' || data->chain[data->i] == 'i')
		data->t[8] = 4;
	else if (data->chain[data->i] == 'o')
		data->t[8] = 5;
	else if (data->chain[data->i] == 'u')
		data->t[8] = 6;
	else if (data->chain[data->i] == 'x')
		data->t[8] = 7;
	else if (data->chain[data->i] == 'X')
		data->t[8] = 8;
	else if (data->chain[data->i] == 'f')
		data->t[8] = 9;
	else if (data->chain[data->i] == '%')
		data->t[8] = 10;
	return (data);
}
