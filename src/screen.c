/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:59:59 by euyana-b          #+#    #+#             */
/*   Updated: 2021/01/02 10:33:35 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


double  to_radians(double degree)
{
	return (degree * M_PI / 180);
}

void draw(int y1, int y2, t_cubed *c3d, int color)
{

	int aux;
	int x1;

	aux = 0;
	x1 = c3d->ray_c.r_count;
	write(1,"b",1);
	printf("\n x1 = %i,y1 = %i,y2 = %i", x1,y1,y2);
	if(y1 < 0)
		y1 = 0;
	if(y2 > c3d->f.R[1])
		y2 = c3d->f.R[1];
	while (y1 < y2)
	{
		//write(1,"A",1);
		aux = x1 + (y1 * c3d->f.R[1]);
		c3d->img.adr[aux] = mlx_get_color_value(c3d->win.mlx, color);
		y1++;
	}
	//write(1,"A",1);

}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}



void rayCasting(t_cubed *c3d)                                                   
{
	int wall;
	double r_a;
	t_r_casting r_cst;
	r_a = c3d->player.angle - c3d->player.h_fov;
	r_cst.i_ang =  c3d->player.fov / c3d->screen.w;
	//c3d->ray_c.r_count = 0;
	r_cst.pre = 10000;
	
	while(c3d->ray_c.r_count < c3d->f.R[0])
	{
		r_cst.r_x = c3d->player.x;
		r_cst.r_y = c3d->player.y;
		r_cst.r_c = cos(to_radians(r_a)) / r_cst.pre;
		r_cst.r_s = sin(to_radians(r_a)) / r_cst.pre;
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
		//printf("\nrayo %i", r_cst.r_count);
		draw(0, (int)floor(c3d->screen.h_h - r_cst.w_h), c3d, BLUE);
		draw(c3d->screen.h_h - r_cst.w_h, c3d->screen.h_h + r_cst.w_h, c3d, RED);
		draw(c3d->screen.h_h + r_cst.w_h, c3d->screen.h, c3d,GREEN);
		r_a += r_cst.i_ang;
		c3d->ray_c.r_count++;
	}
}

void screen(t_cubed *c3d)
{
	int b;
	int s;
	int e;

	c3d->img.ptr = mlx_new_image(c3d->win.mlx, c3d->f.R[0], c3d->f.R[1]);
	c3d->img.adr = (unsigned int *)mlx_get_data_addr(c3d->img.ptr, &b, &s, &e);
	
	//r_cst.r_count = 0;
	//r_cst.r_x = 0;
	//r_cst.r_y = 0;
	//r_cst.r_c = 0;
	//r_cst.r_s = 0;
	//r_cst.dis = 0;
	//r_cst.w_h = 0;
	c3d->ray_c.r_count = 0;
	rayCasting(c3d);
	mlx_put_image_to_window(c3d->win.mlx, c3d->win.win , c3d->img.ptr , 0, 0);
	free(c3d->img.ptr);
	free(c3d->img.adr);
}
