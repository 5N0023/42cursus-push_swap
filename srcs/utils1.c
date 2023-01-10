/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:18:57 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/10 20:17:04 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fakeswap(t_list **stack, int size)
{
	int	min;

	min = (*stack)->lis;
	swap(stack);
	ft_makezeros(stack);
	findlis(stack, size);
	if ((*stack)->lis > min)
		ft_putendl_fd("sa", 1);
	else
	{
		swap(stack);
		ft_makezeros(stack);
		findlis(stack, size);
	}
}

void	ft_push0marktob(t_list **stack, t_list **b, int size)
{
	t_list	*tmp;
	int		count;
	t_list	*tmp2;
	int		min;

	min = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (tmp->mark == 0)
		{
			size = ft_lstsize(*stack);
			count = ft_counter(stack, tmp);
			ft_pushtob(stack, b, size, count);
			findlis(stack, size);
			ft_fakeswap(stack, size);
		}
		tmp = tmp2;
	}
}

void	ft_mintomoon(t_list **stack, int count, int size)
{
	t_list	*tmp;

	tmp = *stack;
	if (count > size / 2)
	{
		while (size - count > 0)
		{
			rrotate(stack);
			ft_putendl_fd("rra", 1);
			count++;
		}
	}
	else
	{
		while (count-- > 0)
		{
			rotate(stack);
			ft_putendl_fd("ra", 1);
		}
	}
}

void	ft_mintotop(t_list **stack, int size)
{
	t_list	*tmp;
	int		min;
	int		count ;
	int		tmpcount;

	count = 0;
	tmp = *stack;
	min = tmp->num;
	while (tmp)
	{
		if (tmp->num <= min)
		{
			min = tmp->num;
			tmpcount = count;
		}
		count++;
		tmp = tmp->next;
	}
	ft_mintomoon(stack, tmpcount, size);
}

void	ft_pushtob(t_list **stack, t_list **b, int size, int count)
{	
	if (count <= size / 2)
	{
		while (count-- > 1)
		{
			rotate(stack);
			ft_putendl_fd("ra", 1);
		}
		push(b, stack);
		ft_putendl_fd("pb", 1);
	}
	else
	{
		while (count++ <= size)
		{
			rrotate(stack);
			ft_putendl_fd("rra", 1);
		}
		push(b, stack);
		ft_putendl_fd("pb", 1);
	}
}
