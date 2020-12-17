/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   Updated: 2020/12/16 17:06:51 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int		read_map(File *file, char * line)
{
	char	**tmp;
	int		j;

	j = 0;
	write(1,"L",1);
	if (!(tmp = malloc(sizeof(char *) * (ft_strlen(line) + 1))))
		return (0);
	while (*line != '\0')
	{
		tmp[j] = &line[j];
		j++;
	}
	file->tab[file->map_y] = *tmp;
	free(tmp);
	file->tab[file->map_y + 1] = NULL;
	file->map_y++;
	printf("\n%s",file->tab[file->map_y]);
	return (1);
}*/

int		main(int ac, char **av)
{
	File file;
	int aux;
	ini_struct_file(&file);
	aux = read_file_cub(&file, av[1]);
	print_file(&file);
	printf("\nValor = %i", aux);
	printf("\nAC = %i", ac);

	int i;
	i = 0;
	while(i < 8)
	{
		printf("(%i, %i)",file.flags[i], i);
		i++;
	}
	return (0);
}
