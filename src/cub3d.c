/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   U n_datesd: 2020/12/12 18:09:26 by euyana-b         ###   ########.fr       */
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
	int map_y;
	int map_x;
	int n_dates;
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
		if (ft_isdigit(*line) )
		{

			if (type == 'F')
				file->F[i] = ft_atoi(line);
			else if (type == 'C')
					file->C[i] = ft_atoi(line);
			if (i == 3)
				return (1);
			while (*line != ',')
				line++;
			i++;
		}

		line++;
	}
	return (0);
}

void type (File *file, char * line)
{
	int aux;
	aux = 0;
	while (*line == ' ')
		line++;

	if (line[0] == 'R')
		aux = t_resolution(file, line);
	else if (line[0] == 'N' && line[1] == 'O')
			aux = t_sprites(file, line,'N');
	else if (line[0] == 'S' && line[1] == 'O')
			aux = t_sprites(file, line,'S');
	else if (line[0] == 'W' && line[1] == 'E')
			aux = t_sprites(file, line,'W');
	else if (line[0] == 'E' && line[1] == 'A')
			aux = t_sprites(file, line,'E');
	else if (line[0] == 'S')
			aux= t_sprites(file, line,'s');
	else if (line[0] == 'F')
			aux = t_floor_ceiling(file, line,'F');
	else if (line[0] == 'C')
			aux = t_floor_ceiling(file, line,'C');

	file->n_dates += aux;
	
}
int read_map(File *file, char * line)
{
	char	**tmp;
	int		j;

	j = 0;
	if (!(tmp = malloc(sizeof(char *) * (ft_strlen(line) + 1))))
		return (0);
	
	while (line[j] != '\0')
	{
		tmp[j] = &line[j];
		//write(1,&line[j],1);
		j++;
	}
	write(1,"\n",1);
	file->tab[0] = *tmp;
	free(tmp);
	//file->tab[file->map_y + 1] = NULL;
	//file->map_y++;
	
	return (1);

}
int read_file_cub(File *file, char *f_cub)
{
	int fd;
	char *line;

	if ((fd = open(f_cub, O_RDONLY)) > 0)
	{
		while (get_next_line(fd,&line) != 0)
		{
			if(ft_strlen(line) > 0)
			{
				type(file, line);
				if (file->n_dates == 8)
					break;
			}
		}
		while (get_next_line(fd,&line) != 0)
		{
			if(ft_strlen(line) > 0)
			{
				//read_map(file, line);
				//printf("\n%s", line);
			}

		}
	}
	else
		fd = -1;
	close(fd);
	//printf("(\n%s)",file->tab[0]);

	return (fd);
}

void print_file(File *file)
{
	printf("\nR %i", file->R[0]);
	printf("\nR %i", file->R[1]);
	printf("\nF %i", file->F[0]);
	printf("\nF %i", file->F[1]);
	printf("\nF %i", file->F[2]);
	printf("\nC %i", file->C[0]);
	printf("\nC %i", file->C[1]);
	printf("\nC %i", file->C[2]);
	printf("\nNO %s", file->NO);
	printf("\nSO %s", file->SO);
	printf("\nWE %s", file->WE);
	printf("\nEA %s", file->EA);
	printf("\nS %s", file->S);
}


int		main(int ac, char **av)
{
	File file;
	int aux;


	aux = 0;
	if (( aux = read_file_cub(&file, av[1])) > 0)
	{
		print_file(&file);
		printf("\nValor = %i", aux);

	}
	else
		printf("Error %i", ac);

	printf("numero \n%i",file.n_dates);


	char	**tmp;
	int		j;

	j = 0;
	if (!(tmp = malloc(sizeof(char *) * (10 + 1))))
		return (0);
	tmp[0] = (char*)malloc(10+1);

	tmp[0][0] = 'a';
	write(1,&tmp[0][0],1);

	return (0);
}
