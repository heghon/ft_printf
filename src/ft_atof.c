/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:15:49 by bmenant           #+#    #+#             */
/*   Updated: 2019/04/30 11:36:00 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		ft_atof(char *str)
{
	long double result;

	result = 0;
	while (*str)
	{
		result *= 10;
		result += (long double)(*str - '0');
		str++;
	}
	return (result);
}
