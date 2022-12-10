/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:24:48 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 16:24:48 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, t_printf *data)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, data);
		ft_putnbr(n % 10, data);
	}
	else
		ft_putchar_len(n + 48, data);
}
