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
}


