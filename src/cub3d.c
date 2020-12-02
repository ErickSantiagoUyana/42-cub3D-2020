/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   Updated: 2020/12/02 23:42:40 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int map;
	char **tab;
}File;

int		t_resolution(File *file, char * line)
{
	line++;
	while (*line == ' ')
		line++;
	file->R[0] = ft_atoi(line);
	
	while (*line != ' ')
		line++;
	file->R[1] = ft_atoi(line);

	if (file->R[0] != 0 && file->R[1] != 0)
		return (1);
	
	return (0);
}

int		t_sprites(File *file, char * line, char type)
{
	line++;
	line++;
	while (*line == ' ' )
		line++;
	if (type == 'N')
		file->NO = line;
	else if (type == 'S')
			file->SO = line;
	else if (type == 'W')
			file->WE = line;
	else if (type == 'E')
			file->EA = line;
	else if (type == 's')
			file->S = line;

	if (ft_strlen(line) != 0)
		return (1);
	return (0);
}

int	t_floor_ceiling(File *file, char * line, char type)
{
	int i;

	i = 0;
	while (*line != '\0')
	{
		if (ft_isdigit(*line))
		{	
			if (type == 'F')
				file->F[i] = ft_atoi(line);
			else if (type == 'C')
					file->C[i] = ft_atoi(line);
			while (*line != ',')
				line++;
			i++;
		}
		line++;
	}
	return (1);
}

void type (File *file, char * line)
{

	while (*line == ' ')
		line++;
	
	if (line[0] == 'R')
		file->map += t_resolution(file, line);
	else if (line[0] == 'N' && line[1] == 'O')
			file->map += t_sprites(file, line,'N');
	else if (line[0] == 'S' && line[1] == 'O')
			file->map += t_sprites(file, line,'S');
	else if (line[0] == 'W' && line[1] == 'E')
			file->map += t_sprites(file, line,'W');
	else if (line[0] == 'E' && line[1] == 'A')
			file->map += t_sprites(file, line,'E');
	else if (line[0] == 'S')
			file->map += t_sprites(file, line,'s');
	else if (line[0] == 'F')
			file->map += t_floor_ceiling(file, line,'F');
	else if (line[0] == 'C')
			file->map += t_floor_ceiling(file, line,'C');
	
}

int read_file_cub(File *file, char *f_cub)
{
	int fd;
	char *line;
	file->map = 0;
	fd = open(f_cub, O_RDONLY);
	while (get_next_line(fd,&line) != 0 || file->map != 8)
	{	
		if(ft_strlen(line) > 0)
			type(file, line);
		
	}

	file->tab[0][0] = "asdasd";
	printf("%s", file->tab[0][0]);
	close(fd);
	return (1);
}

void print_file(File *file)
{
	printf("\n%i", file->R[0]);
	printf("\n%i", file->R[1]);
	printf("\n%i", file->F[0]);
	printf("\n%i", file->F[1]);
	printf("\n%i", file->F[2]);
	printf("\n%i", file->C[0]);
	printf("\n%i", file->C[1]);
	printf("\n%i", file->C[2]);
	printf("\n%s", file->NO);
	printf("\n%s", file->SO);
	printf("\n%s", file->WE);
	printf("\n%s", file->EA);
	printf("\n%s", file->S);
}

int		main(int ac, char **av)
{
	File file;
	
	if (read_file_cub(&file, av[1]))
		print_file(&file);
	else
		printf("Error %i", ac);
	

	return (0);
}
