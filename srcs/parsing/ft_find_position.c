/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:16:13 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/02 11:16:13 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	ft_find_depart_vert_position(char *line, t_map_info *data)
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

int	ft_find_depart_horizontal_position(t_map_info *data)
{
	data->line_p_index = 0;
	data->map_p_index = 0;
	while (data->map[data->map_p_index])
	{
		if (ft_find_depart_vert_position(data->map[data->map_p_index], data))
		{
			data->current_position_horizontal = data->map_p_index;
			data->current_position_vertical = data->line_p_index;
			break ;
		}
		data->map_p_index++;
	}
	return (1);
}
