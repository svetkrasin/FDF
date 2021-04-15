/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:34:47 by svet              #+#    #+#             */
/*   Updated: 2021/04/13 10:15:05 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H
# include <sys/_types/_size_t.h>

typedef struct	s_matrix
{
	long double	*content;
	size_t		rows;
	size_t		columns;
}				t_matrix;

t_matrix		*ft_mtxnew(const size_t rows, const size_t columns);
void			ft_mtxsetelem(t_matrix *mtx, size_t row, size_t column,
															long double value);
long double		ft_mtxgetelem(t_matrix mtx, size_t row, size_t column);
void			ft_mtxprint(t_matrix mtx);

#endif
