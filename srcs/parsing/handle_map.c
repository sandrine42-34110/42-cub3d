#include "cub3d.h"

void	print_map(t_all *all)
{
	int	i;

	i = 0;
	while (all->map->line[i])
	{
		ft_printf("|%s|\n", all->map->line[i]);
		i++;
	}
}

void	fill_map(char *line, t_all *all, int *i, int fd)
{
	char	*trim;
	int		len_line;

	trim = ft_strtrim(line, "\n");
	len_line = ft_strlen(trim);
	if (!all->map->w_map)
		all->map->w_map = len_line;
	if (len_line > all->map->w_map)
		all->map->w_map = len_line;
	all->map->line[*i] = ft_strdup(trim);
	if (!all->map->line[*i])
	{
		go_to_end_fd(fd, line);
		free(trim);
		error_msg_and_close("Error : Add line map failed!", all);
	}
	(*i)++;
	all->map->h_map = *i;
	free(trim);
}

void	taller_line(t_all *all)
{
	int		x;
	int		y;
	char	*new_line;
	char	*temp;

	y = 0;
	while (y < all->map->h_map)
	{
		x = ft_strlen(all->map->line[y]);
		if (x < all->map->w_map)
		{
			new_line = ft_strdup(all->map->line[y]);
			free(all->map->line[y]);
			while(x < all->map->w_map)
			{
				temp = ft_strjoin(new_line, " ");
				free (new_line);
				new_line = temp;
				x++;
			}
			all->map->line[y] = new_line;
		}
		y++;
	}
}

void	check_spaces_and_bn(char *line, int j, t_all *all, int fd)
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
				error_msg_and_close("Error: Map isn't at the end of fd\n", all);
			}
			free(line);
			line = get_next_line(fd);
		}
	}
	taller_line(all);
}

void	handle_map(t_all *all, char *line, int fd)
{
	int	i;
	int	j;

	i = 0;
	all->map->h_map = all->height_file - all->pos_line_read_file;
	all->map->line = malloc(sizeof(char *) * (all->map->h_map + 1));
	if (!all->map->line)
	{
		go_to_end_fd(fd, line);
		error_msg_and_close("Error : Malloc map->line failed!", all);
	}
	while (line)
	{
		j = 0;
		while (line[j] && (line[j] == ' ' || line[j] == '\t'))
			j++;
		if (line[j] =='0' || line[j] == '1')
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
