/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:50:58 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:50:58 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*char_dest;
	char	*char_src;
	int		i;

	char_dest = (char *) dest;
	char_src = (char *) src;
	i = (int)n - 1;
	if (src < dest)
	{
		while (i >= 0)
		{
			char_dest[i] = char_src[i];
			i--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (char_dest);
}
