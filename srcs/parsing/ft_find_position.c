/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:46:25 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:46:25 by abchaban         ###   ########.fr       */
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
			data->current_position_horizontal = data->line_p_index;
			data->current_position_vertical = data->map_p_index;
			break ;
		}
		data->map_p_index++;
	}
	return (1);
}
