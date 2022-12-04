#include "push_swap.h"

void swap(t_list **stack)
{
	t_list *head;
	t_list *tmp;
	t_list *tmpnxt;

	
	head = *stack;
	tmp = head->next;
	if (!tmp)
		return;
	tmpnxt = tmp->next;
	*stack = tmp;
	tmp->next = head;
	head->next = tmpnxt;
}

void push(t_list **a, t_list **b)
{
	t_list *tmpb;
	t_list *tmp;
	tmpb = *b;
	if(!tmpb)
		return ;
	*b = tmpb->next;
	ft_lstadd_front(a,tmpb);
}

void rotate(t_list **stack)
{
	t_list *head;
	t_list *last;
	t_list *tmp;
	if(ft_lstsize(*stack) == 2)
		swap(stack);
	if(ft_lstsize(*stack) > 2)
	{
		tmp = *stack;
		head = *stack;
		last = ft_lstlast(*stack);
		while (tmp->next != last)
			tmp = tmp->next;
		last->next = head;
		tmp->next = NULL;
		*stack = last;
	}
	
}

void rrotate(t_list **stack)
{
	t_list *head;
	t_list *tail;
	if(ft_lstsize(*stack) == 2)
		swap(stack);
	tail = ft_lstlast(*stack);
	head = *stack;
	*stack = head->next;
	tail->next = head;
	head->next = NULL;
}
