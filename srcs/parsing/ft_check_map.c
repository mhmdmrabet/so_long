/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:28:54 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/30 15:28:54 by mmrabet          ###   ########.fr       */
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

int	ft_check_line(char *line, int *exit, int *item, int *position_depart)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_is_characters(line[i]) == 1)
		{
			if (line[i] == 'E')
				*exit = *exit + 1;
			else if (line[i] == 'C')
				*item = *item + 1;
			else if (line[i] == 'P')
				*position_depart = *position_depart + 1;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_map(t_map_info *data)
{
	int	exit;
	int	item;
	int	position_depart;
	int	i;

	i = 0;
	exit = 0;
	position_depart = 0;
	item = 0;
	while (data->map[i])
	{
		if (ft_check_line(data->map[i], &exit, &item, &position_depart) == 0)
			return (0);
		i++;
	}
	if (exit != 1 || position_depart != 1 || item < 1)
		return (0);
	return (1);
}
