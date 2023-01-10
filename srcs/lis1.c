/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:20:31 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/10 19:53:00 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_getnumbers(t_list **stack, int *tab, t_vars2 *tables, int size)
{
	int	k;
	int	i;

	k = ft_max(tables->length, size);
	ft_markintstack(stack, tab[k]);
	i = 0;
	while (k != 0)
	{
		k = tables->sub[k];
		ft_markintstack(stack, tab[k]);
	}
	free(tables->length);
	free(tab);
	free(tables->sub);
}

void	lis(t_list **stack,	int *tab, t_vars2 *tables, int size)
{
	int	k;
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < size)
	{
		while (j != i)
		{
			if (tab[i] < tab[j])
			{
				if (tables->length[i] + 1 >= tables->length[j])
				{
					tables->length[j] = tables->length[i] + 1;
					tables->sub[j] = i;
				}
			}
			i++;
		}
		j++;
		i = 0;
	}
	ft_getnumbers(stack, tab, tables, size);
}

int	*ft_settab(t_list *min, int size)
{
	int		*tab;
	int		i;
	t_list	*tmp;

	tab = malloc(sizeof(int) * size);
	i = 0;
	tmp = min;
	while (i < size)
	{
		tab[i] = tmp->num;
		i++;
		tmp = tmp->next;
	}
	return (tab);
}

t_list	*ft_findmin(t_list *stack)
{
	t_list	*tmp;
	t_list	*ret;
	int		min;

	tmp = stack;
	min = tmp->num;
	while (tmp)
	{
		if (tmp->num <= min)
		{
			ret = tmp;
			min = tmp->num;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	findlis(t_list **stack, int size)
{
	t_list	*min;
	t_list	*tail;
	t_vars2	tables;
	int		i;

	ft_makezeros(stack);
	min = ft_findmin(*stack);
	tail = ft_lstlast(*stack);
	tail->next = *stack;
	tables.length = malloc(sizeof(int) * size);
	tables.sub = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		tables.length[i] = 1;
		i++;
	}
	lis(stack, ft_settab(min, size), &tables, size);
	tail->next = NULL;
}
