/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:06:13 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/09 10:16:50 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	is_walkable(t_game *game, char ch)
{
	if (ch == '0' || ch == 'C' || ch == 'E' || ch == 'P' || ch == 'N')
	{
		game->movements += 1;
		ft_printf("steps: %d\n", game->movements);
		return (1);
	}
	return (0);
}
