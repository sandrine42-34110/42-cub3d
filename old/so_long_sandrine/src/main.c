/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:26:14 by sapupier          #+#    #+#             */
/*   Updated: 2025/06/05 15:50:25 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_file_extension(const char *filename)
{
	const char	*extension;

	extension = ft_strrchr(filename, '.');
	if (extension && ft_strcmp(extension, ".ber") == 0)
		return (1);
	return (0);
}

int	init_and_validate_map(t_map *game_map, const char *file_path)
{
	t_vars	vars;

	vars.exit_count = 0;
	vars.start_count = 0;
	vars.item_count = 0;
	game_map->grid = read_map(file_path);
	if (!game_map->grid)
		return (0);
	if (!validate_map(vars, game_map->grid, &game_map->rows, &game_map->cols))
	{
		free_map_(game_map);
		return (0);
	}
	game_map->collectibles = count_collectibles(game_map);
	if (!verify_path(game_map))
	{
		ft_printf("Error\nNo valid path from start to exit\n");
		free_map_(game_map);
		return (0);
	}
	return (1);
}

int	init_mlx(t_vars *vars, t_map *game_map)
{
	int	win_width;
	int	win_height;

	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		ft_printf("Error\nFailed to initialize mlx\n");
		return (0);
	}
	vars->win = NULL;
	win_width = game_map->cols * TILE_SIZE;
	win_height = game_map->rows * TILE_SIZE;
	vars->win = mlx_new_window(vars->mlx, win_width, win_height, "So Long");
	if (!vars->win)
	{
		ft_printf("Error\nFailed to create window\n");
		free(vars->mlx);
		return (0);
	}
	vars->window_width = win_width;
	vars->window_height = win_height;
	vars->tile_size = TILE_SIZE;
	return (1);
}

int	initalize_game(t_vars *vars, t_map *game_map, int argc, char **argv)
{
	int		start_x;
	int		start_y;

	start_x = 0;
	start_y = 0;
	if (argc != 2)
		return (0);
	if (!validate_file_extension(argv[1]))
		return (ft_printf("Error\nThe file must have .ber extension\n"), 0);
	if (open(argv[1], O_RDONLY) == -1)
		return (ft_printf("Error\nUnable to access file\n"), 0);
	if (!init_and_validate_map(game_map, argv[1]))
		return (0);
	if (!find_start(game_map, &start_x, &start_y))
		return (ft_printf("Error\nNo starting position found\n"), 0);
	if (!init_mlx(vars, game_map))
		return (free_map_(game_map), 0);
	vars->game_map = *game_map;
	vars->player.pos.x = start_x;
	if (!load_images(vars))
		return (free_map_(game_map), 0);
	vars->player.pos.y = start_y;

	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	game_map;

	if (!initalize_game(&vars, &game_map, argc, argv))
		return (1);
	display_map(&vars, &game_map);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_hook(vars.win, 2, (1L << 0), key_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}
