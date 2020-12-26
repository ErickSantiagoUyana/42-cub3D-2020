/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   Updated: 2020/12/27 00:57:03 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_tab(File *file);
void	print_file(File *file);

void ft_move(Cubed *cubed)
{
	double playerCos = cos(degreeToRadians(cubed->player.angle)) * cubed->player.movement;
	double playerSin = sin(degreeToRadians(cubed->player.angle)) * cubed->player.movement;
	double newX = cubed->player.x + playerCos;
	double newY = cubed->player.y + playerSin;
	write(1,"L",1);
	//Collision test
	if (cubed->file.tab[(int)floor(newY)][(int)floor(newX)] - '0' == 0)
	{
		write(1,"M",1);

		cubed->player.x = newX;
		cubed->player.y = newY;
	}
		//mlx_loop(cubed->window.mlx);

	write(1,"u",1);
}

int		ft_key(int key,Cubed *cubed)
{
	
	if (key == T_ESC)
	{
		mlx_destroy_window(cubed->window.mlx, cubed->window.win);
		exit(0);
	}
	if (key == T_UP)
	{
		ft_move(cubed);
	}
	return (1);
}

int		main(int ac, char **av)
{
			write(1,"F",1);

	Cubed cubed;
	int aux;

	ini_struct_file(&cubed.file);
	aux = read_file_cub(&cubed.file, av[1]);
	print_errors_file(aux);
	printf("\nValor de ac %i",ac);
	//print_file(&file);
	//print_tab(&file);
	
	
	///////////////////////////////////////////////////////////////////////////
	
	//Init windows
	cubed.window.mlx = mlx_init();

	//Init window whit screen
	cubed.window.win = mlx_new_window(cubed.window.mlx, cubed.file.R[0], cubed.file.R[1], "cub3D");

	//Create new img 
	cubed.img.ptr = mlx_new_image(cubed.window.mlx, cubed.file.R[0], cubed.file.R[1]);
	cubed.img.adr = (unsigned int *)mlx_get_data_addr(cubed.img.ptr, &cubed.img.bpp, &cubed.img.sl, &cubed.img.end);


	//Hay que guardar todo en una sola

	

	cubed.screen.width = cubed.file.R[0];
	cubed.screen.height = cubed.file.R[1];
	cubed.rayC.delay = 30;

	cubed.rayC.precision = 64;
	cubed.rayC.incrementAngle = 0;

	cubed.player.fov = 60;
	cubed.player.halfFov = 0;
	cubed.player.x = 2;
	cubed.player.y = 2;
	cubed.player.angle = 90;
	cubed.player.movement = 0.3;


	cubed.screen.halfHeight = cubed.screen.width / 2;
	cubed.screen.halfWidth = cubed.screen.height / 2;

	cubed.rayC.incrementAngle = cubed.player.fov / cubed.screen.width;
	cubed.player.halfFov = cubed.player.fov / 2;
	
	cubed.rayC.rayAngle = cubed.player.angle - cubed.player.halfFov;

	cubed.rayC.rayCount = 0;
	cubed.rayC.wall = 0;
	cubed.rayC.ray_x = 0;
	cubed.rayC.ray_y = 0;
	cubed.rayC.rayCos = 0;
	cubed.rayC.raySin = 0;
	cubed.rayC.distance = 0;
	cubed.rayC.wallHeight = 0;

	rayCasting(&cubed);
	//color = create_trgb(0,cubed.file.C[0],file.C[1],file.C[2]);
		write(1,"S",1);

		mlx_key_hook(cubed.window.win,ft_key, &cubed);

	mlx_put_image_to_window(cubed.window.mlx, cubed.window.win , cubed.img.ptr , 0, 0);
	free(cubed.img.ptr);
	free(cubed.img.adr);
	//mlx_key_hook(cubed.window.win,ft_key, &cubed);

	mlx_loop(cubed.window.mlx);
	return (1);
}
