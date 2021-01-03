/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:06:56 by euyana-b          #+#    #+#             */
/*   Updated: 2021/01/03 20:55:55 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//Falta liberar espacio de memoria
void	move(t_cubed *c3d, int type)
{
	double newX;
	double newY;

	if(type == 1)
	{
	newX = c3d->player.x + cos(to_radians(c3d->player.angle)) * c3d->player.move;
	newY = c3d->player.y + sin(to_radians(c3d->player.angle)) * c3d->player.move;
	}
	if(type == 2)
	{
	newX = c3d->player.x - cos(to_radians(c3d->player.angle)) * c3d->player.move;
	newY = c3d->player.y - sin(to_radians(c3d->player.angle)) * c3d->player.move;
	}
	if(type == 3)
		c3d->player.angle -= c3d->player.rot;
	if(type == 4)
		c3d->player.angle += c3d->player.rot;

	if (c3d->f.tab[(int)floor(newY)][(int)floor(newX)] - '0' == 0 && type < 3)
	{
		c3d->player.x = newX;
		c3d->player.y = newY;
		
	}
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
		move(c3d,1);
	if (key == T_DOWN)
		move(c3d,2);
	if (key == T_LEFT)
		move(c3d,3);
	if (key == T_RIGHT)
		move(c3d,4);
	return (1);
}
