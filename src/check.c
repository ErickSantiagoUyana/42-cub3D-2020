/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:46:17 by mjiam             #+#    #+#             */
/*   Updated: 2020/11/16 21:21:06 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** function returns 1 if --save is found, 0 if no second arg,
** else exits on error
*/

int		arg_checker(t_game *game, int argc, char **argv)
{
	if (argc < 2)
		err_handler(game, "No map given\n");
	if (argc >= 2)
	{
	//	if (file_checker(1, argv[1]) < 0)
	//		err_handler(game, "Invalid map file\n");
		if (argc == 3)
		{
			if (!ft_strcmp(argv[2], "--save"))
				return (1);
			err_handler(game, "Invalid second argument\n");
		}
	}
	return (0);
}