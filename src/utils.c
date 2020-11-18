/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:55:51 by kbarahon          #+#    #+#             */
/*   Updated: 2020/11/18 14:59:20 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (str1[i] - str2[i]);
		else
			i++;
	}
	return (str1[i] - str2[i]);
}
