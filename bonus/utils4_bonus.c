/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:12:51 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/10 21:17:09 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_isdigit(int n)
{
	return (n >= '0' && n <= '9');
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_appop(t_list **stack, t_list **b, char *tab, int i)
{
	if (ft_strncmp(tab, "sa", i))
		swap(stack);
	else if (ft_strncmp(tab, "sb", i))
		swap(b);
	else if (ft_strncmp(tab, "ra", i))
		rotate(stack);
	else if (ft_strncmp(tab, "rb", i))
		rotate(b);
	else if (ft_strncmp(tab, "rra", i))
		rrotate(stack);
	else if (ft_strncmp(tab, "rrb", i))
		rrotate(b);
	else if (ft_strncmp(tab, "rr", i))
	{
		rotate(stack);
		rotate(b);
	}
	else if (ft_strncmp(tab, "rrr", i))
	{
		rrotate(stack);
		rrotate(b);
	}
}

int	ft_useoper(t_list **stack, t_list **b)
{
	char	tab[4];
	int		k;
	int		i;

	i = 0;
	k = read(0, &tab[i], 1);
	i++;
	while (k > 0)
	{
		while (tab[i - 1] != '\n')
		{
			k = read(0, &tab[i], 1);
			i++;
		}
		ft_appop(stack, b, tab, i);
		i = 0;
		k = read(0, &tab[i], 1);
		i++;
	}
	return (k);
}
