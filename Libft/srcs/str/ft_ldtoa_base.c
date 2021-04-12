/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:05:05 by svet              #+#    #+#             */
/*   Updated: 2020/10/15 12:39:47 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_math.h"
#include <stdlib.h>

char	*ft_ldtoa_base(long double val, int prec, int base, int isupper)
{
	const unsigned int	minus = val < 0 ? 1 : 0;
	unsigned long int	vd[2];
	char				*str[2];

	minus == 1 ? val = -val : 0;
	val = ft_ldround(val, prec);
	vd[0] = (unsigned long)val;
	vd[1] = (unsigned long)((val - vd[0]) * ft_lpow(10, prec));
	if ((str[0] = ft_strnew(ft_unum_of_digs(vd[0], base) +
			ft_unum_of_digs(vd[1], base) + minus + 1)) == NULL)
		return (NULL);
	minus == 1 ? str[0][0] = '-' : 0;
	if ((str[1] = ft_ultoa_base(vd[0], base, isupper)) == NULL)
		return (NULL);
	ft_strcpy(str[0] + minus, str[1]);
	free(str[1]);
	if ((str[1] = ft_ultoa_base(vd[1], base, isupper)) == NULL)
		return (NULL);
	vd[0] = (unsigned long)(str[0] + ft_strlen(str[0]));
	*(char *)vd[0] = '.';
	ft_strcpy((char *)(vd[0] + 1), str[1]);
	free(str[1]);
	return (str[0]);
}
