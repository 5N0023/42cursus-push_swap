/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:20:00 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/10 19:20:03 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_makezeros(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->lis = 0;
		tmp->mark = 0;
		tmp = tmp->next;
	}
}

int	ft_max(int *tab, int size)
{
	int	max;
	int	i;
	int	count;

	i = 1;
	count = 0;
	max = tab[1];
	while (i < size)
	{
		if (tab[i] > max)
		{
			count = i;
			max = tab[i];
		}
		i++;
	}
	return (count);
}

void	ft_markintstack(t_list **stack, int num)
{
	t_list	*tmp;
	t_list	*head;

	head = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->num == num)
		{
			tmp->mark = 1;
			head->lis += 1;
			return ;
		}
		tmp = tmp->next;
	}
}
