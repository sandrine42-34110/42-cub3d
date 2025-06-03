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

int	handle_line(t_all *all, char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	//if (is_texture(all, line + i))
	if (is_texture(line + i))
		handle_textures(all, line);
	else if (is_color(line + i))
		handle_colors(all, line);
	else if (line[i] == '1')
		return (1);
	else
		error_msg_and_close("Error: invalid line\n");
	return (0);
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

void print_parsing_text(t_all *all)
{
	ft_printf("NO = %s\n", all->text->no);
	ft_printf("SO = %s\n", all->text->so);
	ft_printf("WE = %s\n", all->text->we);
	ft_printf("EA = %s\n", all->text->ea);
	ft_printf("F = r=%d", all->text->floor_r);
	ft_printf(", g=%d", all->text->floor_g);
	ft_printf(", b=%d\n", all->text->floor_b);
	ft_printf("C = r=%d", all->text->ceiling_r);
	ft_printf(", g=%d", all->text->ceiling_g);
	ft_printf(", b= %d\n", all->text->ceiling_b);

}

void	handle_file(t_all *all, char *file)
{
	int	fd;
	char	*line;

	// all->text = malloc(sizeof(t_text));
	// if (!all->text)
	// 	error_msg_and_close("malloc text failed!");
	all->map = malloc(sizeof(t_map));
	if (!all->map)
	{
		//free_text(all->text);								//a ecrire
		error_msg_and_close("malloc map failed!");
	}
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if(handle_line(all, line))
			break ;
		free(line);
		line = get_next_line(fd);
		all->pos_line_read_file++;
	}
	print_parsing_text(all);													// a suppr
	handle_map(all, line, fd); // a écrire
	close(fd);
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
