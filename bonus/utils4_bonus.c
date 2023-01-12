/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:12:51 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/12 16:30:13 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_doublerotate(t_list **stack, t_list **b)
{
	rotate(stack);
	rotate(b);
}

void	ft_doublerrotate(t_list **stack, t_list **b)
{
	rrotate(stack);
	rrotate(b);
}

int	ft_appop(t_list **stack, t_list **b, char *tab, int i)
{
	if (!ft_strncmp(tab, "rrr", i) && i == 3)
		ft_doublerrotate(stack, b);
	else if (!ft_strncmp(tab, "rra", i) && i == 3)
		rrotate(stack);
	else if (!ft_strncmp(tab, "pa", i) && i == 2)
		push(stack, b);
	else if (!ft_strncmp(tab, "pb", i) && i == 2)
		push(b, stack);
	else if (!ft_strncmp(tab, "rrb", i) && i == 3)
		rrotate(b);
	else if (!ft_strncmp(tab, "sa", i) && i == 2)
		swap(stack);
	else if (!ft_strncmp(tab, "sb", i) && i == 2)
		swap(b);
	else if (!ft_strncmp(tab, "ra", i) && i == 2)
		rotate(stack);
	else if (!ft_strncmp(tab, "rb", i) && i == 2)
		rotate(b);
	else if (!ft_strncmp(tab, "rr", i))
		ft_doublerotate(stack, b);
	else
		return (0);
	return (1);
}

int	ft_useoper(t_list **stack, t_list **b)
{
	char	tab[4];
	int		k;
	int		i;

	k = 1;
	while (k > 0)
	{
		i = 0;
		k = read(0, &tab[i], 1);
		while (tab[i] && tab[i] != '\n' && k > 0)
		{
			i++;
			k = read(0, &tab[i], 1);
		}
		if (tab[0] == '\n')
			return (-1);
		if (!ft_appop(stack, b, tab, i))
			return (-1);
		i = 0;
	}
	return (k);
}

int	ft_checkifsorted(t_list **stack)
{
	t_list	*tmp;
	int		prev;

	tmp = *stack;
	prev = tmp->num;
	while (tmp)
	{
		if (prev > tmp->num)
			return (0);
		prev = tmp->num;
		tmp = tmp->next;
	}
	return (1);
}
