/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:19:03 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/11 17:24:14 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushtoa(t_list **stack, t_list **b)
{
	while (*b)
	{
		push(stack, b);
		ft_putendl_fd("pa", 1);
	}
}

void	ft_sort2number(t_list **stack)
{
	if ((*stack)->num > (*stack)->next->num)
	{
		swap(stack);
		ft_putendl_fd("sa", 1);
	}
}

void	ft_sort3number(t_list **stack, int size)
{
	if (size == 1)
		return ;
	if (size == 2)
		ft_sort2number(stack);
	else
	{
		if ((*stack)->next->num > (*stack)->next->next->num)
		{
			rotate(stack);
			ft_putendl_fd("ra", 1);
		}
		if ((*stack)->num > (*stack)->next->next->num)
		{
			rotate(stack);
			ft_putendl_fd("ra", 1);
		}
		if ((*stack)->num > (*stack)->next->num)
		{
			swap(stack);
			ft_putendl_fd("sa", 1);
		}
	}
}

void	ft_shortsort(t_list **stack, t_list **b, int size)
{
	t_list	*min;
	int		pos;

	while (1)
	{
		size = ft_lstsize(*stack);
		if (size <= 3)
			break ;
		min = ft_findmin(*stack);
		pos = ft_counter(stack, min) - 1;
		if (pos <= size / 2)
			ft_dorotate(pos, stack, NULL);
		else
			ft_dorrotate(size - pos, stack, NULL);
		push(b, stack);
		ft_putendl_fd("pb", 1);
	}
	ft_sort3number(stack, size);
	ft_pushtoa(stack, b);
}
