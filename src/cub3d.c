/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   Updated: 2020/12/28 22:33:07 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_tab(File *file);
void	print_file(File *file);

void ft_move(Cubed *cubed)
{
	//write(1,"\n",1);

	double playerCos = cos(degreeToRadians(cubed->player.angle)) * cubed->player.movement;
	double playerSin = sin(degreeToRadians(cubed->player.angle)) * cubed->player.movement;
	double newX = cubed->player.x + playerCos;
	double newY = cubed->player.y + playerSin;
	//Collision test
	printf("\n Floor X %f",floor(newX));
	printf("\n Floor Y %f",floor(newY));

	if (cubed->file.tab[(int)floor(newY)][(int)floor(newX)] - '0' == 0)
	{

		cubed->player.x = newX;
		cubed->player.y = newY;
		printf("\n X %.16f",newX);
		printf("\n Y %.16f",newY);
	}
	else
		write(1,"N",1);
	//write(1,"H",1);

		//mlx_loop(cubed->window.mlx);
	//printf("\nX = %f",cubed->player.x );
	//printf("\nY = %f",cubed->player.y );
	ft_aux(cubed);
}


int		ft_key(int key,Cubed *cubed)
{

	if (key == T_ESC)
	{
		mlx_destroy_window(cubed->window.mlx, cubed->window.win);
		exit(0);
	}
	if (key == T_UP)
		ft_move(cubed);

	return (1);
}

void init_struct_ray(Cubed *cubed)
{
	cubed->screen.width = cubed->file.R[0];
	cubed->screen.height = cubed->file.R[1];
	cubed->rayC.delay = 30;
	cubed->rayC.precision = 64;
	cubed->player.fov = 60;
	//Se debe de modificar con w,e,a,,,
	cubed->player.x = 2;
	cubed->player.y = 2;
	cubed->player.angle = 90;
	cubed->player.movement = 0.3;
	cubed->screen.halfHeight = cubed->screen.width / 2;
	cubed->screen.halfWidth = cubed->screen.height / 2;
	cubed->rayC.incrementAngle = cubed->player.fov / cubed->screen.width;
	cubed->player.halfFov = cubed->player.fov / 2;
}

int		main(int ac, char **av)
{

	Cubed cubed;

	int aux;
	init_struct_file(&cubed.file);
	aux = read_file_cub(&cubed.file, av[1]);
	//print_errors_file(aux);
	//write(1,"0",1);

	//print_file(&cubed.file);
	//print_tab(&cubed.file);
	///////////////////////////////////////////////////////////////////////////
	//Init windows
	cubed.window.mlx = mlx_init();
	//Init window whit screen
	cubed.window.win = mlx_new_window(cubed.window.mlx, cubed.file.R[0], cubed.file.R[1], "cub3D");
	init_struct_ray(&cubed);
	ft_aux(&cubed);

	mlx_key_hook(cubed.window.win,ft_key, &cubed);
	mlx_loop(cubed.window.mlx);

	///////////////////////////////////////////////////////////////////////////
	return (ac);
}
