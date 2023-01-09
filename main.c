/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:22:13 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/09 21:33:17 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_makezeros(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->lis = 0;
		tmp->mark = 0;
		tmp = tmp->next;
	}
}

int	ft_max(int *tab, int size)
{
	int	max;
	int	i;
	int	count;

	i = 1;
	count = 0;
	max = tab[1];
	while (i < size)
	{
		if (tab[i] >= max)
		{
			count = i;
			max = tab[i];
		}
		i++;
	}
	return (count);
}

void	ft_markintstack(t_list **stack, int num)
{
	t_list	*tmp;
	t_list	*head;

	head = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->num == num)
		{
			tmp->mark = 1;
			head->lis += 1;
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_getnumbers(t_list **stack, int *tab, int *length, int *sub, int size)
{
	int	k;
	int	i;

	k = ft_max(length, size);
	ft_markintstack(stack, tab[k]);
	i = 0;
	while (k != 0)
	{
		k = sub[k];
		ft_markintstack(stack, tab[k]);
	}
	free(length);
	free(tab);
	free(sub);
}

void	lis(t_list **stack, int *tab, int *length, int *sub, int size)
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
				if (length[i] + 1 >= length[j])
				{
					length[j] = length[i] + 1;
					sub[j] = i;
				}
			}
			i++;
		}
		j++;
		i = 0;
	}
	ft_getnumbers(stack, tab, length, sub, size);
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
	int		*length;
	int		*sub;
	int		i;

	min = ft_findmin(*stack);
	tail = ft_lstlast(*stack);
	tail->next = *stack;
	length = malloc(sizeof(int) * size);
	sub = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		length[i] = 1;
		i++;
	}
	lis(stack, ft_settab(min, size), length, sub, size);
	tail->next = NULL;
}

int	ft_checkformat(char *num)
{
	if (*num == '-' || *num == '+')
		num++;
	else if (!ft_isdigit(*num))
		return (0);
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}

void ft_pushtob(t_list **stack, t_list **b, int size, int count)
{	
	if (count <= size / 2)
	{
		while (count-- > 1)
		{
			rotate(stack);
			ft_putstr_fd("ra\n", 1);
		}
		push(b, stack);
		ft_putstr_fd("pb\n", 1);
	}
	else
	{
		while (count++ <= size)
		{
			rrotate(stack);
			ft_putstr_fd("rra\n", 1);
		}
		push(b, stack);
		ft_putstr_fd("pb\n", 1);
	}
}

int ft_counter(t_list **stack,t_list *tofind)
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

int ft_findposinstacka(t_list **stack,int num)
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
	if (vars->count <= vars->sizeb / 2 && vars->posa <= vars->sizea / 2)
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
	if (count <= sizeb / 2 && posa <= sizea / 2 && count >= posa )
		return (count);
	else if (count <= sizeb / 2 && posa <= sizea / 2 && count <= posa)
		return (posa);
	else if (count > sizeb / 2 && posa > sizea / 2 
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

void	ft_rotateandpushtoa2(t_list **stack, t_list **b,int index, t_vars *vars)
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

void	ft_rotateandpushtoa1(t_list **stack, t_list **b,int index, t_vars *vars)
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

void	ft_movenumtoa(int num, t_list **stack, t_list **b, int sizea, int sizeb)
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
			vars.sizea = sizea;
			vars.sizeb = sizeb;
			ft_rotateandpushtoa(stack, b, ft_findmoves(&vars), &vars);
			break ;
		}
		count++;
		tmp = tmp->next;
	}
}

void	findshortway(t_list **stack, t_list **b,int sizea,int sizeb)
{
	t_list	*tmp;
	t_vars1	vars;

	tmp = *b;
	vars.count = 0;
	vars.minmoves = 2147483647;
	while (tmp)
	{
		vars.posa = ft_findposinstacka(stack, tmp->num);
		vars.moves = ft_longbtwn(vars.count, vars.posa, sizea, sizeb);
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
	ft_movenumtoa(vars.num, stack, b, sizea, sizeb);
}

void	ft_push0marktoa(t_list **stack, t_list **b)
{
	int	sizea;
	int	sizeb;

	sizea = ft_lstsize(*stack);
	sizeb = ft_lstsize(*b);
	while (sizeb)
	{
		findshortway(stack, b, sizea, sizeb);
		sizeb = ft_lstsize(*b);
		sizea = ft_lstsize(*stack);
	}
}

void	ft_fakeswap(t_list **stack, int size)
{
	int	min;

	min = (*stack)->lis;
	swap(stack);
	ft_makezeros(stack);
	findlis(stack, size);
	if ((*stack)->lis > min)
		ft_putendl_fd("sa", 1);
	else
	{
		swap(stack);
		ft_makezeros(stack);
		findlis(stack, size);
	}
}

void	ft_push0marktob(t_list **stack, t_list **b, int size)
{
	t_list	*tmp;
	int		count;
	t_list	*tmp2;
	int		min;

	min = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (tmp->mark == 0)
		{
			count = ft_counter(stack, tmp);
			ft_pushtob(stack, b, size, count);
			ft_makezeros(stack);
			size = ft_lstsize(*stack);
			ft_makezeros(stack);
			//findlis(stack, size);
			//ft_fakeswap(stack, size);
		}
		tmp = tmp2;
	}
}
void	ft_mintomoon(t_list **stack, int count, int size)
{
	t_list	*tmp;

	tmp = *stack;
	if (count > size / 2)
	{
		while (size - count > 0)
		{
			rrotate(stack);
			ft_putendl_fd("rra", 1);
			count++;
		}
	}
	else
	{
		while (count-- > 0)
		{
			rotate(stack);
			ft_putendl_fd("ra", 1);
		}
	}
}

void	ft_mintotop(t_list **stack, int size)
{
	t_list	*tmp;
	int		min;
	int		count ;
	int		tmpcount;

	count = 0;
	tmp = *stack;
	min = tmp->num;
	while (tmp)
	{
		if (tmp->num <= min)
		{
			min = tmp->num;
			tmpcount = count;
		}
		count++;
		tmp = tmp->next;
	}
	ft_mintomoon(stack, tmpcount, size);
}
void	ft_longsort(t_list **stack, t_list **b)
{
	t_list	*tmp;
	int		min;
	int		size;

	size = ft_lstsize(*stack);
	tmp = *stack;
	findlis(stack, size);
	ft_fakeswap(stack, size);
	ft_push0marktob(stack, b, ft_lstsize(*stack));
	ft_push0marktoa(stack, b);
	size = ft_lstsize(*stack);
	ft_mintotop(stack, size);
}

int	ft_createstack(char **arg, t_list **head)
{
	int		i;
	int		j;
	char	**splited;

	i = 0;
	j = -1;
	while (arg[++i])
	{
		j = -1;
		splited = ft_split(arg[i], ' ');
		if (!ft_strncmp(arg[i], "", 1) || splited[0] == NULL)
			return (free(splited), 0);
		while (splited[++j])
		{
			if (!ft_checkformat(splited[j]) || !ft_strncmp(splited[j], "", 1))
				return (free(splited[j]), free(splited), 0);
			ft_lstadd_back(head, ft_lstnew(ft_atoi(splited[j])));
			free(splited[j]);
		}
		free(splited);
	}
	return (1);
}

int main(int a, char **arg)
{
	t_list	*stack;
	t_list	*tmp;
	t_list	*b;

	if (a == 1)
		return (0);
	b = NULL;
	if (!ft_createstack(arg, &stack))
	{
		ft_putendl_fd("Error", 1);
		ft_lstclear(&stack, free);
		exit (1);
	}
	ft_makezeros(&stack);
	tmp = stack;
	ft_longsort(&stack, &b);
	ft_lstclear(&stack, free);
	return (0);
}	
