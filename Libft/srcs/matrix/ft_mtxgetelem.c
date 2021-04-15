/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxgetelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:33:00 by svet              #+#    #+#             */
/*   Updated: 2021/04/13 18:32:22 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

long double	ft_mtxgetelem(t_matrix mtx, size_t row, size_t column)
{
	return (mtx.content[row * mtx.columns + column]);
}
