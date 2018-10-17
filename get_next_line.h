/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:26:14 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/17 14:30:03 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFF_SIZE 32

int		get_next_line(const int fd, char **line);
char	*str_concat(char *prev, char *buf, ssize_t n);
void	remove_last_new_line(char **rest);
int		return_line(char **rest, char **line, int i);
int		return_last_line(char **line, char **rest);

#endif
