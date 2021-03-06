/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:23:38 by skrasin           #+#    #+#             */
/*   Updated: 2021/04/14 21:08:32 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		get_columns(char **numbers)
{
	size_t n;

	n = 0;
	while(numbers[n++] != NULL)
		continue ;
	return (n); 
}

t_matrix	*build_matrix(t_list *lst)
{
	const size_t	columns = lst->content_size / sizeof(char *) - 1;
	const size_t	rows = ft_lstlength(lst);
	t_matrix *const	mtx = ft_mtxnew(rows, columns);
	size_t			i;
	size_t			j;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < columns)
		{
			if (columns != lst->content_size / sizeof(char *) - 1)
				exit(-1);
			ft_mtxsetelem(mtx, i, j, (long double)ft_strtol(((char **)(lst->content))[j], NULL, 10));
		}
		lst = lst->next;
	}
	ft_mtxprint(*mtx);
	return (mtx);
}

int			parse_file(int fd, t_matrix **map)
{
	int		read;
	char	*line;
	char	**numbers;
	t_list	*lst;

	if (fd < 0)
		return (0); //found wrong line length. Exiting.
	lst = NULL;
	while((read = ft_getline(fd, &line)) > 0) //no data found (empty first line)
	{
		numbers = ft_strsplit(line, ' ');
		ft_lstadd_back(&lst, ft_lstnew(numbers, get_columns(numbers) * sizeof(char *)));
		free(line);
	}
	*map = build_matrix(lst);
	if (read < 0 || map == NULL)
		return (0);
	return (1);
}
