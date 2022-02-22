/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_for_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:31:20 by ilefhail          #+#    #+#             */
/*   Updated: 2022/02/21 14:32:26 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Push_swap.h"

int	ft_checkismax(t_element *b)
{
	int	i;
	int	e;
	int	a;

	a = b->value;
	i = 0;
	e = 0;
	while (b)
	{
		if (b->value > a)
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

int	checkismin(t_element *b)
{
	int	i;
	int	e;
	int	a;

	a = b->value;
	i = 0;
	e = b->index;
	while (b)
	{
		if (b->value < a)
		{
			a = b->value;
			e = b->index;
		}
		b = b->next;
		if (b == NULL)
			break ;
		i++;
	}
	return (e);
}

void	ft_bable(int *a, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac - 1)
	{
		j = i;
		while (j < ac - 1)
		{
			if (a[i] > a[j])
			{
				a[i] = a[j] + a[i];
				a[j] = a[i] - a[j];
				a[i] = a[i] - a[j];
			}
			j++;
		}
		i++;
	}
}

void	ft_index(t_element *a, int ac)
{
	int			i;
	int			*abab;
	t_element	*b;

	b = a;
	abab = malloc(sizeof(int) * (ac - 1));
	i = 0;
	while (a)
	{
		abab[i++] = a->value;
		a = a->next;
	}
	ft_bable(abab, ac);
	while (b)
	{
		i = 0;
		while (i < ac - 1)
		{
			if (b->value == abab[i])
				b->index = i;
			i++;
		}
		b = b->next;
	}
	free(abab);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
