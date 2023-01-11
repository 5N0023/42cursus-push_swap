/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:53:23 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/11 16:37:20 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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
int		ft_checkifsorted(t_list **stack);
size_t	ft_strlen(const char *str);
int		ft_isdigit(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(int num);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
long	ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_createstack(char **arg, t_list **head);

#endif
