/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:07:05 by euyana-b          #+#    #+#             */
/*   Updated: 2019/12/17 12:14:57 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t strlen;

	strlen = 0;
	if (!(dest && src))
		return (0);
	strlen = ft_strlen(src);
	if (strlen < size)
	{
		ft_memcpy(dest, src, strlen + 1);
	}
	else
	{
		if (size != 0)
		{
			ft_memcpy(dest, src, size - 1);
			dest[size - 1] = '\0';
		}
	}
	return (strlen);
}
