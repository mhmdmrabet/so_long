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

int	ft_is_characters(char c)
{
	const char		*characters = "01CEP";
	int				i;

	i = 0;
	while (characters[i])
	{
		if (characters[i] == c)
			return (1);
		i++;
	}
	return (0);
}

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
	printf("%s\n", map[0]);
	printf("%s\n", map[1]);
	printf("%s\n", map[2]);
	if (ft_is_rectangle_map(map, len_map) == 0)
		printf("RECTANGLE : ERROR\n");
	else
		printf("RECTANGLE : SUCCESS\n");
	if (ft_is_border_map_ok(map, len_map) == 0)
		printf("WALL : ERROR\n");
	else
		printf("WALL : SUCCESS\n");
	return (0);
}
