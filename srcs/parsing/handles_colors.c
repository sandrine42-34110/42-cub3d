#include "cub3d.h"

void	parse_rgb(const char *str, int *rgb)
{
	int		i;
	char	**split;
	int		val;

	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
	{
		ft_free_split(split, "Error : invalid RGB format\n");
	}
	i = -1;
	while (++i < 3)
	{
		val = ft_atoi(split[i]);
		if (val < 0 || val > 255)
		{
			ft_free_split(split, "Error : RGB value out of limits\n");
		}
		rgb[i] = val;
	}
	ft_free_split(split, NULL);
}

void	set_color(t_all *all, char type, const char *str)
{
	int	rgb[3];

	parse_rgb(str, rgb);
	if (type == 'F')
	{
		all->text->floor_r = rgb[0];
		all->text->floor_g = rgb[1];
		all->text->floor_b = rgb[2];
	}
	else if (type == 'C')
	{
		all->text->ceiling_r = rgb[0];
		all->text->ceiling_g = rgb[1];
		all->text->ceiling_b = rgb[2];
	}
	else
		error_msg_and_close("Error : unknown color type\n");
}

int	is_color(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == 'F' || line[i] == 'C')
		return (1);
	return (0);
}

void	handle_colors(t_all *all, char *line)
{
	int		i;
	char	**split;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	split = ft_split(line + i, ' ');
	if (!split || !split[0] || !split[1] || split[2])
	{
		ft_free_split(split, "Error: invalid color\n");
	}
	else if (!ft_strncmp(split[0], "F", 2) && !all->text->floor)
	{
		set_color(all, 'F', split[1]);
		all->text->floor = 1;
	}
	else if (!ft_strncmp(split[0], "C", 2) && !all->text->ceiling)
	{
		set_color(all, 'C', split[1]);
		all->text->ceiling = 1;
	}
	else
	{
		ft_free_split(split, "Error: duplicate or invalid color\n");
	}
}
