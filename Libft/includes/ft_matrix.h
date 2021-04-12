/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:34:47 by svet              #+#    #+#             */
/*   Updated: 2021/04/10 18:59:10 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H
# include <sys/_types/_size_t.h>

typedef struct	s_matrix
{
	void		**content;
	size_t		columns;
	size_t		rows;
}				t_matrix;

t_matrix		*ft_mtxnew(const size_t columns, const size_t rows);

#endif
