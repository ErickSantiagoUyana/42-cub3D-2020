/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:59:59 by euyana-b          #+#    #+#             */
/*   Updated: 2021/01/03 21:45:48 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw(int y1, int y2, t_cubed *c3d, int color)
{
	int aux;
	int x1;

	aux = 0;
	x1 = c3d->ray_c.r_count;
	if(y1 < 0)
		y1 = 0;
	if(y2 > c3d->screen.h)
		y2 = c3d->screen.h;
	while (y1 < y2)
	{
		aux = x1 + (y1 * c3d->screen.h);
		c3d->img.adr[aux] = mlx_get_color_value(c3d->win.mlx, color);
		y1++;
	}
}

void rayCasting(t_cubed *c3d)
{
	int wall;
	double r_a;
	t_r_casting r_cst;
	
	r_a = c3d->player.angle - c3d->player.h_fov;
	r_cst.i_ang =  c3d->player.fov / c3d->screen.w;
	c3d->ray_c.r_count = 0;
	while(c3d->ray_c.r_count < c3d->screen.w)
	{
		r_cst.r_x = c3d->player.x;
		r_cst.r_y = c3d->player.y;
		r_cst.r_c = cos(to_radians(r_a)) / 1000;
		r_cst.r_s = sin(to_radians(r_a)) / 1000;
		wall = 0;
		while (wall == 0)
		{
			r_cst.r_x += r_cst.r_c;
			r_cst.r_y += r_cst.r_s;
			wall = c3d->f.tab[(int)floor(r_cst.r_y)][(int)floor(r_cst.r_x)] - '0';
		}
		r_cst.dis = sqrt(pow(c3d->player.x - r_cst.r_x, 2) + pow(c3d->player.y - r_cst.r_y, 2));
		r_cst.dis = r_cst.dis * cos(to_radians(r_a - c3d->player.angle));
		r_cst.w_h = floor(c3d->screen.h_h / r_cst.dis);
		draw(0, (int)floor(c3d->screen.h_h - r_cst.w_h), c3d, c3d->screen.co_c);
		draw(c3d->screen.h_h - r_cst.w_h, c3d->screen.h_h + r_cst.w_h, c3d, RED);
		draw(c3d->screen.h_h + r_cst.w_h, c3d->screen.h, c3d,c3d->screen.co_f);
		r_a += r_cst.i_ang;
		c3d->ray_c.r_count++;
	}
}

void screen(t_cubed *c3d)
{
	int b;
	int s;
	int e;

	c3d->img.ptr = mlx_new_image(c3d->win.mlx, c3d->screen.w, c3d->screen.h);
	c3d->img.adr = (unsigned int *)mlx_get_data_addr(c3d->img.ptr, &b, &s, &e);
	c3d->ray_c.r_count = 0;
	rayCasting(c3d);
	mlx_put_image_to_window(c3d->win.mlx, c3d->win.win , c3d->img.ptr , 0, 0);
	free(c3d->img.ptr);
	free(c3d->img.adr);
}
