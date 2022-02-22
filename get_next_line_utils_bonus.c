/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:39:23 by ilefhail          #+#    #+#             */
/*   Updated: 2021/11/26 14:40:41 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Push_swap.h"

char	*ft_strdup(char	*src)
{
	char	*pstr;
	int		i;

	i = 0;
	pstr = malloc((ft_strlen(src) + 1) * sizeof (char));
	if (pstr == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		pstr[i] = src[i];
		i++;
	}
	pstr[i] = '\0';
	return (pstr);
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *str, int c)
{
	char		*reslt;
	int			i;

	i = 0;
	while (i < ft_strlen(str) + 1)
	{
		if (str[i] == c)
		{
			reslt = ft_strdup(&str[i + 1]);
			free(str);
			return (reslt);
		}
		i++;
	}
	free(str);
	return (NULL);
}

void	ft_bzero(void *str, size_t r)
{
	unsigned char	*pointer;
	size_t			i;

	i = 0;
	pointer = (unsigned char *)str;
	while (i < r)
	{
		pointer[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	void	*dest;

	i = 0;
	dest = malloc(count * size);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, count * size);
	return (dest);
}
