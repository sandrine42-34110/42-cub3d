#include "cub3d.h"

void	check_text(t_all *all)
{
	if (all->text->no == NULL || all->text->so == NULL
		|| all->text->we == NULL || all->text->ea == NULL)
		error_msg_and_close("Error: Missing texture information\n", all);
	if (all->text->floor == 0 || all->text->ceiling == 0)
		error_msg_and_close("Error: Missing color information\n", all);
	
}

void	check_map(t_all *all)
{
	if (all->map->h_map < 3)
		error_msg_and_close("Error: Invalid map\n", all);
	check_close_map(all);
}

void	check_text_and_map(t_all *all)
{
	check_text(all);
	check_map(all);
}