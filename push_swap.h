/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:53:23 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/09 14:17:46 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_vars
{
	int	sizea;
	int	sizeb;
	int	index;
	int	count;
	int	posa;
}	t_vars;
typedef struct s_vars1
{
	int		num;
	int		count;
	int		moves;
	int		minmoves;
	int		posa;
}	t_vars1;
void	rotate(t_list **stack);
void	swap(t_list **stack);
void	rrotate(t_list **stack);
void	push(t_list **a, t_list **b);

#endif
