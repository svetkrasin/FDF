/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:33:02 by skrasin           #+#    #+#             */
/*   Updated: 2021/04/12 22:09:23 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
	t_matrix	*map;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			perror(strerror(errno));
		else if ((mlx_ptr = mlx_init()) == NULL)
			perror("Unable establish connection with Window Server");
		else if (parse_file(fd, &map) == 0)
			perror("Wrong file format");
		else if ((win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "fdf")) == NULL)
			perror("Fails to create a window");
	}
	else
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
	return (0);
}
