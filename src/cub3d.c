/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b ∫ <euyana-b@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   Updated: 2020/11/18 21:05:22 by euyana-b ∫       ###   ########lyon.fr   */
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

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
int		ft_close(t_all *s, int win)
{
	int	i;

	i = 0;
	while (i < s->map.y)
		free(s->map.tab[i++]);
	free(s->map.tab);
	free(s->tex.n);
	free(s->tex.s);
	free(s->tex.e);
	free(s->tex.w);
	free(s->tex.i);
	if (win == 1)
		mlx_destroy_window(s->mlx.ptr, s->win.ptr);
	free(s->mlx.ptr);
	exit(0);
	return (1);
}

int             key_hook(int key, void *arg)
{
    if (key == W)
        printf("Hello from key_hook!\n");
    if (key == ESC)
        ft_close(arg,1);

    return (1);
}

int     main(void)
{

     t_all	s;
     char    *path = "/Users/erickub/Documents/42-cub3D-2020/src/wood.xpm";
      int    w;
    int     h;

    //w = 64;
    //h = 64;

    s.mlx.ptr = mlx_init();
    s.win.ptr = mlx_new_window(s.win.ptr, 640, 480, "Hello world!");

    if (mlx_xpm_file_to_image(s.mlx.ptr, path,&w,&h) == NULL)
        printf("MAAAL");
    else
    {
       mlx_key_hook(s.win.ptr, key_hook, &s);
    mlx_loop(s.mlx.ptr );
    }

    return(0);
}
