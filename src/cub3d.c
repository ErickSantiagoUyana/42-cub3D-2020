/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   Updated: 2020/12/23 15:49:26 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 typedef struct  t_screen
{
	int width;
	int height;
	int halfWidth;
	int halfHeight;
}Screen;

typedef struct t_render{
	int delay;
}Render;

typedef struct t_rayCasting
{
	double incrementAngle;
	int precision;
}RayCasting;

typedef struct t_player
{
	double fov;
	double halfFov;
	double x;
	double y;
	double angle;
}Player;


void	print_tab(File *file);
void	print_file(File *file);

int		ft_key(int key,Window *window)
{
	
	if (key == T_ESC)
	{
		mlx_destroy_window(window->mlx, window->win);
		exit(0);
	}
	return (1);
}

double  degreeToRadians(int degree) 
{
	return (degree * M_PI / 180);
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
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
int		main(int ac, char **av)
{
	File file;
	Img img;
	int aux;

	ini_struct_file(&file);
	aux = read_file_cub(&file, av[1]);
	print_errors_file(aux);
	printf("\nValor de ac %i",ac);
	//print_file(&file);
	//print_tab(&file);
	
	
	///////////////////////////////////////////////////////////////////////////
	Window window;
	//Init windows
	window.mlx = mlx_init();

	//Init window whit screen
	window.win = mlx_new_window(window.mlx, file.R[0], file.R[1], "cub3D");

	//Create new img 
	img.ptr = mlx_new_image(window.mlx, file.R[0], file.R[1]);
	int bpp, sl, end;
	img.adr = (unsigned int *)mlx_get_data_addr(img.ptr, &bpp, &sl, &end);


	mlx_key_hook(window.win,ft_key, &window);

	Screen screen;
	Render render;
	RayCasting raycasting;
	Player player;

	screen.width = file.R[0];
	screen.height = file.R[1];
	render.delay = 30;

	raycasting.precision = 64;
	raycasting.incrementAngle = 0;

	player.fov = 60;
	player.halfFov = 0;
	player.x = 2;
	player.y = 2;
	player.angle = 90;


	screen.halfHeight = screen.width / 2;
	screen.halfWidth = screen.height / 2;

	raycasting.incrementAngle = player.fov / screen.width;
	player.halfFov = player.fov / 2;
	
	double rayAngle = player.angle - player.halfFov;

	int rayCount;
	double ray_x, ray_y;
	double rayCos, raySin;
	int wall;
	double distance;
	int wallHeight;
	
	rayCount = 0;
	wall = 0;
	ray_x = 0;
	ray_y = 0;
	rayCos = 0;
	raySin = 0;
	distance = 0;
	wallHeight = 0;

	int i;
	i = 0;
	int map[10][10] = {{1,1,1,1,1,1,1,1,1,1}, {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,1,1,0,1,0,0,1},
        {1,0,0,1,0,0,1,0,0,1},
        {1,0,0,1,0,0,1,0,0,1},
        {1,0,0,1,0,1,1,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}};
	
	while(rayCount < file.R[0])
	{
		printf("\n Rayo n: %d", rayCount);

		ray_x = player.x;
		ray_y = player.y;
		
		rayCos = cos(degreeToRadians(rayAngle)) / raycasting.precision;
		raySin = sin(degreeToRadians(rayAngle)) / raycasting.precision;
		printf("\nRayo cos player : %f", rayCos);
		wall = 0;
		while (wall == 0)
		{
			//write(1,"o",1);
			ray_x += rayCos;
			ray_y += raySin;
			wall = map[(int)floor(ray_x)][(int)floor(ray_y)];
		}
		printf("\nRayo x player despues : %f", ray_x );
		distance = sqrt(pow(player.x - ray_x, 2) + pow(player.y - ray_y, 2));
		printf("\nAngulo  %f", rayAngle);
		printf("\n This is distancia  %f", distance);
		distance = distance * cos(degreeToRadians(rayAngle - player.angle));
		wallHeight = floor(screen.halfHeight / distance);
		printf("\nWall : %d", wallHeight);
		printf("\nRest : %d", screen.halfHeight - wallHeight);
		drawLine(rayCount, 0, screen.halfHeight - wallHeight, BLUE, &file, &img, &window);
		drawLine(rayCount, screen.halfHeight - wallHeight, screen.halfHeight + wallHeight, RED, &file, &img, &window);
		drawLine(rayCount, screen.halfHeight + wallHeight, screen.height, GREEN, &file, &img, &window);
		printf("\nIncrementAngle: %f", raycasting.incrementAngle);
		rayAngle += raycasting.incrementAngle;
		rayCount++;
	}
	mlx_put_image_to_window(window.mlx, window.win , img.ptr , 0, 0);
	mlx_loop(window.mlx);
	return (0);
}
