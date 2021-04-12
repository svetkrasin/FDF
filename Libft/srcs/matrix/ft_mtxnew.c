/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:42:23 by svet              #+#    #+#             */
/*   Updated: 2021/04/10 19:08:19 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"
#include "ft_memory.h"
#include <sys/_types/_null.h>

t_matrix	*ft_mtxnew(const size_t columns, const size_t rows)
{
	t_matrix	*matrix;
	size_t		i;

	if (columns == 0 || rows == 0 ||
	(matrix = (t_matrix *)ft_memalloc(sizeof(t_matrix))) == NULL ||
	(matrix->content = (void **)ft_memalloc(columns * sizeof(void *))) == NULL)
		return (NULL);
	i = 0;
	while (i < columns)
		if ((matrix->content[i++] = ft_memalloc(rows)) == NULL)
			return (NULL);
	return (matrix);
}
