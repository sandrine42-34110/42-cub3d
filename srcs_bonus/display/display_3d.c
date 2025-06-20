#include "cub3d_bonus.h"

void	draw_ceiling(t_all *all)
{
	int	x;
	int	y;
	int	color;

	color = ((all->text->ceiling_r << 16)
			| (all->text->ceiling_g << 8)
			| (all->text->ceiling_b));
	y = 0;
	while (y < H_WIN / 2)
	{
		x = 0;
		while (x < W_WIN)
		{
			put_pixel(all->screen, x, y, color);
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

	color = ((all->text->floor_r << 16)
			| (all->text->floor_g << 8)
			| (all->text->floor_b));
	y = H_WIN / 2;
	while (y < H_WIN)
	{
		x = 0;
		while (x < W_WIN)
		{
			if ((y >= H_WIN - all->minimap->map_height_px + 1)
				&& (x > W_WIN - all->minimap->map_width_px))
				break ;
			else
				put_pixel(all->screen, x, y, color);
			x++;
		}
		y++;
	}
}

double	height_wall(t_all *all, int *y_0, int *y_1)
{
	double	h;

	if (all->raycast->perp < 0.0001)
		all->raycast->perp = 0.0001;
	h = (1.0 / all->raycast->perp) * ((W_WIN / 2.0) / tan(FOV * M_PI / 360.0));
	*y_0 = (int)((H_WIN - h) / 2.0);
	*y_1 = (int)((H_WIN + h) / 2.0);
	if (*y_0 < 0)
		*y_0 = 0;
	if (*y_1 >= H_WIN)
		*y_1 = H_WIN - 1;
	return (h);
}

void	wall_tex(t_all *all, t_wall *wall, double h, int y_0)
{
	if (all->raycast->wall_tex == TEX_NO)
		wall->tex = &all->mlx->img_w_n;
	else if (all->raycast->wall_tex == TEX_SO)
		wall->tex = &all->mlx->img_w_s;
	else if (all->raycast->wall_tex == TEX_WE)
		wall->tex = &all->mlx->img_w_w;
	else
		wall->tex = &all->mlx->img_w_e;
	if (all->raycast->wall_tex == TEX_NO || all->raycast->wall_tex == TEX_SO)
		wall->wall_x = all->raycast->ray_x;
	else
		wall->wall_x = all->raycast->ray_y;
	wall->wall_x -= floor(wall->wall_x);
	wall->tex_x = (int)(wall->wall_x * (double)wall->tex->width);
	if (wall->tex_x < 0)
		wall->tex_x += wall->tex->width;
	if ((all->raycast->wall_tex == TEX_EA || all->raycast->wall_tex == TEX_NO))
		wall->tex_x = wall->tex->width - wall->tex_x - 1;
	wall->step = (double)wall->tex->height / h;
	wall->tex_pos = (y_0 - H_WIN / 2.0 + h / 2.0) * wall->step;
}

void	draw_walls(t_all *all)
{
	t_wall	wall;
	double	h;
	int		y[3];

	h = height_wall(all, &y[0], &y[1]);
	wall_tex(all, &wall, h, y[0]);
	y[2] = y[0];
	while (y[2] < y[1])
	{
		wall.tex_y = (int)wall.tex_pos;
		if (wall.tex_y < 0)
			wall.tex_y += wall.tex->height;
		wall.tex_y %= wall.tex->height;
		wall.tex_pos += wall.step;
		wall.color = *((unsigned int *)(wall.tex->addr
					+ wall.tex_y * wall.tex->line_length
					+ wall.tex_x * (wall.tex->bpp / 8)));
		if ((y[2] >= H_WIN - all->minimap->map_height_px + 1)
			&& (all->raycast->pos_px_x > W_WIN - all->minimap->map_width_px))
			break ;
		else
			put_pixel(all->screen, all->raycast->pos_px_x, y[2]++, wall.color);
	}
}
