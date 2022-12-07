/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:03:05 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 10:59:12 by mmrabet          ###   ########.fr       */
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
