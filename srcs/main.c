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
	display_minimap(all);
	//mlx_hook(vars.win, 17, 0, close_window, &vars);
    //    mlx_key_hook(vars.win, key_hook, &vars);
        mlx_loop(all->mlx->mlx_ptr);

	ft_printf("ok!\n");
	free_text_and_map(all);
	return (0);
}
