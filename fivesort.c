/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivesort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:24:06 by ilefhail          #+#    #+#             */
/*   Updated: 2022/02/20 16:24:24 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Push_swap.h"

int	ft_checkismin_five(t_element *b)
{
	int	i;
	int	e;
	int	a;

	a = b->value;
	i = 0;
	e = 0;
	while (b)
	{
		if (b->value < a)
		{
			a = b->value;
			e = i;
		}
		b = b->next;
		if (b == NULL)
			break ;
		i++;
	}
	return (e);
}

void	ft_sort_3(t_head *a)
{
	if (a->first->value > a->first->next->value)
		ft_swap(a, 'a');
	if (a->first->value > a->first->next->next->value)
		ft_reverse_r(a, 'a');
	if (a->first->next->value > a->first->next->next->value)
	{
		ft_reverse_r(a, 'a');
		ft_swap(a, 'a');
	}
}

void	ft_sort_a_in_b(t_head *a, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (k < a->len - k)
	{
		while (i < k)
		{
			ft_rotate(a, 'a');
			i++;
		}
	}
	else
	{
		while (j < a->len - k)
		{
			ft_reverse_r(a, 'a');
			j++;
		}
	}
}

void	ft_while(t_head *a, t_head *b)
{
	int	i;

	i = 1;
	while (i < 4)
	{
		ft_push(a, b, 'a');
		i++;
	}
}

void	fivesort(t_head *a, t_head *b)
{
	int	k;

	if (a->len > 3)
	{
		while (a->first)
		{
			k = ft_checkismin_five(a->first);
			ft_sort_a_in_b(a, k);
			ft_push(b, a, 'b');
			if (a->len == 3)
				break ;
		}
	}
	if (a->len == 3)
		ft_sort_3(a);
	else
	{
		if (a->first->value > a->first->next->value)
			ft_swap(a, 'a');
	}
	ft_while(a, b);
}
