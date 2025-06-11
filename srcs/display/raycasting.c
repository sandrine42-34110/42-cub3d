#include "cub3d.h"

void draw_line(t_mlx *mlx)
{
	int dx = abs(mlx->x1 - mlx->x0);
	int dy = -abs(mlx->y1 - mlx->y0);
	int	sx;
	int sy;
	int err = dx + dy;
	int e2;

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
	int		nb_rays;
	double	fov; 
	double	start_angle;
	double	angle_step;
	double	ray_angle;

	nb_rays = W_WIN; // Nombre de rayons à tracer
	fov = 90.0 * M_PI / 180.0; // Champ de vision en radians
	start_angle = all->player->or - fov / 2;
	angle_step = fov / nb_rays;
	all->raycast->pos_ray = 0;
	while (all->raycast->pos_ray < nb_rays)
	{
		ray_angle = start_angle + all->raycast->pos_ray * angle_step;
		draw_vision_line(all, ray_angle); // Bleu pour les rayons
		(all->raycast->pos_ray)++;
	}
}