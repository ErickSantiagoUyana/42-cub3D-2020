/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 09:47:30 by cafernan          #+#    #+#             */
/*   Updated: 2020/07/02 12:43:19 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_SIZE
#  define FD_SIZE 4096
# endif

int				get_next_line(int fd, char **line);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
