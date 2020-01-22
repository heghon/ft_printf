/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_width_star.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:25:46 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/07 14:13:15 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*manage_width_star(t_data *data)
{
	int		n;

	if ((!data->t[5] || !data->t[10]) && ++data->t[10])
	{
		data->t[5] = va_arg(data->arg, int);
		if (data->t[5] < 0 && data->t[0]++)
			data->t[5] = -data->t[5];
	}
	else
		n = va_arg(data->arg, int);
	return (data);
}
