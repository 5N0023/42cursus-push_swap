/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:44:23 by mlektaib          #+#    #+#             */
/*   Updated: 2022/10/17 20:00:50 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*tmp;

	tmp = NULL;
	while (*str)
	{
		if (*(str) == (char)ch)
			tmp = (char *)str;
		str++;
	}
	if (*(str) == (char)ch)
		return ((char *)str);
	return (tmp);
}
