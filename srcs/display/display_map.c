#include "cub3d.h"

void	minimap_colors(t_all *all, int x, int y, int *color)
{
	if (all->map->line[y][x] == '1')
		*color = 0x00FF00;
	else if (all->map->line[y][x] == '0')
		*color = 0xFFFFFF;
	/* else if (all->map->line[y][x] == 'N' || all->map->line[y][x] == 'S'
		|| all->map->line[y][x] == 'E' || all->map->line[y][x] == 'W')
		*color = 0xFF0000; */
	else if (all->map->line[y][x] == 'N' || all->map->line[y][x] == 'S'
		|| all->map->line[y][x] == 'E' || all->map->line[y][x] == 'W')
		*color = 0xFFFFFF;
	else
		*color = 0x888888;
}

void	display_map(t_all *all)
{
	int	x;
	int	y;
	int	color;

	//all->minimap = init_minimap(all);
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

void	display_player(t_all *all)
{
	int	clr_pl;
	int	radius;

	radius = all->mlx->tile_size / 4;
	clr_pl = 0xFF0000;
	//all->player = init_player(all);
	draw_circle(all->mlx,
		all->minimap->offset_x + all->player->x * all->mlx->tile_size,
		all->minimap->offset_y + all->player->y * all->mlx->tile_size,
		radius, clr_pl);
}

void draw_line(t_mlx *mlx, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0);
	int dy = -abs(y1 - y0);
	int sx = x0 < x1 ? 1 : -1;
	int sy = y0 < y1 ? 1 : -1;
	int err = dx + dy;
	int e2;

	while (1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_orientation_line(t_all *all)
{
	double	px;
	double	py;
	double	angle;
	double	line_len; // Longueur du trait en pixels
	double	end_x;
	double	end_y;

	px = all->minimap->offset_x + all->player->x * all->mlx->tile_size;
	py = all->minimap->offset_y + all->player->y * all->mlx->tile_size;
	angle = all->player->or;
	line_len = 20.0;
	end_x = px + cos(angle) * line_len;
	end_y = py + sin(angle) * line_len;
	draw_line(all->mlx, (int)px, (int)py, (int)end_x, (int)end_y, 0xFF0000);
}

void draw_vision_line(t_all *all, double angle, int color)
{
	double	px = all->player->x;
	double	py = all->player->y;
	double	ray_dir_x = cos(angle);
	double	ray_dir_y = sin(angle);
	double	ray_x = px;
	double	ray_y = py;
	int		max_steps = 10; // Portée maximale
	int		step = 0;
	int		hit = 0;

	while (step < max_steps && !hit)
	{
		ray_x += ray_dir_x * 0.2;
		ray_y += ray_dir_y * 0.2;
		if (all->map->line[(int)ray_y][(int)ray_x] == '1')
			hit = 1;
		step++;
	}

	int	start_x = all->minimap->offset_x + px * all->mlx->tile_size;
	int	start_y = all->minimap->offset_y + py * all->mlx->tile_size;
	int	end_x = all->minimap->offset_x + ray_x * all->mlx->tile_size;
	int	end_y = all->minimap->offset_y + ray_y * all->mlx->tile_size;
	draw_line(all->mlx, start_x, start_y, end_x, end_y, color);
}

void draw_vision_cone(t_all *all)
{
	double	base_angle = all->player->or;
	double	angle_left = base_angle - (45.0 * M_PI / 180.0);  // -45°
	double	angle_right = base_angle + (45.0 * M_PI / 180.0); // +45°
	double	angle_quarter_left = base_angle - (22.5 * M_PI / 180.0); // -22.5°
	double	angle_quarter_right = base_angle + (22.5 * M_PI / 180.0); // +22.5°
	double	angle_mid_left = base_angle - (11.25 * M_PI / 180.0); // -11.25°
	double	angle_mid_right = base_angle + (11.25 * M_PI / 180.0); // +11.25°

	// Trace la ligne centrale (orientation principale)
	draw_vision_line(all, base_angle, 0xFF0000);

	// Trace les 6 lignes autour (pour un effet "cône")
	draw_vision_line(all, angle_left, 0x00FF00);
	draw_vision_line(all, angle_right, 0x00FF00);
	draw_vision_line(all, angle_quarter_left, 0x00FF00);
	draw_vision_line(all, angle_quarter_right, 0x00FF00);
	draw_vision_line(all, angle_mid_left, 0x00FF00);
	draw_vision_line(all, angle_mid_right, 0x00FF00);
}



void	display_minimap(t_all *all)
{
	display_map(all);
	display_player(all);
	draw_orientation_line(all);
	draw_vision_cone(all);
}
