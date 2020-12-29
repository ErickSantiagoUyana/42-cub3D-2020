/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:59:59 by euyana-b          #+#    #+#             */
/*   Updated: 2020/12/29 23:32:12 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


double  to_radians(double degree)
{
	return (degree * M_PI / 180);
}

void draw(int x1, int y1, int y2, t_cubed *c3d, int color)
{

	int aux;
	aux = 0;
	//int x1;

	//x1 = c3d->rayC.r_count;

	while ( y1 < y2)
	{
		aux = x1 + (y1 * c3d->f.R[1]);
		c3d->img.adr[aux] = mlx_get_color_value(c3d->win.mlx, color);
		y1++;
	}
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}



void rayCasting(t_cubed *c3d)
{
	int wall;
	
	c3d->rayC.r_a = c3d->player.angle - c3d->player.h_fov;
	wall = 0;
	write(1,"0",1);
	c3d->rayC.r_count = 0;

	while(c3d->rayC.r_count < c3d->f.R[0])
	{
		c3d->rayC.r_x = c3d->player.x;
		c3d->rayC.r_y = c3d->player.y;
		c3d->rayC.r_c = cos(to_radians(c3d->rayC.r_a)) / c3d->rayC.pre;
		c3d->rayC.r_s = sin(to_radians(c3d->rayC.r_a)) / c3d->rayC.pre;         
		while (wall == 0)
		{
			c3d->rayC.r_x += c3d->rayC.r_c;
			c3d->rayC.r_y += c3d->rayC.r_s;
			wall = c3d->f.tab[(int)floor(c3d->rayC.r_y)][(int)floor(c3d->rayC.r_x)] - '0';
		}
		c3d->rayC.dis = sqrt(pow(c3d->player.x - c3d->rayC.r_x, 2) + pow(c3d->player.y - c3d->rayC.r_y, 2));
		c3d->rayC.dis = c3d->rayC.dis * cos(to_radians(c3d->rayC.r_a - c3d->player.angle));
		c3d->rayC.w_h = floor(c3d->screen.h_w / c3d->rayC.dis);
		//draw(0, c3d->screen.h_h - c3d->rayC.w_h, c3d, BLUE);
		draw(c3d->rayC.r_count, 0, c3d->screen.h_h - c3d->rayC.w_h, c3d, BLUE);

		//draw(c3d->screen.h_h - c3d->rayC.w_h, c3d->screen.h_h + c3d->rayC.w_h, c3d, BLUE);
		//draw(c3d->screen.h_h + c3d->rayC.w_h, c3d->screen.h, c3d, BLUE);

		c3d->rayC.r_a += c3d->rayC.i_ang;
		c3d->rayC.r_count++;
	}
	mlx_put_image_to_window(c3d->win.mlx, c3d->win.win , c3d->img.ptr , 0, 0);

}

void screen(t_cubed *c3d)
{
	//Hay que guardar todo en una sola
	//cubed.rayC.r_a = cubed.player.angle - cubed.player.halfFov;
	int b;
	int s;
	int e;

	c3d->img.ptr = mlx_new_image(c3d->win.mlx, c3d->f.R[0], c3d->f.R[1]);
	c3d->img.adr = (unsigned int *)mlx_get_data_addr(c3d->img.ptr, &b, &s, &e);
	
	c3d->rayC.r_count = 0;
	c3d->rayC.r_x = 0;
	c3d->rayC.r_y = 0;
	c3d->rayC.r_c = 0;
	c3d->rayC.r_s = 0;
	c3d->rayC.dis = 0;
	c3d->rayC.w_h = 0;

	rayCasting(c3d);
	free(c3d->img.ptr);
	free(c3d->img.adr);
}
