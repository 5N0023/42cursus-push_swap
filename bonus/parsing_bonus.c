/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:19:18 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/10 20:40:24 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_checkduplicate(t_list **head, int num)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (num == tmp->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
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
			if (ft_checkduplicate(head, ft_atoi(splited[j])))
				return (free(splited[j]), free(splited), 0);
			ft_lstadd_back(head, ft_lstnew(ft_atoi(splited[j])));
			free(splited[j]);
		}
		free(splited);
	}
	return (1);
}
