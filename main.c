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

static void	done(const char *str, int i, unsigned long long *nmbr)
{
	*nmbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*nmbr = *nmbr * 10 + (str[i] - '0');
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	nmbr;
	int					s;

	i = 0;
	s = 1;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s *= -1;
		i++;
	}
	done(str, i, &nmbr);
	if ((nmbr > 2147483647 && s == 1) || (nmbr > 2147483648 && s == -1))
	{
		if (s == 1)
			return (-1);
		else
			return (0);
	}
	return (s * nmbr);
}

int countstack(t_element *a)
{
	int i;

	i = 0;
	while(a != NULL)
	{
		a  = a->next;
		i++;
	}
	return(i);
}

void ft_push_fill(t_head *a, int nmbr)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!a || !new)
		exit(1);
	new->next = a -> first;
	a->first = new;
	new -> value = nmbr;
	a->lent++;
}

void ft_arr(int *arr, int nbr, int e)
{
	int i;

	i = 0;
	while(i < e)
	{
		if(arr[i] == nbr)
		{
			write(2,"Error\n",6);
			free(arr);
			//system("leaks a.out");
			exit(1);
		}
		i++;
	}
}

void fillstack(char **av, int ac, t_head *a)
{
	int i;
	int *arr;
	int j;

	j = 0;
	arr = malloc(sizeof(int) * (ac - 1));
	i = ac - 1;
	while(i > 0)
	{
		ft_arr(arr,ft_atoi(av[i]), j);
		ft_push_fill(a, ft_atoi(av[i]));
		arr[j] = ft_atoi(av[i]);
		j++;
		i--;
	}
	free(arr);
}

void display_list(t_element *a)
{
	while(a != NULL)
	{
		printf("%d\n",a->value);
		a = a->next;
	}
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return(i);
}

int	checkismin(t_element *b)
{
	int i;
	int e;

	e = b->value;
	while(e < b->value)
	{
		b = b->next;
		if(b == NULL)
			return 1;
	}
	return 0;
}

void checknumber(char **av)
{
	int i;
	int j;

	i = 1;
	while(av[i])
	{
		j = 0;
		if((ft_atoi(av[i]) == -1 || ft_atoi(av[i]) == 0) && ft_strlen(av[i]) >= 10)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		while(av[i][j])
		{
			if(av[i][j] == '-' && j != 0)
			{
				//printf("%d\n", j);
				write(2, "Error\n", 6);
				exit(1);
			}
			else if((av[i][j] < '0' || av[i][j] > '9' ) && av[i][j] != '-')
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}


int main(int ac, char **av)
{
	t_head *a = malloc(sizeof(t_head));
	t_head *b = malloc(sizeof(t_head));
	int i;
	int j;

	a->lent = 0;
	b->lent = 0;
	b->first = NULL;
	a->first = NULL;
	fillstack(av, ac, a);
	while(a->first)
	{
		i = 0;
		j = 0;
		ft_push(b, a, 'b');
		if(b->lent ==  1)
		{
			ft_push(b, a,'b');
			i++;
		}
		while(b->first->value < b->first->next->value)
		{
			if(checkismin(b->first))
				ft_rotate(b, 'b');
			else
			{
				ft_swap(b, 'b');
				ft_push(a, b, 'a');
				i++;
			}
			if(b->lent <= 1)
				break ;
		}
		while(j > i)
		{
			ft_push(b, a, 'b');
			j++;
		}
	}
	while(b->first)
		ft_push(a, b, 'a');
	//display_list(a->first);
}

