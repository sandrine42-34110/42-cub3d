/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:28:30 by sapupier          #+#    #+#             */
/*   Updated: 2025/06/23 16:28:31 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
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
		free(mlx->mlx_ptr);
	}
	free(mlx);
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

void	free_display(t_all *all)
{
	if (all->minimap)
		free(all->minimap);
	if (all->player)
		free(all->player);
	if (all->raycast)
		free(all->raycast);
	if (all->screen)
		free(all->screen);
}

void	free_all(t_all *all)
{
	if (all)
	{
		free_text(all->text);
		free_map(all->map);
		free_display(all);
		free_mlx(all->mlx);
		free(all);
	}
}
