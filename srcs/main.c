/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:29:48 by sapupier          #+#    #+#             */
/*   Updated: 2025/06/23 17:02:15 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	mlx_hook(all->mlx->win_ptr, KeyPress, KeyPressMask, key_press_hook, all);
	mlx_hook(all->mlx->win_ptr, KeyRelease, KeyReleaseMask, key_release_hook,
		all);
	mlx_loop_hook(all->mlx->mlx_ptr, update_frame, all);
	mlx_loop(all->mlx->mlx_ptr);
	return (0);
}
