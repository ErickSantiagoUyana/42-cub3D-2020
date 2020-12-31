/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:06:56 by euyana-b          #+#    #+#             */
/*   Updated: 2020/12/31 18:08:08 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//Falta liberar espacio de memoria
void	move(t_cubed *c3d)
{
	double newX;
	double newY;

	newX = c3d->player.x + cos(to_radians(c3d->player.angle)) * c3d->player.move;
	newY = c3d->player.y + sin(to_radians(c3d->player.angle)) * c3d->player.move;
	if (c3d->f.tab[(int)floor(newY)][(int)floor(newX)] - '0' == 0)
	{
		c3d->player.x = newX;
		c3d->player.y = newY;
		
	}
	//printf("\n X %.16f",newX);
	//printf("\n Y %.16f",newY);
	screen(c3d);
}

int	keys(int key, t_cubed *c3d)
{

	if (key == T_ESC)
	{
		mlx_destroy_window(c3d->win.mlx, c3d->win.win);
		exit(0);
	}
	if (key == T_UP)
		move(c3d);
	return (1);
}
