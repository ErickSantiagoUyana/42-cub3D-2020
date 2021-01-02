/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   Updated: 2021/01/01 21:10:24 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	print_tab(t_file *file);
void init_struct_ray(t_cubed *c3d);

int	main(int ac, char **av)
{

	t_cubed c3d;
	
	init_structs(&c3d);
	
	//init_struct_ray(&c3d);

	print_errors_file(read_file_cub(&c3d.f, av[1]));
	//Init windows
	c3d.win.mlx = mlx_init();

	c3d.screen.w = c3d.f.R[0];
	c3d.screen.h = c3d.f.R[1];
	c3d.screen.h_h = c3d.screen.w / 2;
	c3d.screen.h_w = c3d.screen.h / 2;

	c3d.player.fov = 60;
	c3d.player.h_fov = c3d.player.fov / 2;
	c3d.player.x = 2;
	c3d.player.y = 2;
	c3d.player.angle = 90;
	c3d.player.move = 0.3;
	c3d.player.rot = 5.0;
	c3d.player.h_fov = c3d.player.fov / 2;
	
	c3d.win.win = mlx_new_window(c3d.win.mlx, c3d.f.R[0], c3d.f.R[1], "cub3D");
	screen(&c3d);
	mlx_key_hook(c3d.win.win,keys, &c3d);
	mlx_loop(c3d.win.mlx);
	return (ac);
}
