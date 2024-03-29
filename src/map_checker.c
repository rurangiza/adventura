/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:05:41 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/27 12:28:12 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Verify whether the map check all necessary conditions
 *
 * - valid characters (0, 1, C, E, P)
 * - surrounded by walls
 * - at least one : C, E, P
 * - map is rectangular
 * - no duplicates of E or P
 * - valid path
*/

#include "so_long.h"

int	map_checker(t_game *game)
{
	int		row;
	int		col;

	if (!game)
		return (error_msg(0, "path_finder.c : no GAME struct"));
	game->map = ft_split_fd(game->map_filepath, '\n');
	if (game->map == NULL)
		return (error_msg(0, "couldn't store the map in the matrix"));
	game->map_height = tab_height(game->map);
	game->map_width = ft_strlen(game->map[0]);
	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (inner_loop_checker(game, row, col) == 0)
				return (0);
			col++;
		}
		row++;
	}
	if (outer_loop_checker(game) == 0 || path_finder(game) == 0)
		return (0);
	return (1);
}
