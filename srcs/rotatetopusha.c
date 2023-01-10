/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatetopusha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:19:08 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/10 19:52:15 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotateandpushtoa2(t_list **stack, t_list **b,
	int index, t_vars *vars)
{
	if (index == 2)
	{
		if (vars->posa >= vars->count)
		{
			ft_dorotate(vars->count, stack, b);
			ft_dorotate(vars->posa - vars->count, stack, NULL);
		}
		else
		{
			ft_dorotate(vars->posa, stack, b);
			ft_dorotate(vars->count - vars->posa, NULL, b);
		}
	}
	else if (index == 3)
	{
		ft_dorotate(vars->count, NULL, b);
		ft_dorrotate(vars->sizea - vars->posa, stack, NULL);
	}
	else if (index == 4)
	{
		ft_dorotate(vars->posa, stack, NULL);
		ft_dorrotate(vars->sizeb - vars->count, NULL, b);
	}
}

void	ft_rotateandpushtoa1(t_list **stack, t_list **b,
	int index, t_vars *vars)
{
	if (index == 1)
	{
		if (vars->sizea - vars->posa <= vars->sizeb - vars->count)
		{
			ft_dorrotate(vars->sizea - vars->posa, stack, b);
			ft_dorrotate((vars->sizeb - vars->count)
				- (vars->sizea - vars->posa), NULL, b);
		}
		else
		{
			ft_dorrotate(vars->sizeb - vars->count, stack, b);
			ft_dorrotate((vars->sizea - vars->posa)
				- (vars->sizeb - vars->count), stack, NULL);
		}
	}
	else if (index >= 2)
		ft_rotateandpushtoa2(stack, b, index, vars);
}

void	ft_rotateandpushtoa(t_list **stack, t_list **b, int index, t_vars *vars)
{
	if (vars->count == 0)
	{
		if (vars->posa > vars->sizea / 2)
			ft_dorrotate(vars->sizea - vars->posa, stack, NULL);
		else
			ft_dorotate(vars->posa, stack, NULL);
	}
	else if (vars->posa == 0)
	{
		if (vars->count > vars->sizeb / 2)
			ft_dorrotate(vars->sizeb - vars->count, NULL, b);
		else
			ft_dorotate(vars->count, NULL, b);
	}
	else if (index >= 1)
		ft_rotateandpushtoa1(stack, b, index, vars);
	push(stack, b);
	ft_putendl_fd("pa", 1);
}

void	ft_movenumtoa(int num, t_list **stack, t_list **b, t_vars3 *sizes)
{
	t_list	*tmp;
	int		count;
	int		posa;
	t_vars	vars;

	count = 0;
	posa = ft_findposinstacka(stack, num);
	tmp = *b;
	while (tmp)
	{
		if (tmp->num == num)
		{
			vars.count = count;
			vars.posa = posa;
			vars.sizea = sizes->sizea;
			vars.sizeb = sizes->sizeb;
			ft_rotateandpushtoa(stack, b, ft_findmoves(&vars), &vars);
			break ;
		}
		count++;
		tmp = tmp->next;
	}
}
