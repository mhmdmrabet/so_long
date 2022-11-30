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
	if (ft_check_map(map) == 0)
		printf("MAP : ERROR\n");
	else
		printf("MAP : SUCCESS\n");
	return (0);
}
