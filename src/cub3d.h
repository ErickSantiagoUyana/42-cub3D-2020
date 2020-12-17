/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:03:13 by euyana-b          #+#    #+#             */
/*   Updated: 2020/12/16 17:13:15 by euyana-b         ###   ########.fr       */
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
	int date;
	char **tab;
}File;

int		sum_flags(File *file);
void	ini_struct_file(File *file);
void	print_file(File *file);

int		read_file_cub(File *file, char *f_cub);
int		type(File *file, char *line);
int		t_resolution(File *file, char *line, int k);
int		t_sprites(File *file, char *line, char type, int k);
int		t_floor_ceiling(File *file, char *line, char type, int k);


#endif
