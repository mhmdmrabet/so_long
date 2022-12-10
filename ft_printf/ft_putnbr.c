/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:25:44 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 16:25:44 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, t_printf *data)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", data);
	else if (n < 0)
	{
		ft_putchar_len('-', data);
		n = -n;
		ft_putnbr(n, data);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, data);
		ft_putnbr(n % 10, data);
	}
	else
		ft_putchar_len(n + 48, data);
}
