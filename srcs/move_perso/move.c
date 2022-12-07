/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 08:28:31 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/07 10:33:46 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	move_top(t_all_data *all_data)
{
	int	x;
	int	y;

	y = all_data->map->current_position_vertical;
	x = all_data->map->current_position_horizontal;
	if (all_data->map->nb_items == all_data->map->nb_items_collected)
		if (all_data->map->map_cpy[y - 1][x] == 'E')
			exit(EXIT_SUCCESS);
	if (all_data->map->map_cpy[y - 1][x] != '1'
		&& all_data->map->map_cpy[y - 1][x] != 'E')
	{
		if (all_data->map->map_cpy[y - 1][x] == 'C')
			all_data->map->nb_items_collected++;
		all_data->map->map_cpy[y][x] = '0';
		all_data->map->map_cpy[y - 1][x] = 'P';
		all_data->map->current_position_vertical = y - 1;
		display_sprites(all_data);
		ft_printf("%d\n", all_data->data->nb_movement++);
	}
}

void	move_bottom(t_all_data *all_data)
{
	int	x;
	int	y;

	y = all_data->map->current_position_vertical;
	x = all_data->map->current_position_horizontal;
	if (all_data->map->nb_items == all_data->map->nb_items_collected)
		if (all_data->map->map_cpy[y + 1][x] == 'E')
			exit(EXIT_SUCCESS);
	if (all_data->map->map_cpy[y + 1][x] != '1'
		&& all_data->map->map_cpy[y + 1][x] != 'E')
	{
		if (all_data->map->map_cpy[y + 1][x] == 'C')
				all_data->map->nb_items_collected++;
		all_data->map->map_cpy[y][x] = '0';
		all_data->map->map_cpy[y + 1][x] = 'P';
		all_data->map->current_position_vertical = y + 1;
		display_sprites(all_data);
		ft_printf("%d\n", all_data->data->nb_movement++);
	}
}

void	move_right(t_all_data *all_data)
{
	int	x;
	int	y;

	y = all_data->map->current_position_vertical;
	x = all_data->map->current_position_horizontal;
	if (all_data->map->nb_items == all_data->map->nb_items_collected)
		if (all_data->map->map_cpy[y][x + 1] == 'E')
			exit(EXIT_SUCCESS);
	if (all_data->map->map_cpy[y][x + 1] != '1'
		&& all_data->map->map_cpy[y][x + 1] != 'E')
	{
		if (all_data->map->map_cpy[y][x + 1] == 'C')
				all_data->map->nb_items_collected++;
		all_data->map->map_cpy[y][x] = '0';
		all_data->map->map_cpy[y][x + 1] = 'P';
		all_data->map->current_position_horizontal = x + 1;
		display_sprites(all_data);
		ft_printf("%d\n", all_data->data->nb_movement++);
	}
}

void	move_left(t_all_data *all_data)
{
	int	x;
	int	y;

	y = all_data->map->current_position_vertical;
	x = all_data->map->current_position_horizontal;
	if (all_data->map->nb_items == all_data->map->nb_items_collected)
		if (all_data->map->map_cpy[y][x - 1] == 'E')
			exit(EXIT_SUCCESS);
	if (all_data->map->map_cpy[y][x - 1] != '1'
		&& all_data->map->map_cpy[y][x - 1] != 'E')
	{
		if (all_data->map->map_cpy[y][x - 1] == 'C')
			all_data->map->nb_items_collected++;
		all_data->map->map_cpy[y][x] = '0';
		all_data->map->map_cpy[y][x - 1] = 'P';
		all_data->map->current_position_horizontal = x - 1;
		display_sprites(all_data);
		ft_printf("%d\n", all_data->data->nb_movement++);
	}
}

void	move_to(char direction, t_all_data *data)
{
	if (direction == 't')
		move_top(data);
	else if (direction == 'b')
		move_bottom(data);
	else if (direction == 'r')
		move_right(data);
	else if (direction == 'l')
		move_left(data);
}
