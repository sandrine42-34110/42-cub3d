#include "cub3d.h"

void	error_msg_and_close(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

/* void	handle_line(t_all *all, char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return ;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
		|| line[i] == 'F' || line[i] == 'C')
		handle_textures(all, line);
	else if (line[i] == '1')
		handle_map(all, line);	//a ecrire
} */

void	handle_line(t_all *all, char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return ;
	// if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
	// 	|| line[i] == 'F' || line[i] == 'C')
	// 	handle_textures(all, line);
	// else if (line[i] == '1')
	// 	handle_map(all, line);	//a ecrire
	if (is_texture(all, line + i))
		handle_textures(all, line);
	else if (is_color(line + i))
		handle_colors(all, line);
//	else if (line[i] == '1')
//		handle_map(all, line); // à écrire
	else
		error_msg_and_close("Error: invalid line\n");




}

/* void	handle_file(t_all *all, char *file)
{
	int	fd;
	char	*line;

	all->text = malloc(sizeof(t_text));
	if (!all->text)
		error_msg_and_close("malloc text failed!");
	all->map = malloc(sizeof(t_map));
	if (!all->map)
	{
		free_text(all->text);								//a ecrire
		error_msg_and_close("malloc map failed!");
	}
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		handle_line(all, line);	//a ecrire
		free(line);
		line = get_next_line(fd);
	}
} */

void	handle_file(t_all *all, char *file)
{
	int	fd;
	char	*line;

	// all->text = malloc(sizeof(t_text));
	// if (!all->text)
	// 	error_msg_and_close("malloc text failed!");
	// all->map = malloc(sizeof(t_map));
	// if (!all->map)
	// {
	// 	free_text(all->text);								//a ecrire
	// 	error_msg_and_close("malloc map failed!");
	// }
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		handle_line(all, line);	//a ecrire
		free(line);
		line = get_next_line(fd);
	}
}

void	parse_map(t_all *all, char *file)
{
	int	fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_msg_and_close("Opening file failed!");
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		error_msg_and_close("Map file is empty!");
	}
	while (line)
	{
		all->height_file++;
		line = get_next_line(fd);
	}
	close(fd);
	handle_file(all, file);
}
