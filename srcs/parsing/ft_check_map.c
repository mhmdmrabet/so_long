/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:28:54 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/30 15:28:54 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	ft_check_map(char *pathname, t_map_info *data)
{
	const char	error[] = "Error\n";

	data->len_map = ft_count_line(pathname);
	if (data->len_map <= 0)
		return (ft_printf("%sMap too small.\n", error), 0);
	data->map = malloc((data->len_map + 1) * sizeof(char *));
	data->map_cpy = malloc((data->len_map + 1) * sizeof(char *));
	if (!data->map || !data->map)
		return (ft_printf("%sError Malloc.\n"), 0);
	if (ft_fill_map(pathname, data) == 0)
		return (ft_printf("%sMap Not filled.\n", error), 0);
	if (ft_is_rectangle_map(data) == 0)
		return (ft_printf("%sMap is'nt a Rectangle.\n", error), 0);
	if (ft_map_has_all_needed(data) == 0)
		return (ft_printf("%sElement(s) on the Map not valid.\n", error), 0);
	if (ft_is_border_map_ok(data) == 0)
		return (ft_printf("%sThe Map is not surrounded by walls.\n", error), 0);
	if (is_path_valid(data) == 0)
		return (ft_printf("%sPath Not Found.\n", error), 0);
	return (1);
}
