/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@studentX42Xfr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:08:36 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/30 17:08:36 by mmrabet          ###   ########Xfr       */
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
			if (check_e_around_elmnt(data, i, j))
			{
				*add_x = 1;
				return (1);
			}
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
	if (data->map[i + 1][j] != '1' && data->map[i + 1][j] != 'E' )
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

	add_x = 1;
	fill_around_depart(data);
	while (insert_around_x(data, &add_x) == 0 && add_x == 1)
		printf("");
	return (add_x);
}
