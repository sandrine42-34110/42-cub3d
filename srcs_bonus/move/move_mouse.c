#include "cub3d_bonus.h"

/* int	mouse_hook(int x, int y, t_all *all)
{
	static int	prev_x = -1;

	(void)y;
	if (prev_x == -1)
		prev_x = x;
	if (x > prev_x)
		all->player->or += ANGLE_ROT / 1;
	else if (x < prev_x)
		all->player->or -= ANGLE_ROT / 1;
	prev_x = x;
	display_screen(all);
	return (0);
} */
/* 
int	mouse_hook(int x, int y, t_all *all)
{
	static int	ignore_next = 0;
	int			center_x = W_WIN / 2;

	(void)y;

	if (!all || !all->mlx)
		return (0);

	if (ignore_next)
	{
		ignore_next = 0;
		return (0); // Ignore l'événement déclenché par mlx_mouse_move
	}

	if (x != center_x)
	{
		double delta_angle = (x - center_x) * 0.02; // Ajuste ici la sensibilité
		all->player->or += delta_angle;

		ignore_next = 1; // Signale d'ignorer le prochain appel
		mlx_mouse_move(all->mlx->mlx_ptr, all->mlx->win_ptr, center_x, H_WIN / 2);
		display_screen(all);
	}

	return (0);
} */

/* int	mouse_click_hook(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (button == 1)
		all->player->mouse = 1;
	return (0);
}

int	mouse_hook(int x, int y, t_all *all)
{
	static int	last_x = -1;

	(void)y;
	if (last_x == -1)
		last_x = x;

	if (all->player->mouse == 1)
	{
		if (x >= (W_WIN * 3) / 4 || x <= W_WIN / 4)
			mlx_mouse_move(all->mlx->mlx_ptr, all->mlx->win_ptr, W_WIN / 2, H_WIN / 2);
		if (last_x > x)
			all->player->or -= 0.015;
		else if (last_x < x)
			all->player->or += 0.015;
	}
	last_x = x;
	return (0);
} */
/* 
int	mouse_click_hook(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (button == 1) // clic gauche
	{
		all->player->mouse = 1;
		mlx_mouse_hide(all->mlx->mlx_ptr, all->mlx->win_ptr);
		mlx_mouse_move(all->mlx->mlx_ptr, all->mlx->win_ptr, W_WIN / 2, H_WIN / 2);
	}
	else if (button == 3) // clic droit pour désactiver
	{
		all->player->mouse = 0;
		mlx_mouse_show(all->mlx->mlx_ptr, all->mlx->win_ptr);
	}
	return (0);
}


int	mouse_hook(int x, int y, t_all *all)
{
	static int	last_x = -1;
	int			center_x = W_WIN / 2;

	(void)y;
	if (!all || !all->mlx || !all->player->mouse)
		return (0);

	if (last_x == -1)
		last_x = x;

	// Rotation en fonction du delta
	int delta_x = x - last_x;
	if (delta_x != 0)
		all->player->or += delta_x * 0.003; // sensibilité ajustable

	last_x = x;

	// Si la souris touche les bords : recentrage (sans déclencher de saut)
	if (x >= W_WIN * 3 / 4 || x <= W_WIN / 4)
	{
		last_x = center_x; // met à jour la base de calcul pour éviter le saut
		mlx_mouse_move(all->mlx->mlx_ptr, all->mlx->win_ptr, center_x, H_WIN / 2);
	}

	return (0);
} */

/* 
int	mouse_hook(int x, int y, t_all *all)
{
	static int	last_x = -1;
	int			center_x = W_WIN / 2;

	(void)y;
	if (!all || !all->mlx || !all->mlx->win_ptr || !all->player->mouse_enabled)
		return (0);

	if (last_x == -1)
		last_x = x;

	if (x != center_x)
	{
		double delta_angle = (x - center_x) * 0.02;
		all->player->or += delta_angle;

		mlx_mouse_move(all->mlx->mlx_ptr, all->mlx->win_ptr, center_x, H_WIN / 2);
		last_x = center_x;
	}

	return (0);
} */


int	mouse_hook(int x, int y, t_all *all)
{
	static int	ignore = 1;
	int	center_x = W_WIN / 2;

	(void)y;
	if (!all || !all->mlx)
		return (0);

	if (!all->input.mouse_locked)
		return (0); // souris libre, on ne fait rien

	if (ignore)
	{
		ignore = 0;
		mlx_mouse_move(all->mlx->mlx_ptr, all->mlx->win_ptr, center_x, H_WIN / 2);
		return (0);
	}

	if (x != center_x)
	{
		double delta_angle = (x - center_x) * 0.02;
		all->player->or += delta_angle;
		mlx_mouse_move(all->mlx->mlx_ptr, all->mlx->win_ptr, center_x, H_WIN / 2);
		display_screen(all);
	}
	return (0);
}
