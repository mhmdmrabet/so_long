/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:07:44 by mmrabet           #+#    #+#             */
/*   Updated: 2022/12/04 11:07:44 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	ft_print_map(t_map_info *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->len_map)
	{
		j = 0;
		while (j < data->len_line)
		{
			printf("%c", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}