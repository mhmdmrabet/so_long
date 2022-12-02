/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:13:41 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/02 11:13:41 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"


int	move_down(t_map_info *data)
{
	int	position_h;
	int	position_v;

	position_h = data->current_position_horizontal;
	position_v = data->current_position_vertical;

	if (position_h <= 0 || position_h >= data->len_map)
		return (0);
	if (data->prev_current_position_horizontal == position_h + 1)
		return (0);
	if (data->map[position_h + 1][position_v] != '1')
	{
		data->prev_current_position_vertical = position_v;
		data->prev_current_position_horizontal = position_h;
		data->current_position_horizontal = position_h + 1;
		return (1);
	}
	return (0);
}

int	move_up(t_map_info *data)
{
	int	position_h;
	int	position_v;

	position_h = data->current_position_horizontal;
	position_v = data->current_position_vertical;
	if (position_h <= 0 || position_h >= data->len_map)
		return (0);
	if (data->prev_current_position_horizontal == position_h - 1)
		return (0);
	if (data->map[position_h - 1][position_v] != '1')
	{
		data->prev_current_position_vertical = position_v;
		data->prev_current_position_horizontal = position_h;
		data->current_position_horizontal = position_h - 1;
		return (1);
	}
	return (0);
}

int	move_right(t_map_info *data)
{
	int	position_h;
	int	position_v;

	position_h = data->current_position_horizontal;
	position_v = data->current_position_vertical;
	if (position_h <= 0 || position_h >= data->len_map)
		return (0);
	if (data->prev_current_position_vertical == position_v + 1)
		return (0);
	if (data->map[position_h][position_v + 1] != '1')
	{
		data->prev_current_position_vertical = position_v;
		data->prev_current_position_horizontal = position_h;
		data->current_position_vertical = position_v + 1;
		return (1);
	}
	return (0);
}

int	move_left(t_map_info *data)
{
	int	position_h;
	int	position_v;

	position_h = data->current_position_horizontal;
	position_v = data->current_position_vertical;
	if (position_h <= 0 || position_h >= data->len_map)
		return (0);
	if (data->prev_current_position_vertical == position_v - 1)
		return (0);
	if (data->map[position_h][position_v - 1] != '1')
	{
		data->prev_current_position_vertical = position_v;
		data->prev_current_position_horizontal = position_h;
		data->current_position_vertical = position_v - 1;
		return (1);
	}
	return (0);
}
