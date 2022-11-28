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

int	main(void)
{
	int	fd;

	fd = open("./maps/Map.ber", O_RDONLY);
	char	*line;
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = ft_calloc(1, 1);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
	}
	close(fd);
	fd = open("./maps/Map.ber", O_RDONLY);
	map = ft_calloc(i + 1, sizeof(char *));
	if (!map)
		return (-1);
	while (j < i)
	{
		map[j] = get_next_line(fd);
		j++;
	}
	printf("%s", map[0]);
	printf("%s", map[1]);
	printf("%s", map[2]);
	printf("%s", map[3]);
	printf("%s", map[4]);
	printf("%s", map[5]);
	return (-1);
	close(fd);
	return (1);
}