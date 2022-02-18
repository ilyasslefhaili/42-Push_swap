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
	a->len++;
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
		printf("%d == index == %d\n",a->value, a->index);
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
	int a;

	a = b->value;
	i = 0;
	e = b->index;
	while(b)
	{
		if(b->value < a)
		{
			a = b->value;
			e = b->index;
		}
		b = b->next;
		if(b == NULL)
			break ;
		i++;
	}
	return e;
}

void checknumber(char **av)
{
	int i;
	int j;

	i = 1;
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if(av[i][j] == '#' || av[i][j] == '$')
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
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

void ft_bable(int *a, int ac)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < ac - 1)
	{
		j = i;
		while(j < ac - 1)
		{
			if(a[i] > a[j])
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
	int	i;
	int j;
	int *abab;
	t_element *b;

	b = a;
	abab = malloc(sizeof(int) * (ac - 1));
	i = 0;
	while(a)
	{
		abab[i] = a->value;
		i++;
		a = a->next;
	}
	ft_bable(abab, ac);
	while(b)
	{
		i = 0;
		while(i < ac - 1)
		{
			if(b->value == abab[i])
				b->index = i;
			i++;
		}
		b = b->next;
	}
	free(abab);
}

void	ft_return_in_a(t_head *a, t_head *b)
{
	int i;
	int j;

	while(b->first)
	{
		ft_push(a, b, 'a');
		if(a->first->value > a->first->next->value)
			ft_swap(a, 'a');
		j = a->first->next->index - a->first->index;
		if(j > 1)
		{
			i = 0;
			while(a->first->index + 1 < a->first->index)
			{
				ft_rotate(a, 'a');
				i++;
				ft_push(b, a, 'a');
			}
			while(i > 0)
			{
				if(a->first->index + 1 < a->first->next->index)
					ft_swap(a,'a');
				ft_reverse_r(a, 'a');
				i--;
			}
		}

	}

}

void	ready_to_push(t_head *a, t_head *b, int max, int min,int thep, int *k)
{
	int i;
	int j;
	int e;
	t_element	*temp;

	i = 0;
	j = 0;
	while(i < thep)
	{
		temp = a->first;
		e = 0;
		
		while(temp->index > max || temp->index < min)
		{
			temp = temp->next;
			if(temp == NULL)
				break ;
			e++;
		}
		//printf("min == %d , max == %d", min , max);
		j = 0;
		if(a->len - e > e)
		{
			while(j < e)
			{
				ft_rotate(a, 'a');
				j++;
			}
		}
		else
		{
			while(j < a->len - e)
			{
				ft_reverse_r(a, 'a');
				j++;
			}
		}
		if(a->first->index > max)
			break ;
		ft_push(b, a, 'b');
		*k = *k + 1;
		i++;
	}
}

void	sorting(t_head *a, t_head *b)
{
	int min;
	int max;
	int thep;
	int j;
	int i;

	i = 0;
	j = a->len;
	while(i <  j - 5)
	{
		min = checkismin(a->first);
		thep = (a->len - 5) / 3 + 1;
		max = thep + min - 1;
		//printf("max %d", max);
		//printf("%d\n", j);
		ready_to_push(a, b, max, min, thep, &i);
		//printf("%d\n", i);
		//printf("kkk\n");
	}
}

int main(int ac, char **av)
{
	t_head *a = malloc(sizeof(t_head));
	t_head *b = malloc(sizeof(t_head));

	a->len = 0;
	b->len = 0;
	b->first = NULL;
	a->first = NULL;
	checknumber(av);
	fillstack(av, ac, a);
	ft_index(a->first, ac);
	sorting(a, b);
	//fivesort(a, b);
	//printf("a\n ------------------\n");
	//display_list(a->first);
	//printf("b\n ------------------\n");
	display_list(b->first);
	//ft_return_in_a(a, b);
	//printf("a\n ------------------\n");
	//display_list(a->first);
	//printf("%d",checkismin(a->first));
}
