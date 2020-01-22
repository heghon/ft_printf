/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 13:19:24 by bmenant           #+#    #+#             */
/*   Updated: 2019/05/04 13:20:31 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_absolute(int x)
{
	return (x < 0 ? -x : x);
}