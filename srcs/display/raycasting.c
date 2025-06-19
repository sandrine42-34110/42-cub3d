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


/* -------- init du DDA ----------------------------------------------------- */
static void	dda_init(t_all *all, int *mx, int *my,
						double d[8]) /* dirx,diry,ddx,ddy,sx,sy,sdx,sdy */
{
	*mx = (int)all->raycast->px;
	*my = (int)all->raycast->py;
	d[0] = all->raycast->ray_dir_x;
	d[1] = all->raycast->ray_dir_y;
	d[2] = fabs(1.0 / d[0]);
	d[3] = fabs(1.0 / d[1]);
	if (d[0] < 0)
	{
		d[4] = -1;
		d[6] = (all->raycast->px - *mx) * d[2];
	}
	else
	{
		d[4] = 1;
		d[6] = (*mx + 1.0 - all->raycast->px) * d[2];
	}
	if (d[1] < 0)
	{
		d[5] = -1;
		d[7] = (all->raycast->py - *my) * d[3];
	}
	else
	{
		d[5] = 1;
		d[7] = (*my + 1.0 - all->raycast->py) * d[3];
	}
}

/* -------- boucle : avance jusqu’au mur ----------------------------------- */
static void	dda_loop(t_all *all, int mx, int my, double d[8])
{
	int	side;

	while (all->map->line[my][mx] != '1')
	{
		if (d[6] < d[7])
		{
			d[6] += d[2];
			mx += (int)d[4];
			side = 0;
		}
		else
		{
			d[7] += d[3];
			my += (int)d[5];
			side = 1;
		}
	}
	if (side == 0)
		all->raycast->perp = (mx - all->raycast->px
				+ (1 - (int)d[4]) / 2.0) / d[0];
	else
		all->raycast->perp = (my - all->raycast->py
				+ (1 - (int)d[5]) / 2.0) / d[1];
	all->raycast->ray_x = all->raycast->px + all->raycast->perp * d[0];
	all->raycast->ray_y = all->raycast->py + all->raycast->perp * d[1];
	if (!side && d[4] > 0)
		all->raycast->wall_tex = TEX_WE;
	else if (!side)
		all->raycast->wall_tex = TEX_EA;
	else if (side && d[5] > 0)
		all->raycast->wall_tex = TEX_NO;
	else
		all->raycast->wall_tex = TEX_SO;
}

/* -------- fonction à appeler depuis draw_vision_line --------------------- */
void	dda_cast(t_all *all)
{
	int		mx;
	int		my;
	double	d[8];

	dda_init(all, &mx, &my, d);
	dda_loop(all, mx, my, d);
}

void	draw_vision_line(t_all *all)
{
	all->raycast->px = all->player->x;
	all->raycast->py = all->player->y;
	dda_cast(all);
	draw_walls(all);
	all->raycast->start_x = all->minimap->offset_x + all->raycast->px * all->mlx->tile_size;
	all->raycast->start_y = all->minimap->offset_y + all->raycast->py * all->mlx->tile_size;
	all->raycast->end_x = all->minimap->offset_x + all->raycast->ray_x * all->mlx->tile_size;
	all->raycast->end_y = all->minimap->offset_y + all->raycast->ray_y * all->mlx->tile_size;
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
}
