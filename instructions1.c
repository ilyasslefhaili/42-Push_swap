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
int  ft_pop(t_head *a)
{
    t_element   *temp;
    int         c;

    c = a->first->value;
    temp = a->first;
    a->first = a->first->next;
    free(temp);
	a->lent = a->lent - 1;
    return c;
}

void    ft_swap(t_head *a, char c)
{
    int first;
    int second;

    if(countstack(a->first) > 1)
    {
		second = ft_pop(a);
        first = ft_pop(a);
        ft_push_fill(a, second);
        ft_push_fill(a, first);
    }
	if(c == 'a')
		write(1, "sa", 2);
	else if(c == 'a')
		write(1, "sb", 2);
}

void    ft_ss(t_head *a, t_head *b)
{
    ft_swap(a, 'r');
    ft_swap(b, 'r');
}

void ft_push(t_head *a, t_head *b, char c)
{
	ft_push_fill(a, b->first->value);
	ft_pop(b);
	if(c == 'a')
		write(1, "pa\n", 3);
	else if(c == 'b')
		write(1, "pb\n", 3);
}

void	ft_rotate(t_head *a, char c)
{
	t_element *temp;

	temp = a->first;
	while(temp -> next)
		temp = temp->next;
	temp->next = a->first;
	a->first = a->first->next;
	temp->next->next = NULL;
	if(c == 'a')
		write(1, "ra\n", 3);
	else if(c == 'b')
		write(1, "rb\n", 3);	
}

void	ft_rr(t_head *a, t_head *b)
{
	ft_rotate(a, 'r');
	ft_rotate(b, 'r');
	write(1, "rr\n", 3);
}

void	ft_reverse_r(t_head *a, char c)
{
	t_element	*temp;
	t_element	*temp1;

	if(a->first->next != NULL)
	{
		temp = a->first;
		while(temp->next)
		{
			temp1 = temp;
			temp = temp->next;
		}
		temp1->next=NULL;
		temp -> next = a->first;
		a->first = temp;
		if(c == 'a')
			write(1, "rra\n", 4);
		else if(c == 'b')
			write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_head *a, t_head *b)
{
	ft_reverse_r(a, 'r');
	ft_reverse_r(b, 'r');
	write(1, "rrr\n", 4);
}