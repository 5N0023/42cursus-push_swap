/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:28:16 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/09 13:53:44 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == '\n');
}

long	ft_atoi(const char *str)
{
	size_t	res;
	int		sign;
	size_t	prev;

	sign = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		prev = res;
		res = (*str - 48) + (res * 10);
		if (res / 10 != prev && sign == 1)
			return (-1);
		if (res / 10 != prev && sign == -1)
			return (0);
			str++;
	}
	return ((long)res * sign);
}
