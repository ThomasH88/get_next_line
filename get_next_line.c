/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:54:36 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/17 12:01:55 by tholzheu         ###   ########.fr       */
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
	//ft_strdel(&prev);
	return (new);
}

void	remove_last_new_line(char **rest)
{
	int		j;

	j = 0;
	//printf("xrest = %s\n", *rest);
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

	//printf("restt = %s\n", *rest);
	//printf("\n\nreturn_line...\n");
	if (i)
	{
		//printf("yep\n");
		remove_last_new_line(rest);
	}
	if (!*rest || (tmp = ft_strchr(*rest, '\n')) == NULL)
	{
		//printf("kksjdkfljs\n");
		return (0);
	}
	*tmp = '\0';
	*line = ft_strdup(*rest);
	*tmp = '\n';
	if (tmp + 1 && *(tmp + 1) != '\0')
		*rest = tmp + 1;
	else
		*rest = NULL;
	//printf("line1 = %s\n", *line);
	//printf("restk = %s\n", *rest);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	ssize_t			br;
	char			*buff;
	static char		*rest;

	if (!rest || ft_strchr(rest, '\n') == NULL)
	{
		buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
		while ((br = read(fd, buff, BUFF_SIZE)))//error handling
		{
			if (br == -1)
				return (-1);
			//printf("stuck here\n");
			//printf("rest = %s\n", rest);
			rest = str_concat(rest, buff, br);
			if (return_line(&rest, line, 0))
				return (1);
		}
	}
	if (return_line(&rest, line, 1))
	{
		//printf("I'm herre\n");
		return (1);
	}
	//printf("2rest = %s\n", rest);
	if (rest)
	{
		*line = rest;
		rest = NULL;
		return (1);
	}
	return (0);
}
