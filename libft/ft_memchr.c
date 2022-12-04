/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:51:09 by mlektaib          #+#    #+#             */
/*   Updated: 2022/10/17 19:59:28 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)tmp[i] == (unsigned char)value)
			return ((void *)tmp + i);
		i++;
	}
	return (NULL);
}
