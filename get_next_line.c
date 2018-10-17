/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:54:36 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/17 12:33:34 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_concat(char *prev, char *buf, ssize_t n)
{
	char	*new;
	int		i;
	int		j;

	if (prev)
		j = ft_strlen(prev);
	else
		j = 0;
	new = (char *)malloc(sizeof(char) * (j + n + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (prev && prev[i])
	{
		new[i] = prev[i];
		i++;
	}
	while ((--n) >= 0)
		new[i++] = buf[j++];
	new[i] = '\0';
	ft_strdel(&prev);
	return (new);
}

void	remove_last_new_line(char **rest)
{
	int		j;

	j = 0;
	if (!rest || !*rest)
		return ;
	while (rest[0][j])
		j++;
	if (rest[0][j - 1] == '\n')
		rest[0][j - 1] = '\0';
}

int		return_line(char **rest, char **line, int i)
{
	char	*tmp;
	char	*new;

	if (i)
		remove_last_new_line(rest);
	if (!*rest || (tmp = ft_strchr(*rest, '\n')) == NULL)
		return (0);
	*tmp = '\0';
	*line = ft_strdup(*rest);
	*tmp = '\n';
	new = *rest;
	if (tmp + 1 && *(tmp + 1) != '\0')
		*rest = ft_strdup(tmp + 1);
	else
		*rest = NULL;
	ft_strdel(&new);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	ssize_t			br;
	char			buff[BUFF_SIZE];
	static char		*rest;

	if (!rest || ft_strchr(rest, '\n') == NULL)
	{
		//buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
		while ((br = read(fd, buff, BUFF_SIZE)))//error handling
		{
			if (br == -1)
				return (-1);
			rest = str_concat(rest, buff, br);
			if (return_line(&rest, line, 0))
				return (1);
		}
		//ft_strdel(&buff);
	}
	if (return_line(&rest, line, 1))
		return (1);
	if (rest)
	{
		*line = rest;
		rest = NULL;
		return (1);
	}
	return (0);
}
