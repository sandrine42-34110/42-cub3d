/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:40:30 by sapupier          #+#    #+#             */
/*   Updated: 2025/03/06 13:31:23 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**init_map(const char *file_path)
{
	char	*line;
	int		fd;
	int		nb_line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (NULL);
	}
	line = get_next_line(fd);
	nb_line = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		nb_line++;
	}
	close(fd);
	return (malloc((nb_line + 1) * sizeof(char *)));
}

int	open_file(const char *file_path)
{
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (-1);
	}
	return (fd);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	close_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

int	read_and_verify_map(int fd, char **map)
{
	char	*line;
	int		i;
	int		base;

	i = 0;
	base = -1;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strtrim(line, "\n");
		free(line);
		if (!map[i])
			return (0);
		if (base == -1)
			base = ft_strlen(map[i]);
		else if ((int)ft_strlen(map[i]) != base)
		{
			ft_printf("Error \nThe map is not a rectangle\n");
			return ((map[i + 1] = NULL), close_file(fd), 0);
		}
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (1);
}

// char	**read_map(const char *file_path)
// {
// 	int		fd;
// 	char	**map;

// 	map = init_map(file_path);
// 	if (!map)
// 		return (NULL);
// 	fd = open_file(file_path);
// 	if (fd == -1)
// 	{
// 		free(map);
// 		return (NULL);
// 	}
// 	if (!read_and_verify_map(fd, map))
// 	{
// 		free_map(map);
// 		close(fd);
// 		return (NULL);
// 	}
// 	close(fd);
// 	return (map);
// }
