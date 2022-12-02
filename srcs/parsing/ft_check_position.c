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

int	ft_find_path(t_map_info *data)
{
	if (move_down(data) == 1)
		ft_find_path(data);
	else if (move_up(data) == 1)
		ft_find_path(data);
	else if (move_right(data) == 1)
		ft_find_path(data);
	else if (move_left(data) == 1)
		ft_find_path(data);
	else if (data->current_position_horizontal == data->exit_position_horizontal && data->current_position_vertical == data->exit_position_vertical)
		return (1);
}
