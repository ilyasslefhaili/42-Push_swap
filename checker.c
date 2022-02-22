/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:15:47 by ilefhail          #+#    #+#             */
/*   Updated: 2022/02/22 11:15:50 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Push_swap.h"

int	check(t_element *a, int ac)
{
	int	*k;
	int	i;
	int	j;

	k = malloc(sizeof(int) * ac - 1);
	i = 0;
	j = 0;
	while (a)
	{
		j = 0;
		while (j < i)
		{
			if (k[j] > a->value)
			{
				free(k);
				return (0);
			}
			j++;
		}
		k[i] = a->value;
		i++;
		a = a->next;
	}
	return(-1);
}

void ft_if(t_head *a, t_head *b, char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		ft_push(a, b, 'c');	
	else if (ft_strcmp(str, "pb\n") == 0)
		ft_push(b, a, 'c');
	else if (ft_strcmp(str, "ra\n") == 0)
		ft_rotate(a, 'c');
	else if (ft_strcmp(str, "rb\n") == 0)
		ft_rotate(a, 'c');
	else if(ft_strcmp(str, "rr\n") == 0)
		ft_rr(a, b, 0);
	else if (ft_strcmp(str, "sa\n") == 0)
		ft_swap(a, 'c');
	else if (ft_strcmp(str, "sb\n") == 0)
		ft_swap(b, 'c');
	else if (ft_strcmp(str, "ss\n") == 0)
		ft_ss(a, b, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		ft_reverse_r(a, 'r');
	else if (ft_strcmp(str, "rrb\n") == 0)
		ft_reverse_r(b, 'r');
	else if (ft_strcmp(str, "rrr\n") == 0)
		ft_rrr(a, b, 0);
	else
		error();
}

void	ft_if1(t_element *a, int ac, int size, int len)
{
	if(check(a, ac) == 0)
		write(1, "KO\n", 3);
	else if (len != size)
		write(1, "KO\n", 3);
	else if(check(a, ac) == -1)
		write(1, "OK\n", 3);
}

int main(int ac, char **av)
{
	t_head	*a;
	t_head	*b;
	char	*str;
	int		size;

	if(ac <= 1)
		exit(0);
	check_is_str_empty(av, ac);
	a = malloc(sizeof(t_head));
	b = malloc(sizeof(t_head));
	a->len = 0;
	b->len = 0;
	b->first = NULL;
	a->first = NULL;
	checknumber(av);
	fillstack(av, ac, a);
	size = a->len;
	str = get_next_line(0, 1);
	while(str)
	{
		ft_if(a, b, str);
		str = get_next_line(0, 1);
	}
	ft_if1(a->first, ac, size, a->len);
}
