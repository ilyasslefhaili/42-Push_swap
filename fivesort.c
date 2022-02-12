int main(int ac, char **av)
{
	t_head *a = malloc(sizeof(t_head));
	t_head *b = malloc(sizeof(t_head));
	int i;
	int j;
	int k;

	a->lent = 0;
	b->lent = 0;
	j = a->lent;
	b->first = NULL;
	a->first = NULL;
	fillstack(av, ac, a);
	while(a->first)
	{
		i = 0;
		j = 0;
		k = checkismin(a->first);
		if(k < a->lent - k)
		{
			while(i < k)
			{
				ft_rotate(a, 'a');
				i++;
			}
		}
		//printf("i'm number %d\n",a->lent - k);
		//if(a->lent == 0)
		//	break ;
		else
		{
			while(j < a->lent - k)
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
	while(b->first)
		ft_push(a, b, 'a');
	//display_list(a->first);
}
