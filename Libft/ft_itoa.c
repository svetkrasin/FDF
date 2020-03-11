/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:34:00 by skrasin           #+#    #+#             */
/*   Updated: 2020/01/09 18:48:40 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static size_t	ft_itoa_len(int n)
{
	size_t len;

	len = (n <= 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*s;
	size_t		len;

	len = ft_itoa_len(n);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	s[0] = (n < 0) ? '-' : '0';
	while (n != 0)
	{
		s[--len] = (n % 10) * ((n < 0) ? -1 : 1) + '0';
		n /= 10;
	}
	return (s);
}
