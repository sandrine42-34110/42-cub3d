#include "cub3d.h"

void	draw_ceiling(t_all *all)
{
	int	x;
	int	y;
	int	color;

	color = ((all->text->ceiling_r << 16) | (all->text->ceiling_g << 8) | (all->text->ceiling_b));
	y = 0;
	while (y < H_WIN / 2)
	{
		x = 0;
		while (x < W_WIN)
		{
			put_pixel(all->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_all *all)
{
	int	x;
	int	y;
	int	color;

	color = ((all->text->floor_r << 16) | (all->text->floor_g << 8) | (all->text->floor_b));
	y = H_WIN / 2;
	while (y < H_WIN)
	{
		x = 0;
		while (x < W_WIN)
		{
			if ((y >= H_WIN - all->minimap->map_height_px + 1) && (x > W_WIN - all->minimap->map_width_px))
				break ;
			else
				put_pixel(all->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_walls(t_all *all)
{
	double	vx;
	double	vy;
	double	perp;
	double	h;
	int		y[2];

	vx = all->raycast->ray_x - all->raycast->px;
	vy = all->raycast->ray_y - all->raycast->py;
	perp = vx * cos(all->player->or) + vy * sin(all->player->or);
	if (perp < 0.0001)
		perp = 0.0001;
	h = (1.0 / perp) * ((W_WIN / 2.0) / tan(FOV_RAD / 2.0));
	y[0] = (int)((H_WIN - h) / 2.0);
	y[1] = (int)((H_WIN + h) / 2.0);
	if (y[0] < 0)
		y[0] = 0;
	if (y[1] >= H_WIN)
		y[1] = H_WIN - 1;
	while (y[0] < y[1])
	{
		if (y[0] >= H_WIN - all->minimap->map_height_px + 1
			&& all->raycast->pos_px_x > W_WIN - all->minimap->map_width_px)
			break ;
		put_pixel(all->img, all->raycast->pos_px_x, y[0]++, 0x00FFFF);
	}
}

/* 
double normalize_angle(double angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return angle;
}

void	draw_walls(t_all *all, double angle)
{
	double	len_ray;
	double	height_wall;
	double	y;
	int		color = 0x00FFFF;
	int		end_y;

	//printf("wall\n");
	angle = normalize_angle(angle);
	double diff_angle = angle - all->player->or;
	if (diff_angle > M_PI)
		diff_angle -= 2 * M_PI;
	if (diff_angle < -M_PI)
		diff_angle += 2 * M_PI;
	
	len_ray = sqrt(pow((all->raycast->end_x - all->raycast->start_x), 2) +
				   pow((all->raycast->end_y - all->raycast->start_y), 2));
	len_ray = len_ray * cos(diff_angle);
	

	double scale = 8; // ou 2.0 selon le rendu voulu
	height_wall = ((double)H_WIN / len_ray) * scale;

	// height_wall = H_WIN / len_ray;
	y = (int)round((H_WIN - height_wall) / 2.0f);
	end_y = (int)round((H_WIN + height_wall) / 2.0f);
	if (y < 0) 
		y = 0;
	if	(end_y >= H_WIN)
		end_y = H_WIN - 1;
	while (y < end_y)
	{
		if ((y >= H_WIN - all->minimap->map_height_px + 1) && (all->raycast->pos_px_x > W_WIN - all->minimap->map_width_px))
				break ;
			else
		put_pixel(all->img, all->raycast->pos_px_x, y, color);
		y++;
	}
	

} */
// void	draw_walls(t_all *all, double angle)
// {
// 	double	len_ray;
// 	double	height_wall;
// 	double	y;
// 	int		end_y;
// 	int		color;

// 	color = 0x00FFFF;
// 	angle = normalize_angle(angle - all->player->or);
// 	len_ray = sqrt(pow(all->raycast->end_x - all->raycast->start_x, 2)
// 			+ pow(all->raycast->end_y - all->raycast->start_y, 2)) / cos(angle);
// 	height_wall = (H_WIN / len_ray) * 1.5;
// 	y = (H_WIN - height_wall) / 2;
// 	end_y = (int)((H_WIN + height_wall) / 2);
// 	if (y < 0)
// 		y = 0;
// 	if (end_y >= H_WIN)
// 		end_y = H_WIN - 1;
// 	while (y < end_y)
// 		put_pixel(all->img, all->raycast->pos_ray, (int)(y++), color);
// }


