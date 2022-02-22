/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:20:39 by ilefhail          #+#    #+#             */
/*   Updated: 2022/02/20 18:20:41 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Push_swap.h"

void	ft_rotate(t_head *a, char c)
{
	t_element	*temp;

	if (a->len > 1)
	{
		temp = a->first;
		while (temp -> next)
			temp = temp->next;
		temp->next = a->first;
		a->first = a->first->next;
		temp->next->next = NULL;
		if (c == 'a')
			write(1, "ra\n", 3);
		else if (c == 'b')
			write(1, "rb\n", 3);
	}
}

void	ft_rr(t_head *a, t_head *b)
{
	if (a->len > 1 || b->len > 1)
	{
		ft_rotate(a, 'r');
		ft_rotate(b, 'r');
		write(1, "rr\n", 3);
	}
}

void	ft_reverse_r(t_head *a, char c)
{
	t_element	*temp;
	t_element	*temp1;

	if (a->len > 1)
	{
		temp = a->first;
		while (temp->next)
		{
			temp1 = temp;
			temp = temp->next;
		}
		temp1->next = NULL;
		temp -> next = a->first;
		a->first = temp;
		if (c == 'a')
			write(1, "rra\n", 4);
		else if (c == 'b')
			write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_head *a, t_head *b)
{
	if (a->len > 1 || b->len > 1)
	{
		ft_reverse_r(a, 'r');
		ft_reverse_r(b, 'r');
		write(1, "rrr\n", 4);
	}
}
