/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:23:38 by skrasin           #+#    #+#             */
/*   Updated: 2020/03/11 13:16:47 by skrasin          ###   ########.fr       */
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
	while((read = ft_get_next_line(fd, &line)) > 0)
	{
		++i;
		
	}
	if (read < 0)
		return (0);
	
}
