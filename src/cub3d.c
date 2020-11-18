/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   Updated: 2020/11/18 16:47:46 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//#include <mlx.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int     main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
	int i;
	
	i = 10;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
    img.img = mlx_new_image(mlx, 60, 60);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	
	mlx_hook(s.win.ptr, 2, 0, ft_key, &s);
	mlx_hook(s.win.ptr, 17, 0, ft_close, &s);
	while ( i < 0)
	{
		my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);
    	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		write(1,"L",1);
		i--;
	}


    mlx_loop(mlx);
}
