/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 22:18:27 by erick             #+#    #+#             */
/*   Updated: 2019/12/17 11:52:10 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;

	start = 0;
	len = 0;
	if (!s1 || !set)
		return (0);
	while (s1[start] && ft_strchr(set, s1[start]) != 0)
		start++;
	len = ft_strlen(&s1[start]);
	if (len)
		while (s1[start + len - 1]
				&& ft_strchr(set, s1[start + len - 1]) != 0)
			len--;
	return (ft_substr(s1, start, len));
}
