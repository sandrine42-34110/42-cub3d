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
		*dx = cos(angle + M_PI / 2) * MOVE_SPEED;
		*dy = sin(angle + M_PI / 2) * MOVE_SPEED;
	}
	else if (keycode == KEY_A_LEFT)
	{
		*dx = cos(angle - M_PI / 2) * MOVE_SPEED;
		*dy = sin(angle - M_PI / 2) * MOVE_SPEED;
	}
	else
		return (1);
	return (0);
}

void	rotate(int keycode, double *or)
{
	if (keycode)
	{
		if (keycode == KEY_ARROW_RIGHT)
			(*or) += ANGLE_ROT;
		else if (keycode == KEY_ARROW_LEFT)
			(*or) -= ANGLE_ROT;
	}
	return ;
}

void	new_pos_player(t_all *all)
{
	double	new_x;
	double	new_y;

	new_x = all->player->x + all->player->dx;
	new_y = all->player->y + all->player->dy;
	if (all->player->dx < 0)
	{
		if (all->map->line[(int)all->player->y][(int)(new_x - COLL_PAD)] != '1')
			all->player->x = new_x;
	}
	else
	{
		if (all->map->line[(int)all->player->y][(int)(new_x + COLL_PAD)] != '1')
			all->player->x = new_x;
	}
	if (all->player->dy < 0)
	{
		if (all->map->line[(int)(new_y - COLL_PAD)][(int)all->player->x] != '1')
			all->player->y = new_y;
	}
	else
	{
		if (all->map->line[(int)(new_y + COLL_PAD)][(int)all->player->x] != '1')
			all->player->y = new_y;
	}
}

void	move_player(t_all *all, int keycode)
{
	if (keycode == KEY_W_UP || keycode == KEY_S_DOWN
		|| keycode == KEY_A_LEFT || keycode == KEY_D_RIGHT)
	{
		translation(keycode, all->player->or, &all->player->dx,
			&all->player->dy);
		new_pos_player(all);
	}
	else if (keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
		rotate(keycode, &all->player->or);
	display_minimap(all);
}
