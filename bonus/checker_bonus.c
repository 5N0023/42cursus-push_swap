/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:22:13 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/12 16:06:53 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int a, char **arg)
{
	t_list	*stack;
	int		size;
	t_list	*b;

	size = 0;
	b = NULL;
	if (a == 1)
		return (0);
	if (!ft_createstack(arg, &stack) || ft_useoper(&stack, &b) == -1)
	{
		ft_putendl_fd("Error", 2);
		ft_lstclear(&stack, free);
		exit (1);
	}
	if (ft_checkifsorted(&stack))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear(&stack, free);
	return (0);
}	
