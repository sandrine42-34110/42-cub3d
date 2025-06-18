#include "cub3d.h"

void draw_line(t_all *all, t_mlx *mlx)
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
		//mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x0, mlx->y0, mlx->color);
		put_pixel(all->screen, mlx->x0, mlx->y0, all->mlx->color);
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

// void	draw_orientation_line(t_all *all)
// {
// 	double	px;
// 	double	py;
// 	double	angle;
// 	double	line_len; // Longueur du trait en pixels
// 	double	end_x;
// 	double	end_y;

// 	all->mlx->color=0xFF0000;

// 	px = all->minimap->offset_x + all->player->x * all->mlx->tile_size;
// 	py = all->minimap->offset_y + all->player->y * all->mlx->tile_size;
// 	angle = all->player->or;
// 	line_len = 20.0;
// 	end_x = px + cos(angle) * line_len;
// 	end_y = py + sin(angle) * line_len;
// 	draw_3d(all);
// 	draw_line(all, all->mlx);
// }

/* 
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
	all->raycast->start_x = (double)all->minimap->offset_x + all->raycast->px * (double)all->mlx->tile_size;
	all->raycast->start_y = (double)all->minimap->offset_y + all->raycast->py * (double)all->mlx->tile_size;
	all->raycast->end_x = (double)all->minimap->offset_x + all->raycast->ray_x * (double)all->mlx->tile_size;
	all->raycast->end_y = (double)all->minimap->offset_y + all->raycast->ray_y * (double)all->mlx->tile_size;
	all->mlx->x0 = all->raycast->start_x;
	all->mlx->y0 = all->raycast->start_y;
	all->mlx->x1 = all->raycast->end_x;
	all->mlx->y1 = all->raycast->end_y;
	all->mlx->color = 0x0000FF;
	draw_line(all, all->mlx);
	draw_walls(all, angle);
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
	angle_step = fov / (double)nb_rays;
	all->raycast->pos_px_x = 0;
	while (all->raycast->pos_px_x < nb_rays)
	{

		ray_angle = start_angle + all->raycast->pos_px_x * angle_step;
		draw_vision_line(all, ray_angle); // Bleu pour les rayons
		(all->raycast->pos_px_x)++;
	}
} */

/* void	draw_vision_line(t_all *all)
{
	int	hit;

	hit = 0;
	all->raycast->px = all->player->x;
	all->raycast->py = all->player->y;
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
	draw_walls(all);
	all->raycast->start_x = (double)all->minimap->offset_x + all->raycast->px * (double)all->mlx->tile_size;
	all->raycast->start_y = (double)all->minimap->offset_y + all->raycast->py * (double)all->mlx->tile_size;
	all->raycast->end_x = (double)all->minimap->offset_x + all->raycast->ray_x * (double)all->mlx->tile_size;
	all->raycast->end_y = (double)all->minimap->offset_y + all->raycast->ray_y * (double)all->mlx->tile_size;
	all->mlx->x0 = all->raycast->start_x;
	all->mlx->y0 = all->raycast->start_y;
	all->mlx->x1 = all->raycast->end_x;
	all->mlx->y1 = all->raycast->end_y;
	all->mlx->color = 0x0000FF;
	draw_line(all, all->mlx);
} */



void	draw_vision_line(t_all *all)
{
	int		hit;
	double	prev_x;
	double	prev_y;
	double	dx;
	double	dy;
	// double diff_x;
	// double diff_y;

	hit = 0;
	all->raycast->px = all->player->x;
	all->raycast->py = all->player->y;
	all->raycast->ray_x = all->raycast->px;
	all->raycast->ray_y = all->raycast->py;
	while (!hit){
		prev_x = all->raycast->ray_x;
		prev_y = all->raycast->ray_y;
		if (all->map->line[(int)all->raycast->ray_y]
			[(int)all->raycast->ray_x] == '1')
		{
			// diff_x = ((int)all->raycast->ray_x - (int)prev_x);
			// diff_y = ((int)all->raycast->ray_y - (int)prev_y);
			// if (diff_x != 0 && diff_y != 0)
			// {
			// 	diff_x = fabs(all->raycast->ray_x - prev_x);
			// 	diff_y = fabs(all->raycast->ray_y - prev_y);
			// 	if (diff_x < diff_y && diff_x < 0.5)
			// 			all->raycast->wall_tex = TEX_EA;
			// 	else if (diff_y < diff_x && diff_y < 0.5)
			// 			all->raycast->wall_tex = TEX_SO;
			// 	else if (diff_x > diff_y && diff_x >= 0.5)
			// 		all->raycast->wall_tex = TEX_WE;
			// 	else if (diff_y > diff_x && diff_y >= 0.5)
			// 			all->raycast->wall_tex = TEX_NO;
			// }
			// else if (diff_x != 0)
			// {
			// 	if (diff_x < 0)
			// 		all->raycast->wall_tex = TEX_EA;
			// 	else
			// 		all->raycast->wall_tex = TEX_WE;
			// }
			// else if (diff_y != 0)
			// {
			// 	if (diff_y < 0)
			// 		all->raycast->wall_tex = TEX_NO;
			// 	else
			// 		all->raycast->wall_tex = TEX_SO;
			// }
			hit = 1;
			dx = fabs(all->raycast->ray_x - prev_x);
			dy = fabs(all->raycast->ray_y - prev_y);
			if (dx > dy)
			{
				if (all->raycast->ray_dir_x > 0)
					all->raycast->wall_tex = TEX_WE;
				else
					all->raycast->wall_tex = TEX_EA;
			}
			else
			{
				if (all->raycast->ray_dir_y > 0)
					all->raycast->wall_tex = TEX_NO;
				else
					all->raycast->wall_tex = TEX_SO;
			}
		}
		//printf("DEBUG wall_text = %d\n", all->raycast->wall_tex);
	}
	draw_walls(all);
	all->raycast->start_x = (double)all->minimap->offset_x
		+ all->raycast->px * (double)all->mlx->tile_size;
	all->raycast->start_y = (double)all->minimap->offset_y
		+ all->raycast->py * (double)all->mlx->tile_size;
	all->raycast->end_x = (double)all->minimap->offset_x
		+ all->raycast->ray_x * (double)all->mlx->tile_size;
	all->raycast->end_y = (double)all->minimap->offset_y
		+ all->raycast->ray_y * (double)all->mlx->tile_size;
	all->mlx->x0 = all->raycast->start_x;
	all->mlx->y0 = all->raycast->start_y;
	all->mlx->x1 = all->raycast->end_x;
	all->mlx->y1 = all->raycast->end_y;
	all->mlx->color = 0x0000FF;
	draw_line(all, all->mlx);
}

void	draw_vision_cone(t_all *all)
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	dir_x = cos(all->player->or);
	dir_y = sin(all->player->or);
	plane_x = -dir_y * tan(90.0 * M_PI / 360.0);
	plane_y = dir_x * tan(90.0 * M_PI / 360.0);

	all->raycast->pos_px_x = 0;
	
	
	while (all->raycast->pos_px_x < W_WIN)
	{
		camera_x = 2.0 * all->raycast->pos_px_x / W_WIN - 1.0;
		all->raycast->ray_dir_x = dir_x + plane_x * camera_x;
		all->raycast->ray_dir_y = dir_y + plane_y * camera_x;
		draw_vision_line(all);
		all->raycast->pos_px_x++;
	}
	
	ft_printf("DEBUG player is NULL\n");
}
