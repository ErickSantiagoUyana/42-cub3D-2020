/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:24:45 by kbarahon          #+#    #+#             */
/*   Updated: 2020/07/07 11:24:50 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(char **line, char **s)
{
	int			len;
	char		*temp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		temp = ft_strdup(&(*s)[len + 1]);
		free(*s);
		*s = temp;
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

static int	get_out(char **line, int fd, int l_read, char **s)
{
	if (l_read < 0)
		return (-1);
	else if (l_read == 0 && s[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (get_line(line, &s[fd]));
}

int			get_next_line(int fd, char **line)
{
	int			l_read;
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	static char	*s[FD_SIZE];

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	while ((l_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[l_read] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (get_out(line, fd, l_read, s));
}
