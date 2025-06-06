#include "cub3d.h"

int main(int argc, char **argv)
{
	t_all	*all;
	
	all = init_all(argc, argv);
	if (!all)
		return (1);
	parse_map(all, argv[1]);
	check_text_and_map(all);
	all->mlx = init_mlx(all);
	ft_printf("avant disp\n");
	display_minimap(all);
	ft_printf("apres disp\n");
	mlx_hook(all->mlx->win_ptr, 17, 0, close_window, &all);
	//mlx_hook(all->mlx->win_ptr, 2, (1L << 0), key_hook, &all);
	mlx_loop(all->mlx->mlx_ptr);

	ft_printf("ok!\n");
	// free_text_and_map(all);
	return (0);
}
