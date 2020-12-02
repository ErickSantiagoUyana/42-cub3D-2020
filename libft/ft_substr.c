/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 21:29:10 by erick             #+#    #+#             */
/*   Updated: 2019/12/18 15:52:19 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	int		i;

	i = 0;
	mem = NULL;
	if (!(s))
		return (mem);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(mem = malloc(len + 1 * sizeof(char))))
		return (mem);
	if (start >= 0)
	{
		while (len-- && s[i])
		{
			*(mem + i) = *(s + start + i);
			i++;
		}
	}
	mem[i] = '\0';
	return (mem);
}
