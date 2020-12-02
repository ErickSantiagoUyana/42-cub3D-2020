/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:41:19 by erickuyana        #+#    #+#             */
/*   Updated: 2019/12/03 12:07:34 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *straux;

	straux = (unsigned char*)s;
	while (n--)
	{
		if (*straux == (unsigned char)c)
			return (straux);
		straux++;
	}
	return (0);
}
