/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:29:42 by sapupier          #+#    #+#             */
/*   Updated: 2025/06/24 10:36:27 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_msg_and_close(char *msg, t_all *all)
{
	ft_putstr_fd(msg, 2);
	free_text_and_map(all);
	exit(1);
}

void	error_and_close_all(char *msg, t_all *all)
{
	ft_putstr_fd(msg, 2);
	free_all(all);
	exit(1);
}

int	handle_line(t_all *all, char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	if (is_texture(line + i))
		handle_textures(all, line, fd);
	else if (is_color(line + i))
		handle_colors(all, line, fd);
	else if (line[i] == '0' || line[i] == '1')
		return (1);
	else
	{
		go_to_end_fd(fd, line);
		error_msg_and_close("Error: Invalid line\n", all);
	}
	return (0);
}

void	handle_file(t_all *all, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	all->fd = fd;
	line = get_next_line(fd);
	while (line)
	{
		if (handle_line(all, line, fd))
			break ;
		free(line);
		line = get_next_line(fd);
		all->pos_line_read_file++;
	}
	handle_map(all, line, fd);
	close(fd);
}

void	parse_map(t_all *all, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_msg_and_close("Error : Opening file failed!", all);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		error_msg_and_close("Error : Map file is empty!\n", all);
	}
	while (line)
	{
		all->height_file++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	handle_file(all, file);
}
