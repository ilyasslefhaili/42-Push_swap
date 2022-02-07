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
    t_element   *chokara;
    int         c;

    c = a->first->value;
    chokara = a->first;
    a->first = a->first->next;
    free(chokara);
    return c;
}

void    ft_swap(t_head *a)
{
    int first;
    int second;

    second = ft_pop(a);
    first = ft_pop(a);
    ft_push(a, second);
    ft_push(a, first);
}