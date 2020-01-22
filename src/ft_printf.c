/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:22:35 by bmenant           #+#    #+#             */
/*   Updated: 2019/04/30 11:36:08 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_data	*data;
	int		print;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (-1);
	data->chain = format;
	data->len = 0;
	data->i = -1;
	data = init(data);
	if (data->chain)
	{
		va_start(data->arg, format);
		print = check_all(data);
		va_end(data->arg);
		free(data);
		return (print);
	}
	else
		free(data);
	return (-1);
}
