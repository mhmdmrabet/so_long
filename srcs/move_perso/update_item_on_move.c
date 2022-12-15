/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_item_on_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:52:50 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/15 11:50:46 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	update_item_on_map_top(int y, int x, t_map_info *map)
{
	if (map->on_exit)
	{
		map->map_cpy[y - 1][x] = 'P';
		map->map_cpy[y][x] = 'E';
		map->on_exit = 0;
	}
	else if (map->map_cpy[y - 1][x] == 'E')
	{
		map->map_cpy[y - 1][x] = 'P';
		map->map_cpy[y][x] = '0';
		map->on_exit = 1;
	}
	else if (map->on_exit == 0)
	{
		map->map_cpy[y][x] = '0';
		map->map_cpy[y - 1][x] = 'P';
	}
}

void	update_item_on_map_bottom(int y, int x, t_map_info *map)
{
	if (map->on_exit)
	{
		map->map_cpy[y + 1][x] = 'P';
		map->map_cpy[y][x] = 'E';
		map->on_exit = 0;
	}
	else if (map->map_cpy[y + 1][x] == 'E')
	{
		map->map_cpy[y + 1][x] = 'P';
		map->map_cpy[y][x] = '0';
		map->on_exit = 1;
	}
	else if (map->on_exit == 0)
	{
		map->map_cpy[y][x] = '0';
		map->map_cpy[y + 1][x] = 'P';
	}
}

void	update_item_on_map_rigth(int y, int x, t_map_info *map)
{
	if (map->on_exit)
	{
		map->map_cpy[y][x + 1] = 'P';
		map->map_cpy[y][x] = 'E';
		map->on_exit = 0;
	}
	else if (map->map_cpy[y][x + 1] == 'E')
	{
		map->map_cpy[y][x + 1] = 'P';
		map->map_cpy[y][x] = '0';
		map->on_exit = 1;
	}
	else if (map->on_exit == 0)
	{
		map->map_cpy[y][x] = '0';
		map->map_cpy[y][x + 1] = 'P';
	}
}

void	update_item_on_map_left(int y, int x, t_map_info *map)
{
	if (map->on_exit)
	{
		map->map_cpy[y][x - 1] = 'P';
		map->map_cpy[y][x] = 'E';
		map->on_exit = 0;
	}
	else if (map->map_cpy[y][x - 1] == 'E')
	{
		map->map_cpy[y][x - 1] = 'P';
		map->map_cpy[y][x] = '0';
		map->on_exit = 1;
	}
	else if ((map->map_cpy[y][x - 1] != '1'))
	{
		map->map_cpy[y][x] = '0';
		map->map_cpy[y][x - 1] = 'P';
	}
}
