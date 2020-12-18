/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:10:35 by euyana-b          #+#    #+#             */
/*   Updated: 2020/12/18 13:24:31 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_errors_file(int i)
{
	if (i == -1)
		ft_putstr_fd("Error: -1, The file couldn't open", 1);
	else if (i == -2)
		ft_putstr_fd("Error: -2, Incorrect data type ", 1);
	else if (i == -3)
		ft_putstr_fd("Error: -3, Incorrect resolution data", 1);
	else if (i == -4)
		ft_putstr_fd("Error: -4, Incorrect sprite path data", 1);
	else if (i == -5)
		ft_putstr_fd("Error: -5, Incorrect floor or ceiling data", 1);
	else if (i == -6)
		ft_putstr_fd("Error: -6, Error while reserving memory with malloc", 1);
	else if (i == -7)
		ft_putstr_fd("-7", 1);
	else if (i == -8)
		ft_putstr_fd("-8", 1);
}
