#include "cub3d.h"

/* void display_map(t_all *all)
{
	
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img_wmm;
	t_data	img_fmm;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img_wmm.img = mlx_new_image(mlx, (W_WIN / 5), (H_WIN / 5));
	img_fmm.img = mlx_new_image(mlx, all->mlx->tile_size, all->mlx->tile_size);

	img_wmm.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img_wmm, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
void	 nom_fonction()
{
void	*minimap_img;
char	*minimap_addr;
int		bpp, line_len, endian;

minimap_img = mlx_new_image(mlx_ptr, map_width, map_height);
minimap_addr = mlx_get_data_addr(minimap_img, &bpp, &line_len, &endian);
}

void	draw_square(char *addr, int x, int y, int color, int tile_size, int line_len, int bpp)
{
	for (int i = 0; i < tile_size; i++)
	{
		for (int j = 0; j < tile_size; j++)
		{
			char *pixel = addr + (y + i) * line_len + (x + j) * (bpp / 8);
			*(unsigned int *)pixel = color;
		}
	}
}

void	render_minimap(t_all *all)
{
	int	tile_size = 10;
	int	color_wall = WCMM;
	int	color_floor = FCMM;

	for (int y = 0; all->map->line[y]; y++)
	{
		for (int x = 0; all->map->line[y][x]; x++)
		{
			if (all->map->line[y][x] == '1')
				draw_square(minimap_addr, x * tile_size, y * tile_size,
							color_wall, tile_size, line_len, bpp);
			else
				draw_square(minimap_addr, x * tile_size, y * tile_size,
							color_floor, tile_size, line_len, bpp);
		}
	}
}

mlx_put_image_to_window(mlx_ptr, win_ptr, minimap_img, 0, 0);

#define TILE_SIZE 8 // taille d'un carré sur la mini-map
 */
void	draw_square(t_mlx *mlx, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
 

void	display_minimap(t_all *all)
{
	int	y;
	int	x;
	int	color;

	y = W_WIN * (4 / 5);
	while (y < all->map->h_map)
	{
		x = H_WIN * (4 / 5);
		while (all->map->line[y][x])
		{
			if (all->map->line[y][x] == '1')
				color = 0xFFFFFF; // blanc pour les murs
			else if (all->map->line[y][x] == '0')
				color = 0x000000; // noir pour le sol
			else if (all->map->line[y][x] == 'N' || all->map->line[y][x] == 'S'
				|| all->map->line[y][x] == 'E' || all->map->line[y][x] == 'W')
				color = 0xFF0000; // rouge pour le joueur a supprimer apres
			else
				color = 0x888888; // gris pour le reste
			draw_square(all->mlx, x * all->mlx->tile_size,
				y * all->mlx->tile_size, all->mlx->tile_size, color);
			x++;
		}
		y++;
	}
}
