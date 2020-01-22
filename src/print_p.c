/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:25:21 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/01 18:16:55 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert(void *p)
{
	char				*str;
	unsigned long long	nbr;
	unsigned long long	nbr_copy;
	int					i;

	nbr = (unsigned long long)p;
	nbr_copy = nbr;
	i = 0;
	if (nbr_copy == 0)
		i = 1;
	else
		while (nbr_copy && ++i)
			nbr_copy /= 16;
	if (!(str = (char*)ft_memalloc(i + 1)))
		return (NULL);
	if (p == NULL)
		str[0] = '0';
	while (nbr)
	{
		str[--i] = (nbr % 16 > 9) ? (nbr % 16 - 10 + 'a')
			: (nbr % 16 + '0');
		nbr /= 16;
	}
	return (str);
}

t_data		*print_p(t_data *data)
{
	void	*p;
	char	*str;

	p = va_arg(data->arg, void*);
	str = convert(p);
	data->t[10] = (int)ft_strlen(str);
	data->t[11] = (data->t[6] == -1 && !p ? 0 : ft_strlen(str) + 2);
	data->t[12] = (data->t[5] > data->t[10] ?
			data->t[5] : data->t[10]);
	if (data->t[1] || data->t[3])
		data->t[11]++;
	data = check_space(data, 1);
	if (data->t[1] && ++data->len)
		write(1, "+", 1);
	data->len += 2;
	write(1, "0x", 2);
	data = check_space(data, 0);
	data->len += data->t[10];
	write(1, str, data->t[10]);
	data = check_space(data, 2);
	free(str);
	return (init(data));
}
