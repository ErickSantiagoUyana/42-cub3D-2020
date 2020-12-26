/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:59:59 by euyana-b          #+#    #+#             */
/*   Updated: 2020/12/27 00:43:15 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


double  degreeToRadians(double degree) 
{
	return (degree * M_PI / 180);
}

void drawLine(int x1, int y1,int y2, int color, File *file, Img *img, Window *window)
{

	int aux;
	aux = 0;

	while ( y1 < y2)
	{
		aux = x1 + (y1 * file->R[1]);
		img->adr[aux] = mlx_get_color_value(window->mlx,color);
		y1++;
	}
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}
void rayCasting(Cubed *cubed)
{

while(cubed->rayC.rayCount < cubed->file.R[0])
	{
		//printf("\n Rayo n: %d", rayCount);

		cubed->rayC.ray_x = cubed->player.x;
		cubed->rayC.ray_y = cubed->player.y;
		
		//printf("\nRayAngel sin cos y  precision: %.16f %d", rayAngle, raycasting.precision);
		//printf("\nDegreeToRadians %.16f", (rayAngle * M_PI) / 180);

		cubed->rayC.rayCos = cos(degreeToRadians(cubed->rayC.rayAngle)) / cubed->rayC.precision;
		cubed->rayC.raySin = sin(degreeToRadians(cubed->rayC.rayAngle)) / cubed->rayC.precision;
		//printf("\nRayo cos player : %.16f", rayCos);
		//printf("\nRayo sen player : %.16f", raySin);
		cubed->rayC.wall = 0;
		while (cubed->rayC.wall == 0)
		{
			//write(1,"o",1);
			cubed->rayC.ray_x += cubed->rayC.rayCos;
			cubed->rayC.ray_y += cubed->rayC.raySin;
			cubed->rayC.wall = cubed->file.tab[(int)floor(cubed->rayC.ray_y)][(int)floor(cubed->rayC.ray_x)] - '0';
		}
		//printf("\nRayo x player despues : %.16f", ray_x );
		//printf("\nRayo y player despues : %.16f", ray_y );

		cubed->rayC.distance = sqrt(pow(cubed->player.x - cubed->rayC.ray_x, 2) + pow(cubed->player.y - cubed->rayC.ray_y, 2));
		
		
		//printf("\nAngulo  %.16f", rayAngle);
		//printf("\n This is distancia  %.16f", distance);
		cubed->rayC.distance = cubed->rayC.distance * cos(degreeToRadians(cubed->rayC.rayAngle - cubed->player.angle));
		
		cubed->rayC.wallHeight = floor(cubed->screen.halfHeight / cubed->rayC.distance);
		//printf("\nWall : %d", wallHeight);
		//printf("\nRest : %d", screen.halfHeight - wallHeight);
		drawLine(cubed->rayC.rayCount, 0, cubed->screen.halfHeight - cubed->rayC.wallHeight, BLUE , &cubed->file, &cubed->img, &cubed->window);
		drawLine(cubed->rayC.rayCount, cubed->screen.halfHeight - cubed->rayC.wallHeight, cubed->screen.halfHeight + cubed->rayC.wallHeight, RED, &cubed->file, &cubed->img, &cubed->window);
		drawLine(cubed->rayC.rayCount, cubed->screen.halfHeight + cubed->rayC.wallHeight, cubed->screen.height, GREEN, &cubed->file, &cubed->img, &cubed->window);
		//printf("\nIncrementAngle: %.16f", raycasting.incrementAngle);
		cubed->rayC.rayAngle += cubed->rayC.incrementAngle;
		cubed->rayC.rayCount++;
	}
}