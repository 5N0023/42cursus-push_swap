/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:53:23 by mlektaib          #+#    #+#             */
/*   Updated: 2023/01/10 20:14:18 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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

typedef struct s_vars2
{
	int		*length;
	int		*sub;
}	t_vars2;

typedef struct s_vars3
{
	int		sizea;
	int		sizeb;
}	t_vars3;

typedef struct s_list
{
	int				num;
	int				lis;
	int				mark;
	struct s_list	*next;
}	t_list;

void	rotate(t_list **stack);
void	swap(t_list **stack);
void	rrotate(t_list **stack);
void	push(t_list **a, t_list **b);
int		ft_counter(t_list **stack, t_list *tofind);
int		ft_findposinstackamax(t_list **stack, int num);
int		ft_findposinstacka(t_list **stack, int num);
int		ft_findmoves(t_vars *vars);
int		ft_longbtwn(int count, int posa, int sizea, int sizeb);
void	ft_getnumbers(t_list **stack, int *tab, t_vars2 *tables, int size);
void	lis(t_list **stack,	int *tab, t_vars2 *tables, int size);
int		*ft_settab(t_list *min, int size);
t_list	*ft_findmin(t_list *stack);
void	findlis(t_list **stack, int size);
void	ft_makezeros(t_list **stack);
int		ft_max(int *tab, int size);
void	ft_markintstack(t_list **stack, int num);
void	ft_dorotate(int count, t_list **stack, t_list **b);
void	ft_dorrotate(int count, t_list **stack, t_list **b);
void	findshortway(t_list **stack, t_list **b, t_vars3 *sizes);
void	ft_push0marktoa(t_list **stack, t_list **b);
void	ft_longsort(t_list **stack, t_list **b, int size);
void	ft_pushtoa(t_list **stack, t_list **b);
void	ft_sort2number(t_list **stack);
void	ft_sort3number(t_list **stack, int size);
void	ft_shortsort(t_list **stack, t_list **b, int size);
t_list	*ft_lstnew(int num);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
long	ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_fakeswap(t_list **stack, int size);
void	ft_push0marktob(t_list **stack, t_list **b, int size);
void	ft_mintomoon(t_list **stack, int count, int size);
void	ft_mintotop(t_list **stack, int size);
void	ft_pushtob(t_list **stack, t_list **b, int size, int count);
void	ft_movenumtoa(int num, t_list **stack, t_list **b, t_vars3 *sizes);
int		ft_createstack(char **arg, t_list **head);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_isdigit(int n);
size_t	ft_strlen(const char *str);

#endif
