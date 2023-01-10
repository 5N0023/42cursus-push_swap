/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:53:13 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/10 19:53:32 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_counter(t_list **stack, t_list *tofind)
{
	t_list	*tmp;
	int		count;

	tmp = *stack;
	count = 1;
	while (tmp)
	{
		if (tmp == tofind)
			return (count);
		count++;
		tmp = tmp->next;
	}
	return (0);
}

int	ft_findposinstackamax(t_list **stack, int num)
{
	t_list	*tmp;
	int		count;
	int		count2;
	int		max;

	tmp = *stack;
	count = 0;
	count2 = 0;
	max = -2147483648;
	while (tmp)
	{
		if (tmp->num < num && tmp->num > max)
		{
			max = tmp->num;
			count2 = count;
		}
		count++;
		tmp = tmp->next;
	}
	return (count2 + 1);
}

int	ft_findposinstacka(t_list **stack, int num)
{
	t_list	*tmp;
	int		count;
	int		count2;
	int		min;
	int		k;

	count = 0;
	count2 = 0;
	k = 0;
	min = 2147483647;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->num > num && tmp->num < min)
		{
			min = tmp->num;
			count2 = count;
			k = 1;
		}
		count++;
		tmp = tmp->next;
	}
	if (k == 0)
		return (ft_findposinstackamax(stack, num));
	return (count2);
}

int	ft_findmoves(t_vars *vars)
{
	if (vars->count < vars->sizeb / 2 && vars->posa < vars->sizea / 2)
		return (2);
	else if (vars->count >= vars->sizeb / 2 && vars->posa >= vars->sizea / 2)
		return (1);
	else if (vars->count <= vars->sizeb / 2 && vars->posa >= vars->sizea / 2)
		return (3);
	else if (vars->count >= vars->sizeb / 2 && vars->posa <= vars->sizea / 2)
		return (4);
	return (0);
}

int	ft_longbtwn(int count, int posa, int sizea, int sizeb)
{
	if (count < sizeb / 2 && posa < sizea / 2 && count >= posa)
		return (count);
	else if (count < sizeb / 2 && posa < sizea / 2 && count <= posa)
		return (posa);
	else if (count >= sizeb / 2 && posa >= sizea / 2
		&& sizeb - count <= sizea - posa)
		return (sizea - posa);
	else if (count > sizeb / 2 && posa > sizea / 2
		&& sizeb - count >= sizea - posa)
		return (sizeb - count);
	else if (count <= sizeb / 2 && posa >= sizea / 2)
		return (count + (sizea - posa));
	else if (count >= sizeb / 2 && posa <= sizea / 2)
		return (posa + (sizeb - count));
	return (0);
}
