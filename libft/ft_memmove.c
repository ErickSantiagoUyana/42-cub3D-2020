/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:21:50 by euyana-b          #+#    #+#             */
/*   Updated: 2019/12/17 16:24:05 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sour;
	int				i;

	dest = (unsigned char*)dst;
	sour = (unsigned char*)src;
	i = len - 1;
	if (!dst && !src)
		return (0);
	if (*sour == *dest || !len)
		return (dest);
	if (*dest > *sour && (*dest - *sour) < (int)len)
	{
		while (len--)
			dest[len] = sour[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dest);
}
