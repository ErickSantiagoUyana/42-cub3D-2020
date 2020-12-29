/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:03:13 by euyana-b          #+#    #+#             */
/*   Updated: 2020/12/28 21:38:37 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define T_ESC 53
# define T_W 13
# define T_A 0
# define T_S 1
# define T_D 2
# define T_UP 126
# define T_DOWN 125
# define T_LEFT 123
# define T_RIGHT 124

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

typedef struct s_file
{
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	char *S;
	int R[2];
	int F[3];
	int C[3];
	int flags[8];
	int map_y;
	int map_x;
	char **tab;
}File;

typedef struct  s_window
{
	void *mlx;
	void *win;
}Window;

typedef struct	s_img
{
	void *ptr;
	unsigned int *adr;
	int bpp;
	int sl;
	int end;

}Img;

typedef struct  s_screen
{
	int width;
	int height;
	int halfWidth;
	int halfHeight;
}Screen;

typedef struct s_rayCasting
{
	double incrementAngle;
	int precision;
	int delay;
	int rayCount;
	double ray_x;
	double ray_y;
	double rayCos;
	double raySin;
	int wall;
	double distance;
	int wallHeight;
	double rayAngle;
}RayCasting;

typedef struct s_player
{
	double fov;
	double halfFov;
	double x;
	double y;
	double angle;
	double movement;

}Player;

typedef struct s_cubed
{
	Player player;
	RayCasting rayC;
	Screen screen;
	Img img;
	Window window;
	File file;
}Cubed;

int		sum_flags(File *file);
void	init_struct_file(File *file);

int		read_file_cub(File *file, char *f_cub);
int		type(File *file, char *line);
int		t_resolution(File *file, char *line, int k);
int		t_sprites(File *file, char *line, char type, int k);
int		t_floor_ceiling(File *file, char *line, char type, int k);
void	print_errors_file(int i);

void rayCasting(Cubed *cubed);
double  degreeToRadians(double degree);
void ft_aux(Cubed *cubed);



#endif
