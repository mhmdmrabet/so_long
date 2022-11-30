/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:21:47 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/28 19:21:47 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	ft_count_line(const char *pathname)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 0;
	line = ft_calloc(1, 1);
	if (!line)
		return (free(line), -1);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
	}
	close(fd);
	return (i);
}

int	ft_fill_map(const char *pathname, t_map_info *data)
{
	int		fd;
	int		i;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (!data->map)
		return (-1);
	i = 0;
	while (i < data->len_map)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	data->map[data->len_map] = NULL;
	close(fd);
	return (0);
}

