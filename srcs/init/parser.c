/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:23:38 by skrasin           #+#    #+#             */
/*   Updated: 2021/04/11 18:32:12 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_parse_file(int fd, char **map, int *case_size, int *z_size)
{
	int read;
	char *line;
	int	i;

	if (fd < 0 || map == NULL || *map == NULL || case_size == NULL ||
																z_size == NULL)
		return (0);
	i = 0;
	while((read = ft_getline(fd, &line)) > 0)
	{
		++i;
		
	}
	if (read < 0)
		return (0);
	return (1);
}
