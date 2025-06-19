#include "cub3d.h"

void	dda_init(t_all *all, int *mx, int *my, double d[8])
{
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

void	dda_loop(t_all *all, int mx, int my, double d[8])
{
	while (all->map->line[my][mx] != '1')
	{
		if (d[6] < d[7])
		{
			d[6] += d[2];
			mx += (int)d[4];
			all->raycast->side = 0;
		}
		else
		{
			d[7] += d[3];
			my += (int)d[5];
			all->raycast->side = 1;
		}
	}
	if (all->raycast->side == 0)
		all->raycast->perp = (mx - all->raycast->px
				+ (1 - (int)d[4]) / 2.0) / d[0];
	else
		all->raycast->perp = (my - all->raycast->py
				+ (1 - (int)d[5]) / 2.0) / d[1];
	all->raycast->ray_x = all->raycast->px + all->raycast->perp * d[0];
	all->raycast->ray_y = all->raycast->py + all->raycast->perp * d[1];
}

void	attribute_texture(t_all *all, double d[8])
{
	if (!all->raycast->side && d[4] > 0)
		all->raycast->wall_tex = TEX_WE;
	else if (!all->raycast->side)
		all->raycast->wall_tex = TEX_EA;
	else if (all->raycast->side && d[5] > 0)
		all->raycast->wall_tex = TEX_NO;
	else
		all->raycast->wall_tex = TEX_SO;
}

void	dda_cast(t_all *all)
{
	int		mx;
	int		my;
	double	d[8];

	mx = (int)all->raycast->px;
	my = (int)all->raycast->py;
	dda_init(all, &mx, &my, d);
	dda_loop(all, mx, my, d);
	attribute_texture(all, d);
}
