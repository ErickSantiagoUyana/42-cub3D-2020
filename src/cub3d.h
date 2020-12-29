/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:03:13 by euyana-b          #+#    #+#             */
/*   Updated: 2020/12/29 22:03:27 by euyana-b         ###   ########.fr       */
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
}t_file;

typedef struct  s_window
{
	void *mlx;
	void *win;
}t_window;

typedef struct	s_img
{
	void *ptr;
	unsigned int *adr;
	
}t_img;

typedef struct  s_screen
{
	int w;
	int h;
	int h_w;
	int h_h;
	int co_c;
	int co_f;
}t_screen;

typedef struct s_r_casting
{
	double i_ang;
	int pre;
	int delay;
	int r_count;
	double r_x;
	double r_y;
	double r_c;
	double r_s;
	double dis;
	int w_h;
	double r_a;
}t_r_casting;

typedef struct s_player
{
	double fov;
	double h_fov;
	double x;
	double y;
	double angle;
	double move;

}t_player;

typedef struct s_cubed
{
	t_player player;
	t_r_casting rayC;
	t_screen screen;
	t_img img;
	t_window win;
	t_file f;
}t_cubed;

int		sum_flags(t_file *file);
void	init_structs(t_cubed *c3d);
int		read_file_cub(t_file *file, char *f_cub);
//int		type(t_file *file, char *line);
//int		t_resolution(t_file *file, char *line, int k);
//int		t_sprites(t_file *file, char *line, char type, int k);
//int		t_floor_ceiling(t_file *file, char *line, char type, int k);
void	print_errors_file(int i);
void	screen(t_cubed *cubed);
void	move(t_cubed *cubed);
int		keys(int key,t_cubed *cubed);
double  to_radians(double degree);




#endif
