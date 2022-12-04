/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:24:11 by mlektaib          #+#    #+#             */
/*   Updated: 2022/10/21 09:53:39 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	bytes;

	bytes = count * size;
	if (count == 0 || size == 0)
		bytes = 1;
	else if (count != 0 && bytes / count != size)
		return (0);
	p = malloc(bytes);
	if (!p)
	{
		errno = ENOMEM;
		return (0);
	}
	ft_bzero(p, bytes);
	return (p);
}
