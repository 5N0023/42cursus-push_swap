/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:56:47 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/10 20:35:25 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*tmpnxt;

	head = *stack;
	if (!head)
		return ;
	tmp = head->next;
	if (!tmp)
		return ;
	tmpnxt = tmp->next;
	*stack = tmp;
	tmp->next = head;
	head->next = tmpnxt;
}

void	push(t_list **a, t_list **b)
{
	t_list	*tmpb;
	t_list	*tmp;
	size_t	size;

	size = ft_lstsize(*b);
	tmpb = *b;
	if (size == 0)
		return ;
	if (size == 1)
	{
		ft_lstadd_front(a, tmpb);
		*b = NULL;
		return ;
	}
	*b = tmpb->next;
	ft_lstadd_front(a, tmpb);
}

void	rrotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;
	t_list	*tmp;
	int		size;

	if (stack)
		size = ft_lstsize(*stack);
	if (size == 0)
		return ;
	if (size == 2)
	{
		swap(stack);
		return ;
	}
	if (size > 2)
	{
		tmp = *stack;
		head = *stack;
		last = ft_lstlast(*stack);
		while (tmp->next != last)
			tmp = tmp->next;
		last->next = head;
		tmp->next = NULL;
		*stack = last;
	}
}

void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	size_t	size;

	size = 0;
	if (stack)
		size = ft_lstsize(*stack);
	if (size == 0)
		return ;
	if (size == 2)
	{
		swap(stack);
		return ;
	}
	else if (size == 1)
		return ;
	tail = ft_lstlast(*stack);
	head = *stack;
	*stack = head->next;
	tail->next = head;
	head->next = NULL;
}
