/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:59:09 by euyana-b          #+#    #+#             */
/*   Updated: 2019/12/03 12:40:08 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*aux;
	int		i;

	i = ft_strlen(s) - 1;
	aux = (char *)s + i;
	if (!c)
		return (aux + 1);
	while (i >= 0)
	{
		if (*aux == c)
			return (aux);
		aux--;
		i--;
	}
	return (0);
}
