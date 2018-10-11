/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:39:41 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/10 21:12:01 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>//askjfljf

char	*str_concat(char *prev, char *buf, ssize_t n)
{
	char	*new;
	int		i;
	int		j;

	if (prev)
		j = ft_strlen(prev);
	else
		j = 0;
	printf("malloc = %ld\n", j + n + 1);
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

	if (arr == NULL)
	{
		buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		if (!buf)
			return (-1);
		file = NULL;
		ft_strclr(buf);
		while ((br = read(fd, buf, BUFF_SIZE)))
		{
			//printf("bytes read = %ld\n", br);
			//printf("buf before clear = %s\n", buf);
			if (br == -1)
				return (-1);
			file = str_concat(file, buf, br);
			ft_strclr(buf);
			//printf("buf after clear = %s\n", buf);
			//printf("file progress = %s\n\n", file);
		}
		ft_strdel(&buf);
		//printf("file complete = %s\n", file);
		arr = ft_strsplit((char const *)file, '\n');
		ft_strdel(&file);
	}
	*line = *arr;
	if (*line == NULL)
		return (0);
	(void)*(arr)++;
	//printf("line = %s\n", *line);
	return (1);
}
