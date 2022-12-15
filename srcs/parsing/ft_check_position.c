/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:45:53 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:45:53 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	insert_around_depart(t_map_info *data, int replacement)
{
	int	i;
	int	j;

	i = data->map_p_index;
	j = data->line_p_index;
	if (data->map[i + 1][j] != '1' && data->map[i + 1][j] != 'E')
		data->map[i + 1][j] = replacement;
	if (data->map[i - 1][j] != '1' && data->map[i - 1][j] != 'E')
		data->map[i - 1][j] = replacement;
	if (data->map[i][j + 1] != '1' && data->map[i][j + 1] != 'E')
		data->map[i][j + 1] = replacement;
	if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != 'E')
		data->map[i][j - 1] = replacement;
	return ;
}

int	insert_in_line(t_map_info *data, int i, int j, int *add_x)
{
	while (j < data->len_line)
	{
		if (data->map[i][j] == '*')
		{
			check_and_replace(data, i, j - 1, add_x);
			check_and_replace(data, i, j + 1, add_x);
			check_and_replace(data, i + 1, j, add_x);
			check_and_replace(data, i - 1, j, add_x);
		}
		j++;
	}
	return (0);
}

int	insert_around_x(t_map_info *data, int *add_x)
{
	int	result;
	int	i;
	int	j;

	result = 0;
	i = 0;
	*add_x = 0;
	while (i < data->len_map)
	{
		j = 0;
		result = insert_in_line(data, i, j, add_x);
		if (result == 1)
			break ;
		i++;
	}
	return (result);
}

int	fill_around_depart(t_map_info *data)
{
	int		i;
	int		j;
	int		add_x;
	char	replacement;

	replacement = '*';
	add_x = 1;
	ft_find_depart_horizontal_position(data);
	i = data->map_p_index;
	j = data->line_p_index;
	if (data->map[i + 1][j] == 'C' || data->map[i - 1][j] == 'C'
		|| data->map[i][j + 1] == 'C' || data->map[i][j - 1] == 'C')
		data->nb_accesible_collectible = data->nb_accesible_collectible + 1;
	if (data->map[i + 1][j] != '1' && data->map[i + 1][j] != 'E')
		data->map[i + 1][j] = replacement;
	if (data->map[i - 1][j] != '1' && data->map[i - 1][j] != 'E')
		data->map[i - 1][j] = replacement;
	if (data->map[i][j + 1] != '1' && data->map[i][j + 1] != 'E')
		data->map[i][j + 1] = replacement;
	if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != 'E')
		data->map[i][j - 1] = replacement;
	return (1);
}

int	is_path_valid(t_map_info *data)
{
	int		add_x;
	int		i;
	int		x;
	int		j;

	i = 0;
	add_x = 1;
	fill_around_depart(data);
	x = data->current_position_horizontal;
	j = data->current_position_vertical;
	while (insert_around_x(data, &add_x) == 0 && add_x == 1)
		i++;
	if (data->nb_accesible_collectible == data->nb_items)
	{
		if ((data->map[j + 1][x] == 'E' || data->map[j - 1][x] == 'E'
			|| data->map[j][x + 1] == 'E' || data->map[j][x - 1] == 'E'))
			return (1);
		if (check_if_find_e(data))
			return (1);
	}
	return (add_x);
}
