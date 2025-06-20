#include "cub3d.h"

void	check_hit_orientation(t_all *all)
{
	double diff_x = all->raycast->ray_x - floor(all->raycast->ray_x);
	double diff_y = all->raycast->ray_y - floor(all->raycast->ray_y);

	if (diff_x < diff_y)
		all->raycast->hit_vertical = 1;
	else
		all->raycast->hit_vertical = 0;
}

t_img	*get_wall_textures(t_all *all)
{
	if (all->raycast->hit_vertical)
	{
		if (all->raycast->ray_dir_x > 0)
			return (&all->mlx->img_w_e); // mur à l'est
		else
			return (&all->mlx->img_w_w); // mur à l'ouest
	}
	else
	{
		if (all->raycast->ray_dir_y > 0)
			return (&all->mlx->img_w_s); // mur au sud
		else
			return (&all->mlx->img_w_n); // mur au nord
	}
}

void	display_textures(t_all *all)
{
	int	y;
	int	color;
	int	texture_x;
	int	texture_y;
	t_img	*texture;
	printf("DEBUG textures addr: N=%p S=%p E=%p W=%p\n",
		(void *)&all->mlx->img_w_n,
		(void *)&all->mlx->img_w_s,
		(void *)&all->mlx->img_w_e,
		(void *)&all->mlx->img_w_w);
	
	
	texture = get_wall_textures(all);

	
	texture_x = (int)(fmod(all->raycast->ray_x, 1.0) * texture->width);
	if (texture_x < 0)
		texture_x = 0;
	if (texture_x >= all->img->width)
		texture_x = all->img->width - 1;

	y = 0;
	while (y < all->mlx->h_win)
	{
		texture_y = (y * texture->height) / all->mlx->h_win;
		color = ((int *)texture->addr)[texture_y * texture->width + texture_x];
		((int *)all->img->addr)[y * all->mlx->w_win + all->raycast->pos_ray] = color;		y++;
	}
}



