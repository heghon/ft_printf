/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:36:19 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/06 17:49:10 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*print_string(t_data *data, char *c)
{
	int	i;

	i = -1;
	if (c == NULL && !(data->t[6] == 0))
	{
		write(1, "(null)", 6);
		data->len += 6;
	}
	if (c != NULL)
	{
		if (data->t[6] >= 0)
			while (c[++i] && i < data->t[6] && ++data->len)
				write(1, &c[i], 1);
		else
			while (c[++i] && ++data->len)
				write(1, &c[i], 1);
	}
	return (data);
}

static int		max(char *c, t_data *data)
{
	if (data->t[6] >= 0 && c != NULL)
		return ((int)ft_strlen(c) > data->t[6] ?
				data->t[6] : (int)ft_strlen(c));
	else if (c != NULL)
		return ((int)ft_strlen(c));
	else
		return (6);
}

static t_data	*print_s_wchar(t_data *data)
{
	wchar_t	*c;
	int		x;

	x = -1;
	c = va_arg(data->arg, wchar_t *);
	if (data->t[5] != 0)
	{
		if (data->t[0] == 0)
			while (++x < data->t[5] - ft_strlen_w(c) && ++data->len)
				write(1, " ", 1);
		ft_putstr_w(c);
		if (data->t[0] != 0)
			while (++x < data->t[5] - ft_strlen_w(c) && ++data->len)
				write(1, " ", 1);
	}
	else if (data->t[5] == 0)
		ft_putstr_w(c);
	data->len = (c == NULL ? data->len + 6 : data->len + ft_strlen_w(c));
	return (data);
}

t_data			*print_s(t_data *data)
{
	char	*c;
	int		x;

	if (data->t[7] != 3)
	{
		x = -1;
		c = va_arg(data->arg, char *);
		if (data->t[5] != 0)
		{
			if (data->t[0] == 0)
				while (++x < data->t[5] - max(c, data) && ++data->len)
					write(1, " ", 1);
			data = print_string(data, c);
			if (data->t[0] != 0)
				while (++x < data->t[5] - max(c, data) && ++data->len)
					write(1, " ", 1);
		}
		else
			data = print_string(data, c);
	}
	else
		data = print_s_wchar(data);
	return (init(data));
}
