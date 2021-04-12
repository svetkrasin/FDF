/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_posprocessor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:07:51 by svet              #+#    #+#             */
/*   Updated: 2020/10/16 16:05:31 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_parser.h"
#include <sys/_types/_null.h>

static inline void		pos_front_back_split(
	t_dlist *source,
	t_dlist **frontref,
	t_dlist **backref,
	size_t len
)
{
	size_t hopcount;

	if (len < 2)
	{
		*frontref = source;
		*backref = NULL;
	}
	else
	{
		hopcount = (len - 1) / 2;
		*frontref = source;
		while (hopcount-- != 0)
			source = source->next;
		*backref = source->next;
		source->next = NULL;
	}
}

static inline t_dlist	*pos_sorted_merge_and_delete_copy(
	t_dlist *a,
	t_dlist *b
)
{
	t_dlist	*result;
	size_t	na;
	size_t	nb;

	if (a == NULL || b == NULL)
		return (a == NULL ? b : a);
	na = ((t_pos *)(a->content))->n;
	if (na < (nb = ((t_pos *)(b->content))->n))
	{
		result = a;
		result->next = pos_sorted_merge_and_delete_copy(a->next, b);
	}
	else if (na > nb)
	{
		result = b;
		result->next = pos_sorted_merge_and_delete_copy(a, b->next);
	}
	else
	{
		result = a;
		a = a->next;
		ft_dlstdelone(&result, &ft_lstdelcontent);
		result = pos_sorted_merge_and_delete_copy(a, b);
	}
	return (result);
}

static inline void		pos_merge_sort(t_dlist **head_p, size_t len)
{
	t_dlist *head;
	t_dlist *a;
	t_dlist *b;

	head = *head_p;
	if (len == 0 || head == NULL || head->next == NULL)
		return ;
	pos_front_back_split(head, &a, &b, len);
	len = (len - 1) / 2;
	pos_merge_sort(&a, len);
	pos_merge_sort(&b, len);
	*head_p = pos_sorted_merge_and_delete_copy(a, b);
}

void					pos_proc(t_dlist **pos_head_p, t_dlist *fmt_head)
{
	t_dlist	*pos_node;
	size_t	len;

	len = 0;
	pos_node = *pos_head_p;
	while (pos_node != NULL)
	{
		if (((t_pos *)(pos_node->content))->type == 0)
		{
			while (((t_fmt *)(fmt_head->content))->param !=
											((t_pos *)(pos_node->content))->n)
				fmt_head = fmt_head->next;
			((t_pos *)(pos_node->content))->type =
										((t_fmt *)(fmt_head->content))->type;
			((t_pos *)(pos_node->content))->flags =
										((t_fmt *)(fmt_head->content))->flags;
		}
		pos_node = pos_node->next;
		++len;
	}
	pos_merge_sort(pos_head_p, len);
}
