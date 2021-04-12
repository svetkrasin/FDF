/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:07:19 by svet              #+#    #+#             */
/*   Updated: 2020/08/20 15:07:33 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <sys/_types/_null.h>

char	*ft_strappend(char **dst, char const *src)
{
	if (dst == NULL || *dst == NULL || src == NULL)
		return (NULL);
	return (ft_memappend((void **)dst, src, ft_strlen(*dst), ft_strlen(src)));
}
