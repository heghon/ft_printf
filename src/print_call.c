/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_call.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:49:49 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/07 14:12:40 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*print_call(t_data *data)
{
	if (data->t[8] == 1)
		data = print_c(data);
	else if (data->t[8] == 2)
		data = print_s(data);
	else if (data->t[8] == 3)
		data = print_p(data);
	else if (data->t[8] == 4)
		data = print_d(data);
	else if (data->t[8] == 5)
		data = print_o(data);
	else if (data->t[8] == 6)
		data = print_u(data);
	else if (data->t[8] == 7)
		data = print_x(data);
	else if (data->t[8] == 8)
		data = print_bx(data);
	else if (data->t[8] == 9)
		data = print_f(data);
	else if (data->t[8] == 10)
		data = print_percent(data);
	else
		data = print_nothing(data);
	return (data);
}
