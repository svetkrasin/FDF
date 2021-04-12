/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldround.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:45:39 by svet              #+#    #+#             */
/*   Updated: 2020/10/15 12:43:03 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>

static inline long double	ft_floor(long double base)
{
	const unsigned long	base_int = *(unsigned long *)&base;
	unsigned long		mantissa;
	unsigned long		fraction;
	unsigned long		floor;

	mantissa = (base_int & 0xFFF0000000000000) >> 52;
	fraction = base_int & 0x000FFFFFFFFFFFFF;
	mantissa -= 1023;
	floor = ~(0x000FFFFFFFFFFFFF >> mantissa);
	return (base_int & floor);
}

long double					ft_ldround(long double base, int prec)
{
	const int	minus = base < 0 ? 1 : 0;
	long double	floor;
	long double	diff;

	minus == 1 ? base = -base : 0;
	floor = ft_floor(base * ft_lpow(10, prec));
	diff = (base - floor / ft_lpow(10, prec)) * ft_lpow(10, prec);
	if ((unsigned long)floor & 1)
		floor += (diff > 0.499l ? 1.1l : 0.1l);
	else
		floor += (diff > 0.5l ? 1.1l : 0.1l);
	return ((minus == 1 ? floor : -floor) / ft_lpow(10, prec));
}
