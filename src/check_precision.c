/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:09:36 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/07 14:25:58 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*check_precision(t_data *data)
{
	char	*w;
	int		j;

	if (data->chain[data->i] == '.' && ++data->i)
	{
		if ((data->chain[data->i] >= '0' && data->chain[data->i] <= '9')
				&& ++data->t[9] < 10)
		{
			if (!(w = (char *)ft_memalloc(sizeof(char) * 11)))
				return (NULL);
			j = -1;
			while (data->chain[data->i] >= '0' &&
					data->chain[data->i] <= '9' && ++j < 11)
				w[j] = data->chain[data->i++];
			data->t[6] = ft_atoi(w);
			free(w);
		}
		else if (data->chain[data->i] == '*' && data->t[6] == -1 && ++data->i)
			data->t[6] = va_arg(data->arg, int);
		else if (data->chain[data->i] == '*' && data->t[6] >= 0 && ++data->i)
			j = va_arg(data->arg, int);
		else
			data->t[6] = 0;
	}
	return (check_length(data));
}
