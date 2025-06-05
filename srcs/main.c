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
	display_map(all);
	
	ft_printf("ok!\n");
	free_text_and_map(all);
	return (0);
}
