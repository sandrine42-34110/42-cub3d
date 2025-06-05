/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:31:11 by sapupier          #+#    #+#             */
/*   Updated: 2025/02/26 13:38:03 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		n;
	int		i;
	int		j;

	n = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	dest = (char *)malloc((n + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

static char	*read_line(int fd, char *stash)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*temp;

	if (!stash)
	{
		stash = malloc(1);
		stash[0] = 0;
	}
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(stash), NULL);
		buf[bytes_read] = '\0';
		temp = ft_strjoin(stash, buf);
		free(stash);
		stash = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

static char	*get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 2);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

static char	*get_line_next(char *stash)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	next_line = malloc(ft_strlen(stash) - i + 1);
	i++;
	while (stash[i])
		next_line[j++] = stash[i++];
	next_line[j] = 0;
	free(stash);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_line(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = get_line(stash[fd]);
	stash[fd] = get_line_next(stash[fd]);
	return (line);
}
/*
int main ()
{
	int files = open("examples.txt", O_RDONLY);
	if (files == -1)
		return (1);

	char *line;
	//char *stash;
	while ((line = get_next_line(files)) != NULL)
	{
		printf("%s", line);
		free (line);
	}
	close(files);
	return (0);
}*/
