/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_around.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:39:59 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/04 11:39:59 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	check_and_replace(t_map_info *data, int i, int j, int *add_x)
{
	if (isnt_obstacle(data, '*', i, j))
	{
		data->map[i][j] = '*';
		*add_x = 1;
	}
}

int	isnt_obstacle(t_map_info *data, char search, int i, int j)
{
	if (data->map[i][j] != '1' && data->map[i][j] != 'P')
	{
		if (data->map[i][j] != 'E' && data->map[i][j] != '*')
			if ((data->map[i][j] == '0' || data->map[i][j] == 'C'))
				return (1);
	}
	return (0);
}

int	check_e_around_elmnt(t_map_info *data, int i, int j)
{
	if (data->map[i][j - 1] == 'E')
		return (1);
	if (data->map[i][j + 1] == 'E')
		return (1);
	if (data->map[i - 1][j] == 'E')
		return (1);
	if (data->map[i + 1][j] == 'E')
		return (1);
	return (0);
}
