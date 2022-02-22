/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:17:30 by ilefhail          #+#    #+#             */
/*   Updated: 2021/11/24 00:17:32 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Push_swap.h"

char	*ft_strchar(char *str, char c)
{
	char	*s;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		s = ft_calloc(1, i + 1);
	else
		s = ft_calloc(1, i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = str[i];
	return (s);
}

static char	*done(char *chkra, char *buf, int fd, int BUFFER_SIZE)
{
	int	i;
	int	rd;

	i = 0;
	while (buf[i] != '\n')
	{
		i = 0;
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buf[rd] = '\0';
		chkra = ft_strjoin(chkra, buf);
		while (buf[i] != '\n' && buf[i])
			i++;
	}
	return (chkra);
}

char	*get_next_line(int fd, int BUFFER_SIZE)
{
	char		*buf;
	static char	*chkra;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (chkra == NULL)
		chkra = ft_strdup("");
	buf = ft_calloc(1, BUFFER_SIZE + 1);
	chkra = done(chkra, buf, fd, BUFFER_SIZE);
	free(buf);
	if (chkra[0] == '\0')
	{
		free(chkra);
		chkra = NULL;
		return (NULL);
	}
	s = ft_strchar(chkra, '\n');
	chkra = ft_strchr(chkra, '\n');
	return (s);
}
