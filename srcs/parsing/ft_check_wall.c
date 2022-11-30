/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:20:04 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/30 15:20:04 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	ft_is_wall_top_bottom(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_border_wall(char *line)
{
	int	len_line;
	int	i;

	i = 0;
	len_line = (int)ft_strlen(line);
	while (line[i])
	{
		if (i == 0 || (i + 1 == len_line))
			if (line[i] != '1')
				return (0);
		if (ft_is_characters(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_border_map_ok(char **map, int len_map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (i == 0 || (i + 1 == len_map))
		{
			if (ft_is_wall_top_bottom(map[i]) == 0)
				return (0);
		}
		else
			if (ft_is_border_wall(map[i]) == 0)
				return (0);
		i++;
	}
	return (1);
}

int	ft_is_rectangle_map(char **map, int len_map)
{
	int	len_line;
	int	tmp;
	int	i;

	i = 1;
	len_line = (int)ft_strlen(map[0]);
	if (len_line == len_map)
		return (0);
	while (map[i])
	{
		tmp = len_line;
		len_line = (int)ft_strlen(map[i]);
		if (tmp != len_line)
			return (0);
		i++;
	}
	return (1);
}
