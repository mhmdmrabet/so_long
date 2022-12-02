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

int	ft_check_around_position(t_map_info *data)
{
	const int	m_index = data->map_p_index;
	const int	l_index = data->line_p_index;
	int			number_wall;

	number_wall = 0;
	if (data->map[m_index][l_index + 1] == '1')
		number_wall++;
	if (data->map[m_index][l_index - 1] == '1')
		number_wall++;
	if (data->map[m_index + 1][l_index] == '1')
		number_wall++;
	if (data->map[m_index - 1][l_index] == '1')
		number_wall++;
	printf("NUMBER WALL : %d\n", number_wall);
	if (number_wall >= 4)
		return (0);
	return (1);
}

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
	ft_check_around_position(data);
	return (1);
}
