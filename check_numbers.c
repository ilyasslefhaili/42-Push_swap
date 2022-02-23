/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:26:50 by ilefhail          #+#    #+#             */
/*   Updated: 2022/02/22 20:26:55 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	checknumber(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if ((ft_atoi(av[i]) == -1 || ft_atoi(av[i]) == 0)
			&& ft_strlen(av[i]) >= 10)
			error();
		while (av[i][j])
		{
			if (av[i][j] == '-' && j != 0)
				error();
			else if ((av[i][j] < '0' || av[i][j] > '9' ) && av[i][j] != '-')
				error();
			j++;
		}
		i++;
	}
}

void	check_if_sort(t_element *c, int ac, t_head *a, t_head *b)
{
	int	*k;
	int	i;
	int	j;

	k = malloc(sizeof(int) * ac - 1);
	i = 0;
	j = 0;
	while (c)
	{
		j = 0;
		while (j < i)
		{
			if (k[j] > c->value)
			{
				free(k);
				return ;
			}
			j++;
		}
		k[i] = c->value;
		i++;
		c = c->next;
	}
	finish(a, b);
	exit(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	check_is_str_empty(char **av, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "") == 0)
			error();
		i++;
	}
}
