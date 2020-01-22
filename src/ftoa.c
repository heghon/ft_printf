/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:54:19 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/02 17:01:05 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(long double n)
{
	unsigned int	i;
	long double		neg;
	long double		size;
	char			*s;

	neg = 0;
	size = 1;
	if (n < 0)
	{
		i = ((-1) * n);
		neg = 1;
	}
	else
		i = n;
	while (n /= 10)
		size++;
	if (!(s = (char *)malloc(sizeof(char) * (size + 1 + neg))))
		return (NULL);
	s[size + neg] = '\0';
	s[--size + neg] = (i % 10) + 48;
	while (i /= 10)
		s[--size + neg] = (i % 10) + 48;
	if (neg == 1)
		s[0] = '-';
	return (s);
}
