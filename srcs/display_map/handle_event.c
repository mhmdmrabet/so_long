/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:03:05 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/06 18:31:57 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void 	move_top(t_all_data *all_data)
{
	int x;
	int y;

	y = all_data->map->current_position_vertical;
	x = all_data->map->current_position_horizontal;
	if (all_data->map->map_cpy[y - 1][x] != '1' && all_data->map->map_cpy[y - 1][x] != 'E')
	{
		all_data->map->map_cpy[y][x] = '0';
		all_data->map->map_cpy[y - 1][x] = 'P';
		all_data->map->current_position_vertical = y - 1;
	}
	display_sprites(all_data);
}

void 	move_bottom(t_all_data *all_data)
{
	int x;
	int y;

	y = all_data->map->current_position_vertical;
	x = all_data->map->current_position_horizontal;
	if (all_data->map->map_cpy[y + 1][x] != '1' && all_data->map->map_cpy[y + 1][x] != 'E')
	{
		all_data->map->map_cpy[y][x] = '0';
		all_data->map->map_cpy[y + 1][x] = 'P';
		all_data->map->current_position_vertical = y + 1;
	}
	display_sprites(all_data);
}

void 	move_right(t_all_data *all_data)
{
	int x;
	int y;

	y = all_data->map->current_position_vertical;
	x = all_data->map->current_position_horizontal;
	if (all_data->map->map_cpy[y][x + 1] != '1' && all_data->map->map_cpy[y][x + 1] != 'E')
	{
		all_data->map->map_cpy[y][x] = '0';
		all_data->map->map_cpy[y][x + 1] = 'P';
		all_data->map->current_position_horizontal = x + 1;
	}
	display_sprites(all_data);
}

void 	move_left(t_all_data *all_data)
{
	int x;
	int y;

	y = all_data->map->current_position_vertical;
	x = all_data->map->current_position_horizontal;
	if (all_data->map->map_cpy[y][x - 1] != '1' && all_data->map->map_cpy[y][x - 1] != 'E'
		&& all_data->map->map_cpy[y][x - 1] != 'E')
	{
		all_data->map->map_cpy[y][x] = '0';
		all_data->map->map_cpy[y][x - 1] = 'P';
		all_data->map->current_position_horizontal = x - 1;
	}
	display_sprites(all_data);
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
	ft_printf("%d", data->data->nb_movement++);
}

int	handle_keypress(int keysym, t_all_data *all_data)
{
	if (keysym == XK_Escape)
	{
		destroy_free_win(all_data);
		exit(EXIT_SUCCESS);
	}
	// printf("%d\n", keysym);
	if (keysym == 119)
		move_to('t', all_data);
	if (keysym == 97)
		move_to('l', all_data);
	if (keysym == 115)
		move_to('b', all_data);
	if (keysym == 100)
		move_to('r', all_data);
	return (0);
}
