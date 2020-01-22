/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:07:07 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/07 14:12:45 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_all(t_data *data)
{
	while (data->chain[++data->i])
	{
		if (data->chain[data->i] == '%')
		{
			data = check_flags(data);
			data = print_call(data);
		}
		else if (data->chain[data->i] != '%' && ++data->len)
			write(1, &data->chain[data->i], 1);
	}
	return (data->len);
}
