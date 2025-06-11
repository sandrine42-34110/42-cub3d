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

/* void	new_pos_player(t_all *all)
{
	int	new_x;
	int	new_y;

	new_x = (int)(all->player->x + all->player->dx);
	new_y = (int)(all->player->y + all->player->dy);
	if (all->map->line[new_y][new_x] != '1')
	{
		all->player->x += all->player->dx;
		all->player->y += all->player->dy;
	}
} */

// void	new_pos_player(t_all *all)
// {
// 	double	new_x = all->player->x + all->player->dx;
// 	double	new_y = all->player->y + all->player->dy;
// 	int		map_x = (int)new_x;
// 	int		map_y = (int)new_y;

// 	if (all->map->line[(int)all->player->y][map_x] != '1')
// 		all->player->x = new_x;
// 	else
// 	{
// 		if (all->player->dx > 0)
// 			all->player->x = map_x - 0.1;
// 		else if (all->player->dx < 0)
// 			all->player->x = map_x + 1.0 + 0.1;
// 	}

// 	if (all->map->line[map_y][(int)all->player->x] != '1')
// 		all->player->y = new_y;
// 	else
// 	{
// 		if (all->player->dy > 0)
// 			all->player->y = map_y - 0.1;
// 		else
// 			all->player->y = map_y + 1.0 + 0.1;
// 	}
// }

void	new_pos_player(t_all *all)
{
	double	new_x = all->player->x + all->player->dx;
	double	new_y = all->player->y + all->player->dy;
	int		map_x = (int)new_x;
	int		map_y = (int)new_y;

	if (all->map->line[(int)all->player->y][map_x] != '1')
		all->player->x = new_x;
	else
	{
		if (all->player->dx > 0 && all->map->line[(int)all->player->y][map_x + 1] == '1' && new_x - (int)new_x > 0.9)
			all->player->x = map_x - 0.1;
		else if (all->player->dx < 0 && all->map->line[(int)all->player->y][map_x - 1] == '1' && new_x - (int)new_x < 0.1)
			all->player->x = map_x + 1.0 + 0.1;
	}

	if (all->map->line[map_y][(int)all->player->x] != '1')
		all->player->y = new_y;
	else
	{
		if (all->player->dy > 0 && all->map->line[map_y][(int)all->player->x] == '1' && new_y - (int)new_y > 0.9)
			all->player->y = map_y - 0.1;
		else if (all->player->dy < 0 && all->map->line[map_y][(int)all->player->x] == '1' && new_y - (int)new_y < 0.1)
			all->player->y = map_y + 1.0 + 0.1;
	}
}






void	move_player(t_all *all, int keycode)
{
	printf("keycode = %d\n posx pl = %.3f - posy pl = %.3f - or pl = %.3f\n", keycode, all->player->x, all->player->y, all->player->or);
	if (keycode == KEY_W_UP || keycode == KEY_S_DOWN
		|| keycode == KEY_A_LEFT || keycode == KEY_D_RIGHT)
	{
		translation(keycode, all->player->or, &all->player->dx,
			&all->player->dy);
		printf("dx = %.3f - dy = %.3f\n", all->player->dx, all->player->dy);
		new_pos_player(all);
		printf("new posx pl = %.3f - new posy pl = %.3f\n",
			all->player->x, all->player->y);
	}
	else if (keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
		rotate(keycode, &all->player->or);
	display_minimap(all);
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