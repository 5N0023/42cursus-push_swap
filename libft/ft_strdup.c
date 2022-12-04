/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:39:16 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/12 21:21:11 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	srclen;
	char	*dst;

	srclen = ft_strlen(src);
	i = 0;
	dst = malloc(sizeof(char) * srclen + 1);
	if (!dst)
	{
		errno = ENOMEM;
		return (0);
	}
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
