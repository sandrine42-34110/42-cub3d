#include "cub3d.h"

/* int	close_window(t_all *all)
{
	if (vars->person.img_ptr)
		mlx_destroy_image(vars->mlx, vars->person.img_ptr);
	if (vars->backgrd.img_ptr)
		mlx_destroy_image(vars->mlx, vars->backgrd.img_ptr);
	if (vars->wall.img_ptr)
		mlx_destroy_image(vars->mlx, vars->wall.img_ptr);
	if (vars->door.img_ptr)
		mlx_destroy_image(vars->mlx, vars->door.img_ptr);
	if (vars->collect.img_ptr)
		mlx_destroy_image(vars->mlx, vars->collect.img_ptr);
	free_all(all);
	return (mlx_loop_end(all->mlx->mlx_ptr));
} */

// Fonction À utiliser lorsque on aura plus besoin de travailler sur le Mac
/* int	close_window(t_all *all)
{
	return (mlx_loop_end(all->mlx->mlx_ptr));
} */

// Fonction À supprimer lorsque on aura plus besoin de travailler sur le Mac
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

int	key_hook(int keycode, t_all *all)
{
	if (keycode == KEY_ESCAPE)
	{
		close_window(all);
	}
	else
		move_player(all, keycode);
	return (0);
}
