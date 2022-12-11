/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:08:53 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/11 16:19:21 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Quit the game in a clean way, without errors or memory leaks
*/

#include "../../so_long.h"

int	game_over(t_game *game)
{
	if (game->map != NULL)
		free_matrix(game->map);
	if (game->window != NULL)
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
	}
	free(game->mlx);
	system("leaks so_long");
	exit(EXIT_SUCCESS);
	return (0);
}
