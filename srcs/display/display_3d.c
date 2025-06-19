#include "cub3d.h"

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

	color = ((all->text->floor_r << 16) | (all->text->floor_g << 8)
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
	double h;

	if (all->raycast->perp < 0.0001)
		all->raycast->perp = 0.0001;
	h = (1.0 / all->raycast->perp) * ((W_WIN / 2.0) / tan(FOV_RAD / 2.0));
	*y_0 = (int)((H_WIN - h) / 2.0);
	*y_1 = (int)((H_WIN + h) / 2.0);
	if (*y_0 < 0)
		*y_0 = 0;
	if (*y_1 >= H_WIN)
		*y_1 = H_WIN - 1;
	return (h);
}

void	wall_tex(t_all *all, t_wall *will, double h, int y_0)
{
	if (all->raycast->wall_tex == TEX_NO)
		will->tex = &all->mlx->img_w_n;
	else if (all->raycast->wall_tex == TEX_SO)
		will->tex = &all->mlx->img_w_s;
	else if (all->raycast->wall_tex == TEX_WE)
		will->tex = &all->mlx->img_w_w;
	else
		will->tex = &all->mlx->img_w_e;
	if (all->raycast->wall_tex == TEX_NO || all->raycast->wall_tex == TEX_SO)
		will->wall_x = all->raycast->ray_x;
	else
		will->wall_x = all->raycast->ray_y;
	will->wall_x -= floor(will->wall_x);
	will->tex_x = (int)(will->wall_x * (double)will->tex->width);
	if (will->tex_x < 0)
		will->tex_x += will->tex->width;
	if ((all->raycast->wall_tex == TEX_EA || all->raycast->wall_tex == TEX_NO))
		will->tex_x = will->tex->width - will->tex_x - 1;
	// ← Rendu ligne par ligne verticalement
	will->step = (double)will->tex->height / h;
	will->tex_pos = (y_0 - H_WIN / 2.0 + h / 2.0) * will->step;
}

void	draw_walls(t_all *all)
{
	t_wall	will;
	double	h;
	int		y[3];

	h = height_wall(all, &y[0], &y[1]);
	wall_tex(all, &will, h, y[0]);
	y[2] = y[0];
	while (y[2] < y[1])
	{
		will.tex_y = (int)will.tex_pos & (will.tex->height - 1);
		if (will.tex_y < 0)
			will.tex_y += will.tex->height;
		will.tex_pos += will.step;
		will.color = *((unsigned int *)(will.tex->addr
			+ will.tex_y * will.tex->line_length
			+ will.tex_x * (will.tex->bpp / 8)));
		if ((y[2] >= H_WIN - all->minimap->map_height_px + 1)
			&& (all->raycast->pos_px_x > W_WIN - all->minimap->map_width_px))
			break ;
		else
			put_pixel(all->screen, all->raycast->pos_px_x, y[2]++, will.color);
	}
}

/* 
void	draw_walls(t_all *all)
{
	double	perp;
	double	h;
	int		y_start, y_end;
	int		y;
	double	step;
	double	tex_pos;
	int		tex_x, tex_y;
	t_img	*tex;
	double	wall_x;
	int		color;
	
	perp = all->raycast->perp;
	if (perp < 0.0001)
		perp = 0.0001;
	h = (1.0 / perp) * ((W_WIN / 2.0) / tan(FOV_RAD / 2.0));
	y_start = (int)((H_WIN - h) / 2.0);
	y_end = (int)((H_WIN + h) / 2.0);
	if (y_start < 0)
		y_start = 0;
	if (y_end >= H_WIN)
		y_end = H_WIN - 1;
	// ← Texture à utiliser selon wall_tex
	if (all->raycast->wall_tex == TEX_NO)
		tex = &all->mlx->img_w_n;
	else if (all->raycast->wall_tex == TEX_SO)
		tex = &all->mlx->img_w_s;
	else if (all->raycast->wall_tex == TEX_WE)
		tex = &all->mlx->img_w_w;
	else
		tex = &all->mlx->img_w_e;
	// ← Calcul tex_x (position horizontale sur la texture)
	if (all->raycast->wall_tex == TEX_NO || all->raycast->wall_tex == TEX_SO)
		wall_x = all->raycast->ray_x;
	else
		wall_x = all->raycast->ray_y;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if (tex_x < 0)
		tex_x += tex->width;
	if ((all->raycast->wall_tex == TEX_EA || all->raycast->wall_tex == TEX_NO))
		tex_x = tex->width - tex_x - 1;
	// ← Rendu ligne par ligne verticalement
	step = (double)tex->height / h;
	tex_pos = (y_start - H_WIN / 2.0 + h / 2.0) * step;
	y = y_start;
	while (y < y_end)
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		if (tex_y < 0)
			tex_y += tex->height;
		tex_pos += step;
		color = *((unsigned int *)(tex->addr + tex_y * tex->line_length + tex_x * (tex->bpp / 8)));
		if ((y >= H_WIN - all->minimap->map_height_px + 1) && (all->raycast->pos_px_x > W_WIN - all->minimap->map_width_px))
			break ;
		else
			put_pixel(all->screen, all->raycast->pos_px_x, y++, color);
	}
}
 */

