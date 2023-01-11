/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:56:47 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/11 20:31:29 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*beforelast(t_list *tmp, t_list *last)
{
	while (tmp->next != last)
			tmp = tmp->next;
	return (tmp);
}

void	rrotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;
	t_list	*tmp;
	int		size;

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
	if (size > 2)
	{
		tmp = *stack;
		head = *stack;
		last = ft_lstlast(*stack);
		tmp = beforelast(tmp, last);
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
