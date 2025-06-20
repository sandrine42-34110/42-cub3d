#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_all	*all;

	all = init_all(argc, argv);
	if (!all)
		return (1);
	parse_map(all, argv[1]);
	check_text_and_map(all);
	all->mlx = init_mlx(all);
	load_images(all);
	all->screen = init_screen(all);
	display_screen(all);
	mlx_hook(all->mlx->win_ptr, 17, 0, close_window, all);
	mlx_hook(all->mlx->win_ptr, 2, (1L << 0), key_hook, all);
	mlx_mouse_hide(all->mlx->mlx_ptr, all->mlx->win_ptr);
	mlx_hook(all->mlx->win_ptr, 6, (1L << 6), mouse_hook, all);
	mlx_loop(all->mlx->mlx_ptr);
	mlx_destroy_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
	#ifdef __linux__															// À supprimer lorsque on aura plus besoin de travailler sur le Mac
		mlx_destroy_display(all->mlx->mlx_ptr);									// À garder lorsque on aura plus besoin de travailler sur le Mac
	#endif																		// À supprimer lorsque on aura plus besoin de travailler sur le Mac
	free_all(all);
	return (0);
}
