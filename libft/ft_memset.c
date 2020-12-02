/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:12:16 by euyana-b          #+#    #+#             */
/*   Updated: 2019/12/17 11:36:45 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *auxstr;

	auxstr = (unsigned char *)b;
	while (len--)
	{
		*(auxstr++) = (unsigned char)c;
	}
	return (b);
}
