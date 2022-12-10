/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:46:04 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:46:04 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

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

int	ft_is_border_map_ok(t_map_info *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (i == 0 || (i + 1 == data->len_map))
		{
			if (ft_is_wall_top_bottom(data->map[i]) == 0)
				return (0);
		}
		else
			if (ft_is_border_wall(data->map[i]) == 0)
				return (0);
		i++;
	}
	return (1);
}

int	ft_is_rectangle_map(t_map_info *data)
{
	int	tmp;
	int	i;

	i = 1;
	data->len_line = (int)ft_strlen(data->map[0]);
	if (data->len_line == data->len_map)
		return (0);
	while (data->map[i])
	{
		tmp = data->len_line;
		data->len_line = (int)ft_strlen(data->map[i]);
		if (tmp != data->len_line)
			return (0);
		i++;
	}
	return (1);
}
