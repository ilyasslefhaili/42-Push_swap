/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:26:54 by ilefhail          #+#    #+#             */
/*   Updated: 2022/02/07 11:26:56 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Push_swap.h"

int	ft_pop(t_head *a)
{
	t_element	*temp;
	int			c;

	if (!a)
		exit(1);
	c = a->first->value;
	temp = a->first;
	a->first = a->first->next;
	free(temp);
	a->len = a->len - 1;
	return (c);
}

void	ft_swap(t_head *a, char c)
{
	int	first;
	int	second;
	int	index1;
	int	index2;

	if (a->len > 1)
	{
		index1 = a->first->index;
		index2 = a->first->next->index;
		second = ft_pop(a);
		first = ft_pop(a);
		ft_push_fill(a, second);
		a->first->index = index1;
		ft_push_fill(a, first);
		a->first->index = index2;
		if (c == 'a')
			write(1, "sa\n", 3);
		else if (c == 'a')
			write(1, "sb\n", 3);
	}
}

void	ft_ss(t_head *a, t_head *b, int c)
{
	ft_swap(a, 'r');
	ft_swap(b, 'r');
	if (c == 1)
		write(1, "ss\n", 3);
}

void	ft_push(t_head *a, t_head *b, char c)
{
	int	ind;

	if (b->len > 0)
	{
		ft_push_fill(a, b->first->value);
		ind = b->first->index;
		ft_pop(b);
		a->first->index = ind;
		if (c == 'a')
			write(1, "pa\n", 3);
		else if (c == 'b')
			write(1, "pb\n", 3);
	}
}	
