/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:26:49 by svet              #+#    #+#             */
/*   Updated: 2021/04/13 10:08:00 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H
# include "ft_printf.h"
# include <sys/_types/_ssize_t.h>

void	ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

void	ft_putchar(int c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putlnbr_base_fd(long n, int base, int isupper, int fd);
void	ft_putlnbr_base(long n, int base, int isupper);

ssize_t	ft_getline(const int fd, char **line);

#endif
