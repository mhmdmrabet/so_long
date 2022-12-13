/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:44:42 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:44:45 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	handle_keypress(int keysym, t_all_data *all_data)
{
	if (keysym == XK_Escape)
		destroy_free_win(all_data);
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
