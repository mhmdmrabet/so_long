/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:31:12 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/28 19:31:12 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>

# include "./../get_next_line/get_next_line.h"
# include "./../ft_printf/ft_printf.h"
# include "./../libft/libft.h"

typedef struct s_map_info
{
	char	**map;
	int		len_map;
	int		map_p_index;
	int		line_p_index;
	int		len_line;
}	t_map_info;

void	ft_parsing(int fd);
int		ft_check_map(t_map_info *data);
int		ft_count_line(const char *pathname);
int		ft_fill_map(const char *pathname, t_map_info *data);
int		ft_is_characters(char c);
int		ft_is_wall_top_bottom(char *line);
int		ft_is_border_wall(char *line);
int		ft_is_border_map_ok(t_map_info *data);
int		ft_is_rectangle_map(t_map_info *data);
int		ft_is_position_ok(t_map_info *data);

#endif