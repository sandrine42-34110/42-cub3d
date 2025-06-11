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

void draw_line(t_mlx *mlx)
{
	int dx = abs(mlx->x1 - mlx->x0);
	int dy = -abs(mlx->y1 - mlx->y0);
	int	sx;
	int sy;
	int err = dx + dy;
	int e2;
	// int sx = x0 < x1 ? 1 : -1;
	// int sy = y0 < y1 ? 1 : -1;
	if (mlx->x0 < mlx->x1)
		sx = 1;
	else
		sx = -1;
	if (mlx->y0 < mlx->y1)
		sy = 1;
	else
		sy = -1;

	while (1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x0, mlx->y0, mlx->color);
		if (mlx->x0 == mlx->x1 && mlx->y0 == mlx->y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			mlx->x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			mlx->y0 += sy;
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

	all->mlx->color=0xFF0000;

	px = all->minimap->offset_x + all->player->x * all->mlx->tile_size;
	py = all->minimap->offset_y + all->player->y * all->mlx->tile_size;
	angle = all->player->or;
	line_len = 20.0;
	end_x = px + cos(angle) * line_len;
	end_y = py + sin(angle) * line_len;
	draw_line(all->mlx);
}

void adjust_ray_to_wall_border(t_all *all)
{
	int	x;
	int	y;

	x = (int)all->raycast->ray_x;
	y = (int)all->raycast->ray_y;
	while (all->map->line[y][x] == '1')
	{
		all->raycast->ray_x -= all->raycast->ray_dir_x * 0.01;
		all->raycast->ray_y -= all->raycast->ray_dir_y * 0.01;
		x = (int)all->raycast->ray_x;
		y = (int)all->raycast->ray_y;
	}
}

void draw_vision_line(t_all *all, double angle)
{
	int		hit;

	hit = 0;
	all->raycast->px = all->player->x;
	all->raycast->py = all->player->y;
	all->raycast->ray_dir_x = cos(angle);
	all->raycast->ray_dir_y = sin(angle);
	all->raycast->ray_x = all->raycast->px;
	all->raycast->ray_y = all->raycast->py;
	all->mlx->color=0x0000FF;
	while (!hit)
	{
		all->raycast->ray_x += all->raycast->ray_dir_x * 0.2;
		all->raycast->ray_y += all->raycast->ray_dir_y * 0.2;
		if (all->map->line[(int)all->raycast->ray_y][(int)all->raycast->ray_x] == '1')
		{
			hit = 1;
			adjust_ray_to_wall_border(all);
		}
	}
	all->raycast->start_x = all->minimap->offset_x + all->raycast->px * all->mlx->tile_size;
	all->raycast->start_y = all->minimap->offset_y + all->raycast->py * all->mlx->tile_size;
	all->raycast->end_x = all->minimap->offset_x + all->raycast->ray_x * all->mlx->tile_size;
	all->raycast->end_y = all->minimap->offset_y + all->raycast->ray_y * all->mlx->tile_size;
	all->mlx->x0 = all->raycast->start_x;
	all->mlx->y0 = all->raycast->start_y;
	all->mlx->x1 = all->raycast->end_x;
	all->mlx->y1 = all->raycast->end_y;
	all->mlx->color = 0x0000FF;
	draw_line(all->mlx);

}

void draw_vision_cone(t_all *all)
{
	int		i = 0;
	int		nb_rays = W_WIN; // Nombre de rayons à tracer
	double	fov = 90.0 * M_PI / 180.0; // Champ de vision en radians
	double	start_angle = all->player->or - fov / 2;
	double	angle_step = fov / nb_rays;

	while (i < nb_rays)
	{
		double ray_angle = start_angle + i * angle_step;
		draw_vision_line(all, ray_angle); // Bleu pour les rayons
		i++;
	}
}

void	display_minimap(t_all *all)
{
	display_map(all);
	display_player(all);
	draw_orientation_line(all);
	draw_vision_cone(all);
}
