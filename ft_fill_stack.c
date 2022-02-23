/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:45:46 by ilefhail          #+#    #+#             */
/*   Updated: 2022/02/21 15:45:48 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Push_swap.h"

void	ft_push_fill(t_head *a, int nmbr)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!a || !new)
		exit(1);
	new->next = a -> first;
	a->first = new;
	new -> value = nmbr;
	a->len++;
}

void	ft_arr(int *arr, int nbr, int e)
{
	int	i;

	i = 0;
	while (i < e)
	{
		if (arr[i] == nbr)
		{
			write(2, "Error\n", 6);
			free(arr);
			exit(1);
		}
		i++;
	}
}

void	fillstack(char **av, int ac, t_head *a)
{
	int	i;
	int	*arr;
	int	j;

	j = 0;
	arr = malloc(sizeof(int) * (ac - 1));
	if (!arr)
		exit(1);
	i = ac - 1;
	while (i > 0)
	{
		ft_arr(arr, ft_atoi(av[i]), j);
		ft_push_fill(a, ft_atoi(av[i]));
		arr[j] = ft_atoi(av[i]);
		j++;
		i--;
	}
	free(arr);
}

void	ft_free(t_head *a)
{
	while (a->first)
		ft_pop(a);
	free(a);
}

void	finish(t_head *a, t_head *b)
{
	ft_free(a);
	ft_free(b);
}
