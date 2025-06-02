#include "cub3d.h"

void	ft_free_split(char **split, char *msg)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	if (msg)
	{
		ft_putstr_fd(msg, 2);
		exit (1);
	}
}

int	is_texture(t_all *all, char *line)
{
	int		i;
	char	**split;
	int		result;

	(void) all;
	result = 0;
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	split = ft_split(line + i, ' ');
	if (!split || !split[0])
	{
		ft_free_split(split, NULL);
		return (0);
	}
	if (!ft_strncmp(split[0], "NO", 3)
		|| !ft_strncmp(split[0], "SO", 3)
		|| !ft_strncmp(split[0], "WE", 3)
		|| !ft_strncmp(split[0], "EA", 3))
		result = 1;
	ft_free_split(split, NULL);
	return (result);
}

void	handle_textures(t_all *all, char *line)
{
	int		i;
	char	**split;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	split = ft_split(line + i, ' ');
	if (!split || !split[0] || !split[1] || split[2])
	{
		ft_free_split(split, "Error: invalid texture\n");
	}
	if (!ft_strncmp(split[0], "NO", 3) && !all->text->no)
		all->text->no = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "SO", 3) && !all->text->so)
		all->text->so = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "WE", 3) && !all->text->we)
		all->text->we = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "EA", 3) && !all->text->ea)
		all->text->ea = ft_strdup(split[1]);
	else
	{
		ft_free_split(split, "Error: duplicate or invalid texture\n");
	}
}
