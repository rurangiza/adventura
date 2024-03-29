/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:40:40 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/27 12:28:40 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Initialized the game environment
 *
 * - initialize minilibx, open a window, 
 * - check arguments, file extension and check map
 * - load assets
 * - initialize player position and movement count 
*/

#include "so_long.h"

int	game_init(t_game *game, char **av)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (error_msg(0, "can't initialize minilibx"));
	game->window = NULL;
	game->sprites[0].img = NULL;
	map_init(game, av);
	if (map_checker(game) == 0)
		return (0);
	game->window = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE + (HUD_HEIGHT + 40), "Adventura");
	if (game->window == NULL)
	{
		free(game->window);
		return (error_msg(0, "couldn't connect to the window"));
	}
	player_init(game);
	game->delay = 0;
	game->animation_state = 0;
	game->polarity = 1;
	return (load_assets(game));
}

void	map_init(t_game *game, char **av)
{
	game->map_filepath = av[1];
	game->c_credit = 0;
	game->e_credit = 0;
	game->p_credit = 0;
	game->map_width = -1;
}

void	player_init(t_game *game)
{
	game->x_shift = game->starting_pos.col;
	game->y_shift = game->starting_pos.row;
	game->x_last = game->x_shift;
	game->y_last = game->y_shift;
	game->plr_angle = 16;
	game->steps_count = 0;
	game->life_points = 5;
	game->player_moved = TRUE;
	game->enemies = NULL;
}
