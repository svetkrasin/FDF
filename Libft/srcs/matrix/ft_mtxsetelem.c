/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxsetelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:33:20 by svet              #+#    #+#             */
/*   Updated: 2021/04/12 22:58:31 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

void	ft_mtxsetelem(
	t_matrix *mtx,
	size_t row,
	size_t column,
	long double value
)
{
	mtx->content[row * mtx->rows + column] = value;
}
