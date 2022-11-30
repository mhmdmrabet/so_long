/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:42:28 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/28 18:42:28 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

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

int	ft_fill_map(const char *pathname, char **map, int len_map)
{
	int		fd;
	int		i;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (!map)
		return (-1);
	i = 0;
	while (i < len_map)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[len_map] = NULL;
	close(fd);
	return (0);
}

int	main(void)
{
	const char	*pathname = "./maps/Map.ber";
	char		**map;
	int			len_map;

	len_map = ft_count_line(pathname);
	if (len_map < 0)
		return (ft_printf("Error\n"), -1);
	map = malloc((len_map + 1) * sizeof(char *));
	if (ft_fill_map(pathname, map, len_map) != 0)
		return (ft_printf("Error\n"), -1);
	printf("%s", map[0]);
	printf("%s", map[1]);
	printf("%s", map[2]);
	printf("%s", map[3]);
	printf("%s", map[4]);
	printf("%s", map[5]);
	return (0);
}
