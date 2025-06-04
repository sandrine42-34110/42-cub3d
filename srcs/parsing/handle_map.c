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

void	fill_map(char *line, t_all *all, int *i)
{
	int	len_line;

	len_line = ft_strlen(line);
	all->map->line[*i] = ft_strndup(line, len_line - 1);
	// if (!all->map->line[i])
	//	error_map("add line map failed!", all);									//a ecrire free toutes les lignes avant
	(*i)++;
}

void check_spaces_and_bn(char *line, int j)
{
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] != '\0' && line[j] != '\n')
		error_msg_and_close("Error: map is not at the end of fd\n");			// a ecrire
}

void	handle_map(t_all *all, char *line, int fd)
{
	int	i;
	int	j;

	i = 0;
	all->map->line = malloc(sizeof(char *)
		* (all->height_file - all->pos_line_read_file + 1));
	// if (!all->map->line)
	//	error_map("malloc map->line failed!", all);								//a ecrire 
	while(line)
	{
		j = 0;
		while (line[j] && (line[j] == ' ' || line[j] == '\t'))
			j++;
		if (line[j] == '1')
		{
			fill_map(line, all, &i);
			free(line);
			line = get_next_line(fd);
		}
		else
		{
			check_spaces_and_bn(line, j);
			free(line);
			line = get_next_line(fd);
		}
	}
	all->map->line[i] = NULL;
	print_map(all);																//a supprimer
}

/* void	handle_map(t_all *all, char *line, int fd)
{
	int	i;
	int	j;
	int	len_line;

	i = 0;
	all->map->line = malloc(sizeof(char *)
		* (all->height_file - all->pos_line_read_file + 1));
	// if (!all->map->line)
	//	error_map("malloc map->line failed!", all);								//a ecrire 
	while(line)
	{
		j = 0;
		while (line[j] && (line[j] == ' ' || line[j] == '\t'))
			j++;
		if (line[j] == '1')
		{
			len_line = ft_strlen(line);
			all->map->line[i] = ft_strndup(line, len_line - 1);
			// if (!all->map->line[i])
			//	error_map("add line map failed!", all);							//a ecrire free toutes les lignes avant
			i++;
			free(line);
			line = get_next_line(fd);
		}
		else
		{
			free(line);
			line = get_next_line(fd);
		}
	}
	all->map->line[i] = NULL;
	print_map(all);																//a supprimer
} */
