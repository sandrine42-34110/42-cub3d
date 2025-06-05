/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:24:49 by sapupier          #+#    #+#             */
/*   Updated: 2025/03/06 12:09:17 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(const char *file_path)
{
	int		fd;
	char	**map;

	map = init_map(file_path);
	if (!map)
		return (NULL);
	fd = open_file(file_path);
	if (fd == -1)
	{
		free(map);
		return (NULL);
	}
	if (!read_and_verify_map(fd, map))
	{
		free_map(map);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}

int	close_window(t_vars *vars)
{
	if (vars->person.img_ptr)
		mlx_destroy_image(vars->mlx, vars->person.img_ptr);
	if (vars->backgrd.img_ptr)
		mlx_destroy_image(vars->mlx, vars->backgrd.img_ptr);
	if (vars->wall.img_ptr)
		mlx_destroy_image(vars->mlx, vars->wall.img_ptr);
	if (vars->door.img_ptr)
		mlx_destroy_image(vars->mlx, vars->door.img_ptr);
	if (vars->collect.img_ptr)
		mlx_destroy_image(vars->mlx, vars->collect.img_ptr);
	free_map_(&vars->game_map);
	return (mlx_loop_end(vars->mlx));
}

int	validate_map(t_vars vars, char **map, int *rows, int *cols)
{
	if (!map || !map[0])
		return (ft_printf("Error\nEmpty map\n"), 0);
	get_map_dimensions(map, rows, cols);
	if (!check_borders(map))
	{
		ft_printf("Error\nInvalid map borders\n");
		return (0);
	}
	if (check_characters(vars, map))
		return (0);
	return (1);
}
