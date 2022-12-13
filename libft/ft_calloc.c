/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:49:19 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:49:19 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	result;
	void	*ptr;

	if (nmemb && size && (nmemb * size / size != nmemb))
		return (NULL);
	result = (nmemb * size);
	ptr = (void *)malloc(result);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, result);
	return (ptr);
}
