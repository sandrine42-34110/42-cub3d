/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:29:06 by sapupier          #+#    #+#             */
/*   Updated: 2025/06/23 16:29:07 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_walkable(t_all *all, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (all->map->line[map_y][map_x] == '1')
		return (0);
	return (1);
}

void	move_player_by_delta(t_all *all, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = all->player->x + dx;
	new_y = all->player->y + dy;
	if (is_walkable(all, new_x, all->player->y))
		all->player->x = new_x;
	if (is_walkable(all, all->player->x, new_y))
		all->player->y = new_y;
}

void	rotation(t_all *all)
{
	if (all->input.left)
		all->player->or -= ANGLE_ROT;
	if (all->input.right)
		all->player->or += ANGLE_ROT;
}

void	translation(t_all *all, double *dy, double *dx)
{
	if (all->input.w)
	{
		*dx += cos(all->player->or) * MOVE_SPEED;
		*dy += sin(all->player->or) * MOVE_SPEED;
	}
	if (all->input.s)
	{
		*dx -= cos(all->player->or) * MOVE_SPEED;
		*dy -= sin(all->player->or) * MOVE_SPEED;
	}
	if (all->input.d)
	{
		*dx += cos(all->player->or + M_PI_2) * MOVE_SPEED;
		*dy += sin(all->player->or + M_PI_2) * MOVE_SPEED;
	}
	if (all->input.a)
	{
		*dx += cos(all->player->or - M_PI_2) * MOVE_SPEED;
		*dy += sin(all->player->or - M_PI_2) * MOVE_SPEED;
	}
}

int	update_frame(t_all *all)
{
	double	dx;
	double	dy;

	dx = 0;
	dy = 0;
	rotation(all);
	translation(all, &dy, &dx);
	if (dx != 0 || dy != 0)
		move_player_by_delta(all, dx, dy);
	display_screen(all);
	return (0);
}
