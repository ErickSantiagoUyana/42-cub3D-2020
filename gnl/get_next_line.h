/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:25:52 by euyana-b          #+#    #+#             */
/*   Updated: 2020/12/02 13:25:54 by euyana-b         ###   ########.fr       */
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
