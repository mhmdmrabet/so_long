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

void	ft_parsing(int fd)
{
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
	map = ft_calloc(i + 1, sizeof(char *));
	if (!map)
		return ;
	printf("READ %zd", read(fd, line, 8250));
	while (j < i)
	{
		map[j] = get_next_line(fd);
		printf("%s", map[j]);
		j++;
	}
	// while (j > 0)
	// {
	// 	printf("%s", map[0]);
	// 	j--;
	// }
	return ;
}
