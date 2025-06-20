#include "cub3d_bonus.h"

void	minimap_colors(t_all *all, int x, int y)
{
	if (all->map->line[y][x] == '1')
		all->minimap->color = WCMM;
	else if (all->map->line[y][x] == '0')
		all->minimap->color = FCMM;
	else if (all->map->line[y][x] == 'N' || all->map->line[y][x] == 'S'
		|| all->map->line[y][x] == 'E' || all->map->line[y][x] == 'W')
		all->minimap->color = FCMM;
	else
		all->minimap->color = 0x888888;
}

void	display_map(t_all *all)
{
	int	x;
	int	y;

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
			minimap_colors(all, x, y);
			draw_square(all, all->minimap->offset_x + x * all->mlx->tile_size,
				all->minimap->offset_y + y * all->mlx->tile_size,
				all->mlx->tile_size);
			x++;
		}
		y++;
	}
}

void	display_player(t_all *all)
{
	int	radius;

	radius = all->mlx->tile_size / 4;
	draw_circle(all,
		all->minimap->offset_x + all->player->x * all->mlx->tile_size,
		all->minimap->offset_y + all->player->y * all->mlx->tile_size,
		radius);
}

void	display_screen(t_all *all)
{
	display_map(all);
	display_player(all);
	draw_ceiling(all);
	draw_floor(all);
	draw_vision_cone(all);
	mlx_put_image_to_window(all->mlx->mlx_ptr, all->mlx->win_ptr,
		all->screen->img, 0, 0);
}
