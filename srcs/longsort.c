/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:19:51 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/10 19:36:01 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dorotate(int count, t_list **stack, t_list **b)
{
	if (stack && b)
	{
		while (count-- > 0)
		{
			ft_putendl_fd("rr", 1);
			rotate(stack);
			rotate(b);
		}
	}
	else if (stack && !b)
	{
		while (count-- > 0)
		{
			rotate(stack);
			ft_putendl_fd("ra", 1);
		}
	}
	else if (!stack && b)
	{
		while (count-- > 0)
		{
			rotate(b);
			ft_putendl_fd("rb", 1);
		}
	}
}

void	ft_dorrotate(int count, t_list **stack, t_list **b)
{
	if (stack && b)
	{
		while (count-- > 0)
		{
			ft_putendl_fd("rrr", 1);
			rrotate(stack);
			rrotate(b);
		}
	}
	else if (stack && !b)
	{
		while (count-- > 0)
		{
			rrotate(stack);
			ft_putendl_fd("rra", 1);
		}
	}
	else if (!stack && b)
	{
		while (count-- > 0)
		{
			rrotate(b);
			ft_putendl_fd("rrb", 1);
		}
	}
}

void	findshortway(t_list **stack, t_list **b, t_vars3 *sizes)
{
	t_list	*tmp;
	t_vars1	vars;

	tmp = *b;
	vars.count = 0;
	vars.minmoves = 2147483647;
	while (tmp)
	{
		vars.posa = ft_findposinstacka(stack, tmp->num);
		vars.moves = ft_longbtwn(vars.count, vars.posa,
				sizes->sizea, sizes->sizeb);
		if (vars.minmoves == 2147483647)
		{
			vars.num = tmp->num;
			vars.minmoves = vars.moves;
		}
		if (vars.moves < vars.minmoves)
		{
			vars.minmoves = vars.moves;
			vars.num = tmp->num;
		}
		vars.count++;
		tmp = tmp->next;
	}
	ft_movenumtoa(vars.num, stack, b, sizes);
}

void	ft_push0marktoa(t_list **stack, t_list **b)
{
	t_vars3	vars;

	vars.sizea = ft_lstsize(*stack);
	vars.sizeb = ft_lstsize(*b);
	while (vars.sizeb)
	{
		findshortway(stack, b, &vars);
		vars.sizeb = ft_lstsize(*b);
		vars.sizea = ft_lstsize(*stack);
	}
}

void	ft_longsort(t_list **stack, t_list **b, int size)
{
	t_list	*tmp;
	int		min;

	tmp = *stack;
	findlis(stack, size);
	ft_fakeswap(stack, size);
	ft_push0marktob(stack, b, ft_lstsize(*stack));
	ft_push0marktoa(stack, b);
	ft_mintotop(stack, size);
}
