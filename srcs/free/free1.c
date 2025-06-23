/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:28:35 by sapupier          #+#    #+#             */
/*   Updated: 2025/06/23 16:28:36 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	free_map_copy(char **map_copy, int height)
{
	int	y;

	if (!map_copy)
		return ;
	y = 0;
	while (y < height)
	{
		if (map_copy[y])
			free(map_copy[y]);
		y++;
	}
	free(map_copy);
}
