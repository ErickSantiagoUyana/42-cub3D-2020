/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   Updated: 2020/12/29 22:36:54 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{

	t_cubed c3d;

	init_structs(&c3d);
	print_errors_file(read_file_cub(&c3d.f, av[1]));

	//Init windows
	c3d.win.mlx = mlx_init();
	//Init window whit screen
	c3d.win.win = mlx_new_window(c3d.win.mlx, c3d.f.R[0], c3d.f.R[1], "cub3D");
	screen(&c3d);
	mlx_key_hook(c3d.win.win,keys, &c3d);
	mlx_loop(c3d.win.mlx);
	return (ac);
}
