/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:14:28 by bmenant           #+#    #+#             */
/*   Updated: 2019/04/30 14:03:37 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*init(t_data *data)
{
	data->t[0] = 0;
	data->t[1] = 0;
	data->t[2] = 0;
	data->t[3] = 0;
	data->t[4] = 0;
	data->t[5] = 0;
	data->t[6] = -1;
	data->t[7] = 0;
	data->t[8] = 0;
	data->t[9] = 0;
	data->t[10] = 0;
	data->t[11] = 0;
	data->t[12] = 0;
	data->t[13] = 0;
	return (data);
}
