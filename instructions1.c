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
    return c;
}

void    ft_swap(t_head *a)
{
    int first;
    int second;

    if(countstack(a->first) > 1)
    {
		second = ft_pop(a);
        first = ft_pop(a);
        ft_push(a, second);
        ft_push(a, first);
    }
}

void    ft_ss(t_head *a, t_head *b)
{
    ft_swap(a);
    ft_swap(b);
}

void ft_push_a(t_head *a, t_head *b, char c)
{
	ft_push(a, b->first->value);
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
		write(1, "rra\n", 3);
	else if(c == 'b')
		write(1, "rrb\n", 3);
}

void	ft_rrr(t_head *a, t_head *b)
{
	ft_reverse_r(a, 'r');
	ft_reverse_r(b, 'r');
	write(1, "rrr\n", 4);
}