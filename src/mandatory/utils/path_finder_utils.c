/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:13:21 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/07 13:48:33 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

// Check if node has neem visited, based on coordinates
int	in_queue(t_node current, t_node *queue, int head, int tail)
{
	int		i;

	i = 0;
	while (i <= tail)
	{
		if (i == head)
			i++;
		if (queue[i].row == current.row && queue[i].col == current.col)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

// Add node to a matrix of nodes
t_node	add_node(int row, int col)
{
	t_node	node;

	node.row = row;
	node.col = col;
	return (node);
}

// Initialize the queue
void	q_init(t_node *queue, int q_size)
{
	int	i;

	i = 0;
	while (i < q_size)
	{
		queue[i] = add_node(-1, -1);
		i++;
	}
}

// Check if an exit was found
int	found_exit(t_game *game, t_node node)
{
	if (game->map[node.row][node.col] == 'E')
		return (1);
	return (0);
}

// Add all friends to the queue
void	add_neighbours(t_game *game, t_node *queue, int head, int *tail)
{
	t_node	current;
	int		pos;
	int		row;
	int		col;

	pos = *tail;
	current = queue[head];
	row = current.row - 1;
	while (row <= current.row + 1)
	{
		col = current.col - 1;
		while (col <= current.col + 1)
		{
			if (game->map[row][col] == '1')
				col++;
			else if (game->map[row][col] == 'P')
				col++;
			else if ((row == current.row) && (col == current.col))
				col++;
			else if (in_queue(add_node(row, col), queue, head, *tail))
				col++;
			else
			{
				queue[pos++] = add_node(row, col);
				*tail += 1;
				col++;
			}
		}
		row++;
	}
}
