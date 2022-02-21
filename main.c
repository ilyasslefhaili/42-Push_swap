/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:17:06 by ilefhail          #+#    #+#             */
/*   Updated: 2022/01/04 11:17:08 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_return_in_a(t_head *a, t_head *b)
{
	int	i;

	while (b->first)
	{
		i = 0;
		if (ft_checkismax(b->first) < b->len - ft_checkismax(b->first))
		{
			while (b->first->index + 1 != a->first->index)
			{
				ft_rotate(b, 'b');
				i++;
			}
			ft_push(a, b, 'a');
		}
		else
		{
			while (b->first->index + 1 != a->first->index)
			{
				ft_reverse_r(b, 'b');
				i++;
			}
			ft_push(a, b, 'a');
		}
	}
}

void	get_element(t_head *a, int e)
{
	int	j;

	j = 0;
	if (a->len - e > e)
	{
		while (j < e)
		{
			ft_rotate(a, 'a');
			j++;
		}
	}
	else
	{
		while (j < a->len - e)
		{
			ft_reverse_r(a, 'a');
			j++;
		}
	}
}

void	ready_to_push(t_head *a, t_head *b, t_min_max nx, int *k)
{
	int			i;
	int			e;
	t_element	*temp;

	i = 0;
	while (i < nx.thep)
	{
		temp = a->first;
		e = 0;
		while (temp->index > nx.max || temp->index < nx.min)
		{
			temp = temp->next;
			if (temp == NULL)
				break ;
			e++;
		}
		get_element(a, e);
		if (a->first->index > nx.max)
			break ;
		ft_push(b, a, 'b');
		*k = *k + 1;
		i++;
	}
}

void	sorting(t_head *a, t_head *b)
{
	t_min_max	nx;
	int			j;
	int			i;

	i = 0;
	j = a->len;
	while (i < j - 5)
	{
		nx.min = checkismin(a->first);
		nx.thep = (a->len - 5) / 6 + 1;
		nx.max = nx.thep + nx.min - 1 ;
		ready_to_push(a, b, nx, &i);
	}
}

int	main(int ac, char **av)
{
	t_head	*a;
	t_head	*b;

	check_is_str_empty(av, ac);
	a = malloc(sizeof(t_head));
	b = malloc(sizeof(t_head));
	a->len = 0;
	b->len = 0;
	b->first = NULL;
	a->first = NULL;
	checknumber(av);
	fillstack(av, ac, a);
	check_if_sort(a->first, ac);
	if (a->len <= 5)
		fivesort(a, b);
	else
	{
		ft_index(a->first, ac);
		sorting(a, b);
		fivesort(a, b);
		ft_return_in_a(a, b);
	}
	free(b);
}
