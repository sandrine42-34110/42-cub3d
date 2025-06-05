/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:35:04 by sapupier          #+#    #+#             */
/*   Updated: 2025/03/06 12:07:56 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESCAPE)
	{
		close_window(vars);
	}
	else
		move_player(vars, keycode);
	return (0);
}

int	is_valid_move(t_vars *vars, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= vars->game_map.cols || new_y < 0
		|| new_y >= vars->game_map.rows)
		return (0);
	if (vars->game_map.grid[new_y][new_x] == '1')
		return (0);
	if (vars->game_map.grid[new_y][new_x] == 'E'
			&& vars->game_map.collectibles != 0)
		return (0);
	return (1);
}

void	collect_item(t_vars *vars, int new_x, int new_y)
{
	if (vars->game_map.grid && vars->game_map.grid[new_y][new_x] != '1')
	{
		if (vars->game_map.grid[new_y][new_x] == 'C')
		{
			vars->game_map.collectibles--;
			vars->game_map.grid[new_y][new_x] = '0';
		}
	}
}

void	try_exit(t_vars *vars, int new_x, int new_y)
{
	if (vars->game_map.grid[new_y][new_x] == 'E')
	{
		if (vars->game_map.collectibles == 0)
			close_window(vars);
	}
}

int	movement(int keycode, int *new_x, int *new_y)
{
	if (keycode)
	{
		if (keycode == KEY_D_RIGHT)
			return (((*new_x) += 1), 0);
		else if (keycode == KEY_A_LEFT)
			return (((*new_x) -= 1), 0);
		else if (keycode == KEY_W_UP)
			return (((*new_y) -= 1), 0);
		else if (keycode == KEY_S_DOWN)
			return (((*new_y) += 1), 0);
	}
	return (1);
}
