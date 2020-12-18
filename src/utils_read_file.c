/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:48:30 by euyana-b          #+#    #+#             */
/*   Updated: 2020/12/18 17:04:42 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		sum_flags(File *file)
{
	int i;
	int aux;

	i = 0;
	aux = 0;
	while (i < 8)
	{
		aux += file->flags[i];
		i++;
	}
	return (aux);
}

void	ini_struct_file(File *file)
{
	int i;

	i = -1;
	file->map_y = 0;
	file->map_y = 0;
	while (i < 8)
		file->flags[i++] = 0;
	i = 0;
	while (i < 3)
	{
		file->F[i] = 0;
		file->C[i] = 0;
		i++;
	}
	file->R[0] = 0;
	file->R[1] = 0;
	file->NO = NULL;
	file->SO = NULL;
	file->WE = NULL;
	file->EA = NULL;
	file->S = NULL;
	file->tab = NULL;
}

void	print_file(File *file)
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

void	print_tab(File *file)
{
	int i;

	i = 0;
	while (i < file->map_y)
	{
		printf("\n%s", file->tab[i]);
		i++;
	}
}
