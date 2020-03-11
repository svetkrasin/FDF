/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:58:27 by skrasin           #+#    #+#             */
/*   Updated: 2020/01/09 18:49:04 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memalloc(size_t size)
{
	void *f;

	if (!(f = malloc(size * sizeof(void))))
		return (NULL);
	ft_bzero(f, size);
	return (f);
}
