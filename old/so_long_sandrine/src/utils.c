/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:26:33 by sapupier          #+#    #+#             */
/*   Updated: 2025/02/26 11:02:29 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_dimensions(char **map, int *rows, int *cols)
{
	*rows = 0;
	*cols = 0;
	if (!map || !map[0])
		return ;
	while (map[*rows])
		(*rows)++;
	if (*rows > 0)
		*cols = ft_strlen(map[0]);
}

int	check_horizontal_borders(char **map, int rows)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[rows - 1][i] != '\0')
	{
		if (map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_vertical_borders(char **map, int rows)
{
	int	row;
	int	len;

	row = 1;
	while (row < rows - 1)
	{
		len = ft_strlen(map[row]);
		if ((map[row][0] != '1') || (map[row][len - 1] != '1'))
			return (0);
		row++;
	}
	return (1);
}

int	check_borders(char **map)
{
	int	rows;
	int	cols;

	get_map_dimensions(map, &rows, &cols);
	if (rows == 0 || cols == 0)
		return (0);
	return (check_horizontal_borders(map, rows)
		&& check_vertical_borders(map, rows));
}

int	check_characters(t_vars vars, char **map)
{
	int	rows;
	int	i;

	rows = 0;
	while (map[rows] != NULL)
	{
		i = 0;
		while (map[rows][i] != '\0')
		{
			if (map[rows][i] == 'E')
				vars.exit_count++;
			else if (map[rows][i] == 'P')
				vars.start_count++;
			else if (map[rows][i] == 'C')
				vars.item_count++;
			else if (map[rows][i] != '1' && map[rows][i] != '0')
				return (ft_printf("Error\nInvalid character\n"), 1);
			i++;
		}
		rows++;
	}
	if (vars.exit_count != 1 || vars.start_count != 1 || vars.item_count < 1)
		return (ft_printf("Error\nInvalid map\n"), 1);
	return (0);
}
