/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:33:02 by skrasin           #+#    #+#             */
/*   Updated: 2020/03/11 13:16:41 by skrasin          ###   ########.fr       */
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
	int		*map;

	if (argc > 1 && argc != 3 && argc < 5)
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
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]");
	return (0);
}