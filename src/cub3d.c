/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   Updated: 2020/12/18 20:20:23 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		main(int ac, char **av)
{
	File file;
	Window window;

	int aux;


	ini_struct_file(&file);
	aux = read_file_cub(&file, av[1]);
	print_errors_file(aux);
	printf("\nValor de ac %i",ac);
	//print_file(&file);
	//print_tab(&file);
	
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, file.R[0], file.R[1], "cub3D");

	mlx_key_hook(window.win,ft_key, &window);
	

	
	void *img;
	int     img_width;
    int     img_height;
	 if((img = mlx_png_file_to_image(window.mlx, file.SO, &img_width, &img_height)))
	 	ft_putstr_fd("Hola", 1);

	//while (a < 1)
	//{
	//mlx_put_image_to_window(window.mlx, window.win,img,0,0);
	//}
	mlx_loop(window.mlx);
	

	return (0);
}
