/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:42:56 by erick             #+#    #+#             */
/*   Updated: 2019/12/18 11:52:26 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_char(int n)
{
	int aux;

	aux = 0;
	if (!n)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		aux++;
	}
	return (aux);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = num_char(n);
	if (n < 0)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	str[i] = '\0';
	if (!n)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i - 1] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}
