#include "cub3d.h"

void	draw_square(t_all *all, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_pixel_put(all->mlx->mlx_ptr, all->mlx->win_ptr,
				x + i, y + j, color);
			j++;
		}
		i++;
	}
}

t_minimap	*init_minimap(t_all *all)
{
	t_minimap	*minimap;

	minimap = malloc(sizeof(t_minimap));
	if (!minimap)
		error_and_close_all("Error : malloc minimap failed!", all);
	minimap->map_width_px = 0;
	minimap->map_height_px = 0;
	minimap->offset_x = 0;
	minimap->offset_y = 0;
	return (minimap);
}

void	minimap_colors(t_all *all, int x, int y, int *color)
{
	if (all->map->line[y][x] == '1')
		*color = 0x00FF00;
	else if (all->map->line[y][x] == '0')
		*color = 0xFFFFFF;
	else if (all->map->line[y][x] == 'N' || all->map->line[y][x] == 'S'
		|| all->map->line[y][x] == 'E' || all->map->line[y][x] == 'W')
		*color = 0xFF0000;
	else
		*color = 0x888888;
}

void	display_map(t_all *all)
{
	int	x;
	int	y;
	int	color;

	all->minimap = init_minimap(all);
	all->minimap->map_width_px = all->map->w_map * all->mlx->tile_size;
	all->minimap->map_height_px = all->map->h_map * all->mlx->tile_size;
	all->minimap->offset_x = W_WIN - all->minimap->map_width_px;
	all->minimap->offset_y = H_WIN - all->minimap->map_height_px;
	y = 0;
	while (y < all->map->h_map)
	{
		x = 0;
		while (all->map->line[y][x])
		{
			minimap_colors(all, x, y, &color);
			draw_square(all, all->minimap->offset_x + x * all->mlx->tile_size,
				all->minimap->offset_y + y * all->mlx->tile_size,
				all->mlx->tile_size, color);
			x++;
		}
		y++;
	}
}

t_player	*init_player(t_all *all)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		error_and_close_all("Error : malloc player failed!", all);
	player->dx = 0;
	player->dy = 0;
	player->d_or = 0;
	player->x = 0;
	player->y = 0;
	player->or = 0;
	return (player);
}

void	display_player(t_all *all)
{
	all->player = init_player(all);
	
}


void	display_minimap(t_all *all)
{
	display_map(all);
	display_player(all);
}