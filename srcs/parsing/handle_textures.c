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

/* int	is_texture(t_all *all, char *line)
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
} */

int	is_texture(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if ((line[i] == 'N' && line[i + 1] == 'O')
		|| (line[i] == 'S' && line[i + 1] == 'O')
		|| (line[i] == 'W' && line[i + 1] == 'E')
		|| (line[i] == 'E' && line[i + 1] == 'A'))
		return (1);
	return (0);
}

void	handle_textures(t_all *all, char *line)
{
	int		i;
	char	**split;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	split = ft_split(line + i, ' ');
	if (!split || !split[0] || !split[1])
		ft_free_split(split, "Error: invalid texture\n");
	if (split[2] && split[2][0] != '\n')
		ft_free_split(split, "Error: too many arguments for texture\n");
	if (!ft_strncmp(split[0], "NO", 3) && !all->text->no)
		all->text->no = ft_strdup(ft_strtrim(split[1], "\n"));
	else if (!ft_strncmp(split[0], "SO", 3) && !all->text->so)
		all->text->so = ft_strdup(ft_strtrim(split[1], "\n"));
	else if (!ft_strncmp(split[0], "WE", 3) && !all->text->we)
		all->text->we = ft_strdup(ft_strtrim(split[1], "\n"));
	else if (!ft_strncmp(split[0], "EA", 3) && !all->text->ea)
		all->text->ea = ft_strdup(ft_strtrim(split[1], "\n"));
	else
		ft_free_split(split, "Error: duplicate or invalid texture\n");
}
