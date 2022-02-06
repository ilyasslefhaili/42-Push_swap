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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

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
	if (nmbr > LONG_MAX)
	{
		if (s == 1)
			return (-1);
		else
			return (0);
	}
	return (s * nmbr);
}

typedef struct element {
	int value;
	struct element *next;
}t_element;

typedef struct head {
	t_element *first;
}t_head;

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

void push(t_head *a, int nmbr)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!a || !new)
		exit(1);
	new->next = a -> first;
	a->first = new;
	new -> value = nmbr;
}
void fillstack(char **av, int ac, t_head *a)
{
	int i;

	i = ac - 1;
	while(i > 0)
	{
		push(a, ft_atoi(av[i]));
		i--;
	}
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
			else if((av[i][j] <= '0' || av[i][j] >= '9' ) && av[i][j] != '-')
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

	checknumber(av);
	a -> first = NULL;
	fillstack(av, ac, a);
	//printf("%d\n",countstack(a -> first));
	display_list(a->first);
}
