/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:54:22 by mlektaib          #+#    #+#             */
/*   Updated: 2022/10/17 19:59:33 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	k;

	if (!dest && !src)
		return (0);
	k = 0;
	while (k < n)
	{
		((unsigned char *)dest)[k] = ((unsigned char *)src)[k];
		k++;
	}
	return (dest);
}
