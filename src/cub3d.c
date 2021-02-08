/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   Updated: 2021/02/08 20:00:11 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cubed c3d;
	
	init_struct_file(&c3d);
	print_errors_file(read_file_cub(&c3d.f, av[1]));
	init_struct_screen(&c3d);
	init_struct_player(&c3d);
	
	//Init windows
	c3d.win.mlx = mlx_init();
	c3d.win.win = mlx_new_window(c3d.win.mlx, c3d.screen.w, c3d.screen.h, "cub3D");
	screen(&c3d);
	mlx_key_hook(c3d.win.win,keys, &c3d);
	mlx_loop(c3d.win.mlx);
	return (ac);
}
