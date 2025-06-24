/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_text_and_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:27:26 by sapupier          #+#    #+#             */
/*   Updated: 2025/06/24 11:30:36 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_text(t_all *all)
{
	if (all->text->no == NULL || all->text->so == NULL
		|| all->text->we == NULL || all->text->ea == NULL)
		error_msg_and_close("Error : Missing texture information\n", all);
	if (all->text->floor == 0 || all->text->ceiling == 0)
		error_msg_and_close("Error : Missing color information\n", all);
}

void	invalid_tile(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->map->h_map)
	{
		x = 0;
		while (x < all->map->w_map)
		{
			if (all->map->line[y][x] == '\0')
				break ;
			else if (all->map->line[y][x] != 'N' && all->map->line[y][x] != 'S'
				&& all->map->line[y][x] != 'E' && all->map->line[y][x] != 'W'
				&& all->map->line[y][x] != '0' && all->map->line[y][x] != '1'
				&& all->map->line[y][x] != ' ')
				error_msg_and_close("Error : Invalid map\n", all);
			x++;
		}
		y++;
	}
}

void	check_close_map(t_all *all)
{
	int		x;
	int		y;
	char	**map_copy;

	x = 0;
	y = 0;
	if (!find_start(all->map, &x, &y))
		error_msg_and_close("Error : No player!\n", all);
	ctrl_only_one_player(all->map, x, y, all);
	map_copy = duplicate_map(all->map, all);
	flood_fill(map_copy, x, y, all);
	find_unclose_map(all->map, map_copy, all);
	free_map_copy(map_copy, all->map->h_map);
}

void	check_map(t_all *all)
{
	if (all->map->h_map < 3)
		error_msg_and_close("Error : Invalid map\n", all);
	check_close_map(all);
	invalid_tile(all);
}

void	check_text_and_map(t_all *all)
{
	check_text(all);
	check_map(all);
}
