#include "Push_swap.h"
int	ft_checkismin_five(t_element *b)
{
	int i;
	int e;
	int a;

	a = b->value;
	i = 0;
	e = 0;
	while(b)
	{
		if(b->value < a)
		{
			a = b->value;
			e = i;
		}
		b = b->next;
		if(b == NULL)
			break ;
		i++;
	}
	return e;
}


void	fivesort(t_head *a, t_head *b)
{
	int i;
	int j;
	int k;

	while(a->first)
	{
		i = 0;
		j = 0;
		k = ft_checkismin_five(a->first);
		if(k < a->len - k)
		{
			while(i < k)
			{
				ft_rotate(a, 'a');
				i++;
			}
		}
		//printf("i'm number %d\n",a->len - k);
		//if(a->len == 0)
		//	break ;
		else
		{
			while(j < a->len - k)
			{
				ft_reverse_r(a, 'a');
				j++;
			}
		}
		ft_push(b , a, 'b');
		if(a->first->next->next == NULL)
			break ;
	}
	if(a->first->value > a->first->next->value)
		ft_swap(a, 'a');
	i = 1;
	while(i < 4)
	{
		ft_push(a, b, 'a');
		i++;
	}
}
