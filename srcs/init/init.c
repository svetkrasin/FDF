/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:33:02 by skrasin           #+#    #+#             */
/*   Updated: 2021/04/11 22:12:29 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
	int		case_size;
	int		z_size;
	char	*map;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			perror(NULL);
		if ((mlx_ptr = mlx_init()) != (void *)0 )
		{
			if (ft_parse_file(fd, &map, &case_size, &z_size) != 0)
			{
				case_size = ft_atoi(argv[2]);
				z_size = ft_atoi(argv[3]);
				if ((win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "fdf")) != NULL)
				{
					fd++;
				}
			}
		}
	}
	else
		ft_putstr("Usage : ./fdf <filename>\n");
	return (0);
}
