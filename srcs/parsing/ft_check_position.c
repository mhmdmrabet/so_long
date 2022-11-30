/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:08:36 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/30 17:08:36 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	ft_find_position(char *line, t_map_info *data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
		{
			data->line_p_index = i;
			return (1);
		}
		i++;
	}
	return (0);
}

// int	ft_check_around_position(char **map, t_map_info *data)
// {
// 	if (map[data->map_p_index - 1][data->line_p_index] != '1')
// 	return (1);
// }

int	ft_is_position_ok(t_map_info *data)
{
	data->line_p_index = 0;
	data->map_p_index = 0;
	while (data->map[data->map_p_index])
	{
		if (ft_find_position(data->map[data->map_p_index], data) == 1)
			break ;
		data->map_p_index++;
	}
	printf("MAP[%d] | LINE[%d]\n", data->map_p_index, data->line_p_index);
	return (1);
}
