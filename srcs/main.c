/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:22:13 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/11 21:16:03 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int a, char **arg)
{
	t_list	*stack;
	t_list	*b;
	int		size;

	b = NULL;
	if (a == 1)
		return (0);
	if (!ft_createstack(arg, &stack))
	{
		ft_putendl_fd("Error", 2);
		ft_lstclear(&stack, free);
		return (1);
	}
	if (ft_checkifsorted(&stack))
		return (0);
	size = ft_lstsize(stack);
	if (size > 10)
		ft_longsort(&stack, &b, size);
	else
		ft_shortsort(&stack, &b, size);
	ft_lstclear(&stack, free);
	return (0);
}	
