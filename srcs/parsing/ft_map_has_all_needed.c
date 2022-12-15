/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_has_all_needed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:46:43 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:46:43 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	ft_is_characters(char c)
{
	const char		*characters = "01CEP";
	int				i;

	i = 0;
	while (characters[i])
	{
		if (characters[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_line(int i, int *exit, int *position_depart, t_map_info *data)
{
	int	j;

	j = 0;
	while (data->map[i][j])
	{
		if (ft_is_characters(data->map[i][j]) == 1)
		{
			if (data->map[i][j] == 'E')
			{
				*exit = *exit + 1;
				data->exit_position_horizontal = j;
				data->exit_position_vertical = i;
			}
			else if (data->map[i][j] == 'C')
				data->nb_items = data->nb_items + 1;
			else if (data->map[i][j] == 'P')
				*position_depart = *position_depart + 1;
		}
		else
			return (0);
		j++;
	}
	return (1);
}

int	ft_map_has_all_needed(t_map_info *data)
{
	int	exit;
	int	item;
	int	position_depart;
	int	i;

	i = 0;
	exit = 0;
	position_depart = 0;
	item = 0;
	data->nb_items = 0;
	while (data->map[i])
	{
		if (ft_check_line(i, &exit, &position_depart, data) == 0)
			return (0);
		i++;
	}
	if (exit != 1 || position_depart != 1 || data->nb_items < 1)
		return (0);
	return (1);
}
