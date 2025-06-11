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

// int	close_window(t_all *all)
// {
// 	#ifdef __linux__
// 		mlx_loop_end(all->mlx->mlx_ptr);
// 	#endif
// 		free_all(all);
	
// 	exit(1);
// 	return (0);
// }

int	close_window(t_all *all)
{

	// free_all(all);
	return (mlx_loop_end(all->mlx->mlx_ptr));
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
