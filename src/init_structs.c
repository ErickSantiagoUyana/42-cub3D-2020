/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:20:35 by euyana-b          #+#    #+#             */
/*   Updated: 2020/12/29 21:15:30 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_struct_ray(t_cubed *c3d)
{
	c3d->screen.w = c3d->f.R[0];
	c3d->screen.h = c3d->f.R[1];

	c3d->rayC.delay = 30;
	c3d->rayC.pre= 64;
	c3d->rayC.i_ang = c3d->player.fov / c3d->screen.w;

	c3d->player.fov = 60;
	c3d->player.x = 2;
	c3d->player.y = 2;
	c3d->player.angle = 90;
	c3d->player.move = 0.3;
	c3d->player.h_fov = c3d->player.fov / 2;
	
	c3d->screen.h_h = c3d->screen.w / 2;
	c3d->screen.h_w = c3d->screen.h / 2;
	//c3d->screen.co_c = 
	
}

void	init_structs(t_cubed *c3d)
{
	int i;

	i = -1;
	c3d->f.map_y = 0;
	c3d->f.map_y = 0;
	while (i < 8)
		c3d->f.flags[i++] = 0;
	i = 0;
	while (i < 3)
	{
		c3d->f.F[i] = 0;
		c3d->f.C[i] = 0;
		i++;
	}
	c3d->f.R[0] = 0;
	c3d->f.R[1] = 0;
	c3d->f.NO = NULL;
	c3d->f.SO = NULL;
	c3d->f.WE = NULL;
	c3d->f.EA = NULL;
	c3d->f.S = NULL;
	c3d->f.tab = NULL;
	init_struct_ray(c3d);
}
