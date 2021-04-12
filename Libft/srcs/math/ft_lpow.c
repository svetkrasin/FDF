/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:43:40 by svet              #+#    #+#             */
/*   Updated: 2020/10/15 12:35:47 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

long double	ft_lpow(long double base, long int exp)
{
	long double tmp;

	if (exp == 0)
		return (1);
	tmp = ft_lpow(base, exp / 2);
	if (exp % 2 == 0)
		return (tmp * tmp);
	return (exp > 0 ? base * tmp * tmp : tmp * tmp / base);
}
