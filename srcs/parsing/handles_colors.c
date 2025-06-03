#include "cub3d.h"

int	ft_isdigit_and_spaces (char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (!((c[i] >= '0' && c[i] <= '9')
			|| c[i] == ' '
			|| c[i] == '\t'
			|| c[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}
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
	if ((split[1] && split[1][0] != '\n')
		&& (split[2] && split[2][0] != '\n')
		&& (split[3] && split[3][0] != '\n'))
		ft_free_split(split, "Error: number of arguments for colors\n");
	i = -1;
	while (++i < 3)
	{
		if(!ft_isdigit_and_spaces(split[i]))
			ft_free_split(split, "Error : RGB value must be a number\n");
		val = ft_atoi(split[i]);
		if (val < 0 || val > 255)
			ft_free_split(split, "Error : RGB value out of limits\n");
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

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == 'F')
	{
		if (all->text->floor)
			error_msg_and_close("Error: duplicate floor color\n");				//a surement modifier (surtout les free)
		set_color(all, 'F', line + i + 1);
		all->text->floor = 1;
	}
	else if (line[i] == 'C')
	{	
		if (all->text->ceiling)
			error_msg_and_close("Error: duplicate ceiling color\n");			//a surement modifier (surtout les free)
		set_color(all, 'C', line + i + 1);
		all->text->ceiling = 1;
	}
	else
	{
		error_msg_and_close("Error: duplicate or invalid color\n");
	}
}
