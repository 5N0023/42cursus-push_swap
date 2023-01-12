/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:12:51 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/12 18:58:34 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_doubleop(t_list **stack, t_list **b, int k)
{
	if (k == 1)
	{
		rotate(stack);
		rotate(b);
	}
	if (k == 2)
	{
		rrotate(stack);
		rrotate(b);
	}
	if (k == 3)
	{
		swap(stack);
		swap(b);
	}
}

int	ft_appop(t_list **stack, t_list **b, char *tab, int i)
{
	if (!ft_strncmp(tab, "rrr", i) && i == 3)
		ft_doubleop(stack, b, 2);
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
	else if (!ft_strncmp(tab, "ss", i) && i == 2)
		ft_doubleop(stack, b, 3);
	else if (!ft_strncmp(tab, "ra", i) && i == 2)
		rotate(stack);
	else if (!ft_strncmp(tab, "rb", i) && i == 2)
		rotate(b);
	else if (!ft_strncmp(tab, "rr", i) && i == 2)
		ft_doubleop(stack, b, 1);
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
		if (k == 0)
			return (0);
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
	if (!tmp)
		return (0);
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
