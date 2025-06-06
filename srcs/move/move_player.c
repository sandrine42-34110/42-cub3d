#include "cub3d.h"

int	translation(int keycode, double angle, double *dx, double *dy)
{
	if (keycode == KEY_W_UP)
	{
		*dx = cos(angle) * MOVE_SPEED;
		*dy = sin(angle) * MOVE_SPEED;
	}
	else if (keycode == KEY_S_DOWN)
	{
		*dx = -cos(angle) * MOVE_SPEED;
		*dy = -sin(angle) * MOVE_SPEED;
	}
	else if (keycode == KEY_D_RIGHT)
	{
		*dx = cos(angle + pi() / 2) * MOVE_SPEED;
		*dy = sin(angle + pi() / 2) * MOVE_SPEED;
	}
	else if (keycode == KEY_A_LEFT)
	{
		*dx = cos(angle - pi() / 2) * MOVE_SPEED;
		*dy = sin(angle - pi() / 2) * MOVE_SPEED;
	}
	else
		return (1);
	return (0);
}

int	rotate(int keycode, double *or)
{
	if (keycode)
	{
		if (keycode == KEY_ARROW_RIGHT)
			return (((*or) += ANGLE_ROT), 0);
		else if (keycode == KEY_ARROW_LEFT)
			return (((*or) -= ANGLE_ROT), 0);
	}
	return (1);
}

void	new_pos_player(t_all *all)
{
	int	new_x;
	int	new_y;

	new_x = (int)(all->player->x + all->player->dx);
	new_y = (int)(all->player->y + all->player->dy);
	if (all->map->line[new_x][new_y] != '1')
	{
		all->player->x += all->player->dx;
		all->player->y += all->player->dy;
	}
}

void	move_player(t_all *all, int keycode)
{
	if (keycode == KEY_W_UP || keycode == KEY_S_DOWN
		|| keycode == KEY_A_LEFT || keycode == KEY_D_RIGHT)
	{
		translation(keycode, all->player->or, &all->player->dx,
			&all->player->dx);
		new_pos_player(all);
	}
	if (keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
		rotate(keycode, &all->player->or);
}

/* void move_player(t_all *all, int keycode)
{
	double new_x;
	double new_y;

	if (keycode == KEY_W_UP)
	{
		new_x = all->player->x + all->player->dx * MOVE_SPEED;
		new_y = all->player->y + all->player->dy * MOVE_SPEED;
		if (all->map[(int)new_y][(int)new_x] != '1')
		{
			all->pos_x = new_x;
			all->pos_y = new_y;
		}
	}
	if (keycode == KEY_S)
	{
		new_x = all->pos_x - all->dir_x * move_speed;
		new_y = all->pos_y - all->dir_y * move_speed;
		if (all->map[(int)new_y][(int)new_x] != '1')
		{
			all->pos_x = new_x;
			all->pos_y = new_y;
		}
	}
	if (keycode == KEY_A)
	{
		new_x = all->pos_x - all->plane_x * move_speed;
		new_y = all->pos_y - all->plane_y * move_speed;
		if (all->map[(int)new_y][(int)new_x] != '1')
		{
			all->pos_x = new_x;
			all->pos_y = new_y;
		}
	}
	if (keycode == KEY_D)
	{
		new_x = all->pos_x + all->plane_x * move_speed;
		new_y = all->pos_y + all->plane_y * move_speed;
		if (all->map[(int)new_y][(int)new_x] != '1')
		{
			all->pos_x = new_x;
			all->pos_y = new_y;
		}
	}
} */