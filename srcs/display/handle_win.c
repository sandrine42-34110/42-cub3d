/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:28:09 by sapupier          #+#    #+#             */
/*   Updated: 2025/06/23 16:28:10 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (all->mlx->win_ptr)
		mlx_destroy_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
	if (all->mlx->mlx_ptr)
		mlx_destroy_display(all->mlx->mlx_ptr);
	free_all(all);
	exit(0);
}
