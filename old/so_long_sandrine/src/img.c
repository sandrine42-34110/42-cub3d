/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:35:30 by sapupier          #+#    #+#             */
/*   Updated: 2025/02/27 13:30:22 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_vars *vars, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img_ptr, x * TILE_SIZE,
		y * TILE_SIZE);
}

void	display_map(t_vars *vars, t_map *game_map)
{
	int	x;
	int	y;

	y = 0;
	while (y < game_map->rows)
	{
		x = 0;
		while (x < game_map->cols)
		{
			put_image(vars, vars->backgrd.img_ptr, x, y);
			if (game_map->grid[y][x] == '1')
				put_image(vars, vars->wall.img_ptr, x, y);
			else if (game_map->grid[y][x] == 'E')
				put_image(vars, vars->door.img_ptr, x, y);
			else if (game_map->grid[y][x] == 'P')
				put_image(vars, vars->person.img_ptr, x, y);
			else if (game_map->grid[y][x] == 'C')
				put_image(vars, vars->collect.img_ptr, x, y);
			x++;
		}
		y++;
	}
}

int	load_images(t_vars *vars)
{
	vars->person.img_ptr = mlx_xpm_file_to_image(vars->mlx, "person_right.xpm",
			&vars->person.width, &vars->person.heigh);
	vars->backgrd.img_ptr = mlx_xpm_file_to_image(vars->mlx, "background.xpm",
			&vars->backgrd.width, &vars->backgrd.heigh);
	vars->wall.img_ptr = mlx_xpm_file_to_image(vars->mlx, "wall.xpm",
			&vars->wall.width, &vars->wall.heigh);
	vars->door.img_ptr = mlx_xpm_file_to_image(vars->mlx, "door.xpm",
			&vars->door.width, &vars->door.heigh);
	vars->collect.img_ptr = mlx_xpm_file_to_image(vars->mlx, "collectible.xpm",
			&vars->collect.width, &vars->collect.heigh);
	if (!vars->person.img_ptr || !vars->backgrd.img_ptr
		|| !vars->wall.img_ptr || !vars->door.img_ptr || !vars->collect.img_ptr)
	{
		return (ft_printf("Error\nFailed to load one or more images\n"), 0);
	}
	if (vars->person.width != TILE_SIZE || vars->person.heigh != TILE_SIZE
		|| vars->backgrd.width != TILE_SIZE || vars->backgrd.heigh != TILE_SIZE
		|| vars->wall.width != TILE_SIZE || vars->wall.heigh != TILE_SIZE
		|| vars->door.width != TILE_SIZE || vars->door.heigh != TILE_SIZE
		|| vars->collect.width != TILE_SIZE || vars->collect.heigh != TILE_SIZE)
	{
		ft_printf("Error\nOne or more images have incorrect dimensions\n");
		return (0);
	}
	return (1);
}
