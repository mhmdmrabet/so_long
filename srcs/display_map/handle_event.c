/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:03:05 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/06 16:03:28 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	handle_keypress(int keysym, t_data_mlx *data)
{
	if (keysym == XK_Escape)
		destroy_free_win(data);
	return (0);
}
