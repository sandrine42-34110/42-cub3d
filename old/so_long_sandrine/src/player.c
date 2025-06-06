/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:59:36 by sapupier          #+#    #+#             */
/*   Updated: 2025/06/06 15:35:29 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_vars *vars, int keycode)
{
	int			new_x;
	int			new_y;
	static int	count;

	new_x = vars->player.pos.x;
	new_y = vars->player.pos.y;
	if (movement(keycode, &new_x, &new_y) == 1)
		return ;
	if (is_valid_move(vars, new_x, new_y) != 1)
		return ;
	if (vars->game_map.grid && vars->game_map.grid[new_y][new_x] != '1')
	{
		count++;
		ft_printf("%d\n", count);
		collect_item(vars, new_x, new_y);
		vars->game_map.grid[vars->player.pos.y][vars->player.pos.x] = '0';
		vars->player.pos.x = new_x;
		vars->player.pos.y = new_y;
		display_map(vars, &vars->game_map);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->person.img_ptr,
			new_x * vars->tile_size, new_y * vars->tile_size);
		try_exit(vars, new_x, new_y);
	}
}

int	count_collectibles(t_map *map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	x = 0;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->grid[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
