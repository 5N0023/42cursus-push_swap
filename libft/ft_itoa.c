/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:02:41 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/12 20:51:26 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigit(int n)
{
	int	count;
	int	num;

	count = 0;
	if (n == 0)
		n = 1;
	num = n;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

static char	*ft_itoahelper(int count, char *tab, int i, long num)
{
	tab[count] = '\0';
	count--;
	while (count >= i)
	{
		tab[count] = (num % 10) + '0';
		num = num / 10;
		count--;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*tab;
	int		i;
	long	num;

	i = 0;
	num = n;
	count = ft_countdigit(n);
	if (n < 0)
		count++;
	tab = (char *)malloc(sizeof(char) * count + 1);
	if (!tab)
		return (0);
	if (n < 0)
	{
		tab[i] = '-';
		i++;
		num = -num;
	}
	return (ft_itoahelper(count, tab, i, num));
}
