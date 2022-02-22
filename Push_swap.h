/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:27:40 by ilefhail          #+#    #+#             */
/*   Updated: 2022/02/07 11:27:41 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct element {
	int				value;
	struct element	*next;
	int				index;
}t_element;
typedef struct head {
	t_element	*first;
	int			len;
}t_head;
typedef struct min_max{
	int	min;
	int	max;
	int	thep;
}t_min_max;
void	ft_free(t_head *a);
int		ft_atoi(const char *str);
void	error(void);
int		ft_checkismax(t_element *b);
int		checkismin(t_element *b);
void	fivesort(t_head *a, t_head *b);
void	ft_bable(int *a, int ac);
void	ft_index(t_element *a, int ac);
void	sorting(t_head *a, t_head *b);
void	ready_to_push(t_head *a, t_head *b, t_min_max nx, int *k);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_push_fill(t_head *a, int nmbr);
void	ft_arr(int *arr, int nbr, int e);
void	fillstack(char **av, int ac, t_head *a);
int		ft_strlen(const char *s);
void	checknumber(char **av);
void	ft_swap(t_head *a, char c);
int		ft_pop(t_head *a);
void	ft_push(t_head *a, t_head *b, char c);
void	ft_rotate(t_head *a, char c);
void	ft_reverse_r(t_head *a, char c);
void	check_is_str_empty(char **av, int ac);
void	check_if_sort(t_element *a, int ac);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char	*src);
char	*ft_strjoin(char const	*s1, char const	*s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *str, int c);
char	*get_next_line(int fd, int BUFFER_SIZE);
void	ft_ss(t_head *a, t_head *b, int c);
void	ft_rr(t_head *a, t_head *b, int c);
void	ft_rrr(t_head *a, t_head *b, int c);


#endif
