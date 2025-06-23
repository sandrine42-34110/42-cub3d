/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:29:11 by sapupier          #+#    #+#             */
/*   Updated: 2025/06/23 16:29:12 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_hook(int keycode, t_all *all)
{
	if (keycode == KEY_ESCAPE)
		close_window(all);
	else if (keycode == KEY_W_UP)
		all->input.w = 1;
	else if (keycode == KEY_S_DOWN)
		all->input.s = 1;
	else if (keycode == KEY_A_LEFT)
		all->input.a = 1;
	else if (keycode == KEY_D_RIGHT)
		all->input.d = 1;
	else if (keycode == KEY_ARROW_LEFT)
		all->input.left = 1;
	else if (keycode == KEY_ARROW_RIGHT)
		all->input.right = 1;
	return (0);
}

int	key_release_hook(int keycode, t_all *all)
{
	if (keycode == KEY_W_UP)
		all->input.w = 0;
	else if (keycode == KEY_S_DOWN)
		all->input.s = 0;
	else if (keycode == KEY_A_LEFT)
		all->input.a = 0;
	else if (keycode == KEY_D_RIGHT)
		all->input.d = 0;
	else if (keycode == KEY_ARROW_LEFT)
		all->input.left = 0;
	else if (keycode == KEY_ARROW_RIGHT)
		all->input.right = 0;
	return (0);
}
