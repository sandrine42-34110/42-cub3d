#include "cub3d.h"

void print_map(t_all *all)
{
	int	i;

	i = 0;
	while (all->map->line[i])
	{
		ft_printf("%s\n", all->map->line[i]);
		i++;
	}
}

/* void	fill_map(char *line, t_all *all, int *i)
{
	int	len_line;

	len_line = ft_strlen(line);
	all->map->line[*i] = ft_strndup(line, len_line - 1);
	if (!all->map->line[*i])
		error_msg_and_close("add line map failed!", all);
	(*i)++;
}

void check_spaces_and_bn(char *line, int j, t_all *all)
{
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] != '\0' && line[j] != '\n')
	{
		free(line);
		error_msg_and_close("Error: map is not at the end of fd\n", all);
	}
}

void	handle_map(t_all *all, char *line, int fd)
{
	int	i;
	int	j;

	i = 0;
	all->map->line = malloc(sizeof(char *)
		* (all->height_file - all->pos_line_read_file + 1));
	if (!all->map->line)
		error_msg_and_close("malloc map->line failed!",  all);
	while(line)
	{
		j = 0;
		while (line[j] && (line[j] == ' ' || line[j] == '\t'))
			j++;
		if (line[j] == '1')
			fill_map(line, all, &i);
		else
			check_spaces_and_bn(line, j, all);
		free(line);
		line = get_next_line(fd);
	}
	all->map->line[i] = NULL;

	print_map(all);																//a supprimer
} */

void	fill_map(char *line, t_all *all, int *i, int fd)
{
	char	*trim;

	trim = ft_strtrim(line, "\n");
	all->map->line[*i] = ft_strdup(trim);
	if (!all->map->line[*i])
	{
		go_to_end_fd(fd, line);
		free(trim);
		error_msg_and_close("add line map failed!", all);
	}
	(*i)++;
	free(trim);
}

void check_spaces_and_bn(char *line, int j, t_all *all, int fd)
{
	if (line)
	{
		while (line)
		{
			while (line[j] && (line[j] == ' ' || line[j] == '\t'))
				j++;
			if (line[j] != '\0' && line[j] != '\n')
			{
				go_to_end_fd(fd, line);
				error_msg_and_close("Error: map isn't at the end of fd\n", all);
			}
			free(line);
			line = get_next_line(fd);
		}
	}
}

void	handle_map(t_all *all, char *line, int fd)
{
	int	i;
	int	j;

	i = 0;
	all->map->line = malloc(sizeof(char *)
		* (all->height_file - all->pos_line_read_file + 1));
	if (!all->map->line)
	{
		go_to_end_fd(fd, line);
		error_msg_and_close("malloc map->line failed!", all);
	}
	while (line)
	{
		j = 0;
		while (line[j] && (line[j] == ' ' || line[j] == '\t'))
			j++;
		if (line[j] == '1')
			fill_map(line, all, &i, fd);
		else
			break ;
		free(line);
		line = get_next_line(fd);
	}
	all->map->line[i] = NULL;
	check_spaces_and_bn(line, j, all, fd);
	//print_map(all);																//a supprimer
}
