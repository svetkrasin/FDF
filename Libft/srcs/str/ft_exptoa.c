/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exptoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:19:13 by svet              #+#    #+#             */
/*   Updated: 2020/10/15 12:46:34 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_math.h"
#include <stdlib.h>

static inline long int	ft_exp(long double val, int prec)
{
	long int e;

	e = 0;
	if (val != 0)
		while (ft_ldabs(val) < 1)
		{
			val *= 10;
			--e;
		}
	while (ft_ldabs(ft_ldround(val, prec)) >= 10)
	{
		val /= 10;
		++e;
	}
	return (e);
}

char					*ft_exptoa(
	long double val,
	int prec,
	int base,
	int isupper
)
{
	char		*str[2];
	long int	e;

	if ((e = ft_exp(val, prec)) > 0)
		val /= ft_lpow(10, e);
	else if (e < 0)
		val *= ft_lpow(10, -e);
	str[1] = ft_ldtoa_base(ft_ldround(val, prec), prec, base, isupper);
	if ((str[0] = ft_strjoin(str[1], "e ")) == NULL)
		return (NULL);
	free(str[1]);
	str[1] = ft_ltoa_base(ft_llabs(e), base, isupper);
	str[0][ft_strlen(str[0]) - 1] = e < 0 ? '-' : '+';
	if (ft_strappend(&str[0], str[1]) == NULL)
		return (NULL);
	free(str[1]);
	return (str[0]);
}
