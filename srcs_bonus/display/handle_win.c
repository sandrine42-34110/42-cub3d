#include "cub3d_bonus.h"

int	close_window(t_all *all)
{
	if (all->mlx->img_w_n.img)
		mlx_destroy_image(all->mlx->mlx_ptr, all->mlx->img_w_n.img);
	if (all->mlx->img_w_s.img)
		mlx_destroy_image(all->mlx->mlx_ptr, all->mlx->img_w_s.img);
	if (all->mlx->img_w_e.img)
		mlx_destroy_image(all->mlx->mlx_ptr, all->mlx->img_w_e.img);
	if (all->mlx->img_w_w.img)
		mlx_destroy_image(all->mlx->mlx_ptr, all->mlx->img_w_w.img);
	if (all->screen->img)
		mlx_destroy_image(all->mlx->mlx_ptr, all->screen->img);
	#ifdef __linux__
		return (mlx_loop_end(all->mlx->mlx_ptr));
	#else
		(void)all;
		exit(0);
	#endif
}
/* 
int	key_hook(int keycode, t_all *all)
{
	if (keycode == KEY_ESCAPE)
	{
		close_window(all);
	}
	else
		move_player(all, keycode);
	return (0);
} */

int	key_press_hook(int keycode, t_all *all)
{
	if (keycode == KEY_ESCAPE)
		close_window(all);
	else if (keycode == KEY_W_UP)
		all->input.w = 1;
	else if (keycode == KEY_S_DOWN)
		all->input.s = 1;
	else if (keycode == KEY_A_LEFT)
		all->input.a = 1;
	else if (keycode == KEY_D_RIGHT)
		all->input.d = 1;
	else if (keycode == KEY_ARROW_LEFT)
		all->input.left = 1;
	else if (keycode == KEY_ARROW_RIGHT)
		all->input.right = 1;
	return (0);
}

int	key_release_hook(int keycode, t_all *all)
{
	if (keycode == KEY_W_UP)
		all->input.w = 0;
	else if (keycode == KEY_S_DOWN)
		all->input.s = 0;
	else if (keycode == KEY_A_LEFT)
		all->input.a = 0;
	else if (keycode == KEY_D_RIGHT)
		all->input.d = 0;
	else if (keycode == KEY_ARROW_LEFT)
		all->input.left = 0;
	else if (keycode == KEY_ARROW_RIGHT)
		all->input.right = 0;
	return (0);
}

int	is_walkable(t_all *all, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;

	if (map_y < 0 || map_y >= all->map->h_map || map_x < 0 || map_x >= all->map->w_map)
		return (0); // hors des limites
	if (all->map->line[map_y][map_x] == '1')
		return (0); // mur
	return (1); // case vide
}

void	move_player_by_delta(t_all *all, double dx, double dy)
{
	double	new_x = all->player->x + dx;
	double	new_y = all->player->y + dy;

	if (is_walkable(all, new_x, all->player->y))
		all->player->x = new_x;
	if (is_walkable(all, all->player->x, new_y))
		all->player->y = new_y;
}

int	update_frame(t_all *all)
{
	double	dx = 0;
	double	dy = 0;

	// rotation
	if (all->input.left)
		all->player->or -= ANGLE_ROT;
	if (all->input.right)
		all->player->or += ANGLE_ROT;

	// recalcul du vecteur de mouvement à chaque frame
	if (all->input.w)
	{
		dx += cos(all->player->or) * MOVE_SPEED;
		dy += sin(all->player->or) * MOVE_SPEED;
	}
	if (all->input.s)
	{
		dx -= cos(all->player->or) * MOVE_SPEED;
		dy -= sin(all->player->or) * MOVE_SPEED;
	}
	if (all->input.d)
	{
		dx += cos(all->player->or + M_PI_2) * MOVE_SPEED;
		dy += sin(all->player->or + M_PI_2) * MOVE_SPEED;
	}
	if (all->input.a)
	{
		dx += cos(all->player->or - M_PI_2) * MOVE_SPEED;
		dy += sin(all->player->or - M_PI_2) * MOVE_SPEED;
	}

	// affecte les déplacements et collision
	if (dx != 0 || dy != 0)
		move_player_by_delta(all, dx, dy);

	display_screen(all);
	return (0);
}
