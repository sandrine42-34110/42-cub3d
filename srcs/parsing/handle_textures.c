#include "cub3d.h"

void	ft_free_split(char **split, char *msg, t_all *all)
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
		free_all(all);
		exit (1);
	}
}

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

void	parse_texture(char **split, t_all *all, int fd, char *line)
{
	char	*strim;

	strim = ft_strtrim(split[1], "\n");
	if (!ft_strncmp(split[0], "NO", 3) && !all->text->no)
		all->text->no = ft_strdup(strim);
	else if (!ft_strncmp(split[0], "SO", 3) && !all->text->so)
		all->text->so = ft_strdup(strim);
	else if (!ft_strncmp(split[0], "WE", 3) && !all->text->we)
		all->text->we = ft_strdup(strim);
	else if (!ft_strncmp(split[0], "EA", 3) && !all->text->ea)
		all->text->ea = ft_strdup(strim);
	else
	{
		go_to_end_fd(fd, line);
		free(strim);
		ft_free_split(split, "Error: Duplicate or invalid texture\n", all);
	}
	ft_free_split(split, NULL, all);
	free(strim);
}

void	check_text_name(char *str, t_all *all, int fd)
{
	int	len_text_file;

	len_text_file = ft_strlen(str);
	if (ft_strcmp(".xpm",str + len_text_file - 4) == 0)
		return ;
	go_to_end_fd(fd, str);
	error_msg_and_close("Error: Texture file must be a .xpm file\n", all);
}

void	handle_textures(t_all *all, char *line, int fd)
{
	int		i;
	char	**split;

	check_text_name(line, all, fd);
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	split = ft_split(line + i, ' ');
	if (!split || !split[0] || !split[1])
	{
		go_to_end_fd(fd, line);
		ft_free_split(split, "Error: Invalid texture\n", all);
	}
	if (split[2] && split[2][0] != '\n')
	{
		go_to_end_fd(fd, line);
		ft_free_split(split, "Error: Too many arguments for texture\n", all);
	}
	parse_texture(split, all, fd, line);
}
