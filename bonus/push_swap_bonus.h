/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:53:23 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/10 21:05:11 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	int				lis;
	int				mark;
	struct s_list	*next;
}	t_list;
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_useoper(t_list **stack, t_list **b);
void	swap(t_list **stack);
void	push(t_list **a, t_list **b);
void	rrotate(t_list **stack);
void	rotate(t_list **stack);
char	**ft_split(char const *s, char c);
#endif
