/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:10:18 by bmenant           #+#    #+#             */
/*   Updated: 2019/04/30 11:35:54 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*check_width(t_data *data)
{
	char	*w;
	int		j;

	if (data->chain[data->i] == '*' && ++data->i && ++data->t[9])
		data = manage_width_star(data);
	if (data->chain[data->i] >= '0' && data->chain[data->i] <= '9')
	{
		if (!(w = (char *)ft_memalloc(sizeof(char) * 11)))
			return (NULL);
		j = -1;
		while (data->chain[data->i] >= '0'
				&& data->chain[data->i] <= '9' && ++j < 11)
			w[j] = data->chain[data->i++];
		data->t[5] = ft_atoi(w);
		if (data->chain[data->i] == '*' && ++data->i && ++data->t[9])
			data = manage_width_star(data);
		free(w);
	}
	return (check_precision(data));
}
