#include "cub3d.h"

void	free_text(t_text *text)
{
	if (!text)
		return ;
	if (text->no)
		free(text->no);
	if (text->so)
		free(text->so);
	if (text->we)
		free(text->we);
	if (text->ea)
		free(text->ea);
	free(text);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return;
	if (map->line)
	{
		i = 0;
		while (map->line[i])
		{
			free(map->line[i]);
			i++;
		}
	}
	free(map->line);
	free(map);
}

void	free_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->mlx_ptr)
	{
		if (mlx->win_ptr)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		// Assuming you have functions to destroy images if they exist
		// mlx_destroy_image(mlx->mlx_ptr, mlx->img_w_n);
		// mlx_destroy_image(mlx->mlx_ptr, mlx->img_w_s);
		// mlx_destroy_image(mlx->mlx_ptr, mlx->img_w_e);
		// mlx_destroy_image(mlx->mlx_ptr, mlx->img_w_w);
		free(mlx);
	}
}

void	free_text_and_map(t_all *all)
{
	if (all)
	{
		free_text(all->text);
		free_map(all->map);
		free(all);
	}
}

void	free_minimap(t_minimap *minimap)
{
	if (minimap)
		free(minimap);
}

void	free_all(t_all *all)
{
	if (all)
	{
		free_text(all->text);
		free_map(all->map);
		free_mlx(all->mlx);
		if (all->minimap)
			free_minimap(all->minimap);
		free(all);
	}
}