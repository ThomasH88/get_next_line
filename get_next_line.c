/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:39:41 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/15 15:59:32 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>//kjasljfjls

/*int		len_rest(char *str)
{
	int		i;
	int		len;

	i = 2;
	len = 0;
	while (i--)
	{
		while (str && *str && *str == '\n')
			str++;
		if (i == 0)
			while (str && *str)
			{
				str++;
				len++;
			}
		else
			while (str && *str && *str != '\n')
				str++;
	}
	return (len);
}

void	save_strings(char *str, char **line, char **rest, int len)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	i = 2;
	printf("str = %s\n", str);
	while (i--)
	{
		while (str && *str && *str == '\n')
			str++;
		if (i == 0 && len)
			while (str && *str)
			{
				rest[0][j] = *str;
				str++;
				j++;
			}
		else
			while (str && *str && *str != '\n')
			{
				line[0][k] = *str;
				printf("line[0][%d] = %c\n", k, line[0][k]);
				str++;
				k++;
			}
	}
	rest[0][j] = '\0';
	line[0][k] = '\0';
}

int		str_1_split(char *str, char **line, char **rest)
{
	char	*s1;
	char	*s2;
	int		len;

	len = len_rest(str);
	printf("malloc this much = %d\n", len);
	printf("m = %d\n", len_n_word(str, '\n', 1));
	s1 = (char *)malloc(sizeof(char) * (len_n_word(str, '\n', 1) + 1));
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	//s1[len_n_word(str, '\n', 1)] = '\0';
	//s2[len] = '\0';
	if (!s1 || !s2)
		return (-1);
	*line = s1;
	*rest = s2;
	save_strings(str, line, rest, len);
	printf("line 1 = %s\n", *line);
	printf("rest 1 = %s\n", *rest);
	if (len == 0)
		return (0);
	else
		return (1);
}*/
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

void	arr_to_list(char *str, t_list **head)
{
	char	**arr;

	//printf("str = %s\n", str);
	arr = ft_strsplit(str, '\n');
	while (arr && *arr)
	{
		//printf("*arr = %s\n", *arr);
		lstadd_back(head, *arr);
		arr++;
	}
	/*write(1, "\n..............\n", 16);
	lstprint(head);
	write(1, "\n..............\n", 16);*/
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head;
	char			*buff;
	char			*str;
	ssize_t			br;

	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_memset((void *)buff, '\0', BUFF_SIZE + 1);
	str = NULL;
	while ((br = read(fd, buff, BUFF_SIZE)))
	{
		if (br == -1)
			return (-1);
		str = str_concat(str, buff, br);
		//printf("str = %s\n", str);
		if (ft_strchr(str, '\n'))
			arr_to_list(str, &head);
		if (head)
		{
			*line = head->data;
			head = head->next;
			ft_memset((void *)buff, '\0', BUFF_SIZE + 1);
			return (1);
		}
	}
	return (0);
}
