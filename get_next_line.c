/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:39:41 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/10 22:36:05 by tholzheu         ###   ########.fr       */
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

int		get_next_line(const int fd, char **line)
{
	char			*buf;
	ssize_t			br;
	char			*file;
	static char		**arr;

	if (!line)
		return (-1);
	if (arr == NULL)
	{
		if (!(buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
			return (-1);
		file = NULL;
		while ((br = read(fd, buf, BUFF_SIZE)))
		{
			if (br == -1)
				return (-1);
			file = str_concat(file, buf, br);
		}
		arr = ft_strsplit((char const *)file, '\n');
		ft_strdel(&buf);
		ft_strdel(&file);
	}
	if (*arr == NULL)
		return (0);
	*line = *arr;
	(void)*(arr)++;
	return (1);
}
