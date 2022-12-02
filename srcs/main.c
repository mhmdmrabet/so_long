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
	t_map_info	*p_data;
	t_map_info	data;

	p_data = &data;
	p_data->len_map = ft_count_line(pathname);
	if (p_data->len_map < 0)
		return (ft_printf("Error\n"), -1);
	p_data->map = malloc((p_data->len_map + 1) * sizeof(char *));
	if (ft_fill_map(pathname, p_data) != 0)
		return (ft_printf("Error\n"), -1);
	printf("%s\n", p_data->map[0]);
	printf("%s\n", p_data->map[1]);
	printf("%s\n", p_data->map[2]);
	printf("%s\n", p_data->map[3]);
	printf("%s\n", p_data->map[4]);
	printf("%s\n", p_data->map[5]);
	if (ft_is_rectangle_map(p_data) == 0)
		printf("RECTANGLE : ERROR\n");
	else
		printf("RECTANGLE : SUCCESS\n");
	if (ft_is_border_map_ok(p_data) == 0)
		printf("WALL : ERROR\n");
	else
		printf("WALL : SUCCESS\n");
	if (ft_check_map(p_data) == 0)
		printf("MAP : ERROR\n");
	else
		printf("MAP : SUCCESS\n");
	ft_find_exit_horizontal_position(p_data);
	ft_find_depart_horizontal_position(p_data);
	printf("LEN LINE %d\n", p_data->len_line);
	printf("LEN MAP %d\n", p_data->len_map);
	fill_around_depart(p_data);
	ft_print_map(p_data);
	return (0);
}
