/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:47:48 by euyana-b          #+#    #+#             */
/*   Updated: 2020/12/29 21:18:01 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		read_map(t_file *file, char *line)
{
	char	**tmp;
	int		j;

	j = -1;
	tmp = NULL;
	if (!(tmp = malloc(sizeof(char *) * (file->map_y + 2))))
		return (-6);
	while (++j < file->map_y)
		tmp[j] = file->tab[j];
	tmp[file->map_y] = line;
	tmp[file->map_y + 1] = NULL;
	if (file->map_y > 0)
		free(file->tab);
	file->tab = tmp;
	file->map_y++;
	return (1);
}

int		t_floor_ceiling(t_file *file, char *line, char type, int k)
{
	int i;
	int aux;

	aux = 0;
	i = 0;
	while (*line != '\0')
	{
		if (ft_isdigit(*line) || *line == '-')
		{
			aux = ft_atoi(line);
			if ((aux >= 0 && aux <= 255) && i < 4)
			{
				if (type == 'F')
					file->F[i] = ft_atoi(line);
				else if (type == 'C')
					file->C[i] = ft_atoi(line);
				i++;
			}
			else
				return (-5);
			while (*line != ',' && *line != '\0')
				line++;
		}
		else
			line++;
	}
	file->flags[k] = 1;
	return (1);
}

int		t_sprites(t_file *file, char *line, char type, int k)
{
	while (*line != '\0')
	{
		if (*line == '.')
		{
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
			file->flags[k] = 1;
			return (1);
		}
		line++;
	}
	return (-4);
}

int		t_resolution(t_file *file, char *line, int k)
{
	int i;
	int aux;

	aux = 0;
	i = 0;
	while (*line != '\0')
	{
		if (ft_isdigit(*line) || *line == '-')
		{
			aux = ft_atoi(line);
			if (aux > 0 && i < 2)
			{
				file->R[i] = aux;
				i++;
			}
			else
				return (-3);
			while (*line != ' ' && *line != '\0')
				line++;
		}
		else
			line++;
	}
	if ((file->R[0] * file->R[1]) > 0)
		file->flags[k] = 1;
	else
		return (-3);
	return (1);
}

int		type(t_file *file, char *line)
{
	int aux;

	aux = 0;
	while (*line != '\0')
	{
		if (line[0] == 'R' && file->flags[0] == 0)
			return (t_resolution(file, line, 0));
		else if (line[0] == 'N' && line[1] == 'O' && file->flags[1] == 0)
			return (t_sprites(file, line, 'N', 1));
		else if (line[0] == 'S' && line[1] == 'O' && file->flags[2] == 0)
			return (t_sprites(file, line, 'S', 2));
		else if (line[0] == 'W' && line[1] == 'E' && file->flags[3] == 0)
			return (t_sprites(file, line, 'W', 3));
		else if (line[0] == 'E' && line[1] == 'A' && file->flags[4] == 0)
			return (t_sprites(file, line, 'E', 4));
		else if (line[0] == 'S' && file->flags[5] == 0)
			return (t_sprites(file, line, 's', 5));
		else if (line[0] == 'F' && file->flags[6] == 0)
			return (t_floor_ceiling(file, line, 'F', 6));
		else if (line[0] == 'C' && file->flags[7] == 0)
			return (t_floor_ceiling(file, line, 'C', 7));
		line++;
	}
	return (-2);
}

int		read_file_cub(t_file *file, char *f_cub)
{
	int		fd;
	int		aux;
	char	*line;

	aux = -1;
	line = NULL;
	if ((fd = open(f_cub, O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &line) != 0)
		{
			if (ft_strlen(line) > 0)
			{
				if (sum_flags(file) != 8)
					aux = type(file, line);
				else
					aux = read_map(file, line);
				if (aux < 0)
						return (aux);
			}
		}
	}
	//free(line);
	close(fd);
	return (aux);
}
