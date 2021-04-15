/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:03:07 by svet              #+#    #+#             */
/*   Updated: 2021/04/14 21:17:33 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"
#include "ft_io.h"
#include <stdio.h>

void	ft_mtxprint(t_matrix mtx)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < mtx.rows)
	{
		j = 0;
		while (j < mtx.columns)
		{
			printf("%3.0Lf%c", ft_mtxgetelem(mtx, i, j), j == mtx.columns - 1 ? '\n': ' ');
			++j;
		}
		++i;
	}
}
