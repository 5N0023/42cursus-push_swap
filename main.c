#include "push_swap.h"


int ft_checkformat(char *num)
{
	if (*num == '-' || *num == '+')
		num++;
	else if(!ft_isdigit(*num))
		return (0);
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}

void ft_marklis(t_list **stack)
{
	t_list *head;
	t_list *tmp;
	head = *stack;
	if(!head)
		return;
	int prev = head->num;
	head->mark = 1;
	tmp = head->next;
	if(!tmp)
		return;
	while(tmp != head)
	{
		if (tmp->num > prev)
			{
				prev = tmp->num;
				tmp->mark = 1;
			}
		tmp = tmp->next;
	}
}

t_list *ft_findmaxlis(t_list **stack)
{
	t_list *tmp;
	tmp = *stack;
	t_list *ret;
	int max = tmp->lis; 
	ret = tmp;
	while(tmp)
	{
		if(tmp->lis > max)
		{
			ret = tmp;
			max = tmp->lis;
		}
		tmp = tmp->next;
	}
	return ret;
}
void ft_findlis2(t_list **stack)
{
	t_list *head;
	t_list *tmp;
	head = *stack;
	int prev = head->num;
	tmp = head->next;
	while(tmp != head)
	{
		if (tmp->num > prev)
			{
				prev = tmp->num;
				head->lis++;
			}
		tmp = tmp->next;
	}
}
void ft_findlis(t_list **stack)
{
	t_list *tail;
	t_list *head;
	t_list *tmphead;

	head = *stack;
	tail = ft_lstlast(*stack);
	tail->next = head;
	tmphead = head->next;
	ft_findlis2(&head);
	while(tmphead != head)
	{
		ft_findlis2(&tmphead);
		tmphead = tmphead->next;
	}
	tail->next = NULL;
	tmphead = ft_findmaxlis(stack);
	tail->next = head;
	ft_marklis(&tmphead);
	tail->next = NULL;
}

void ft_longsort(t_list **stack)
{
	t_list *tmp;
	tmp = *stack;
	ft_findlis(stack);
}

int ft_createstack(char **arg,t_list **head)
{
	int i;
	int j;


	i = 0;
	j = -1;
	char **splited;
	while (arg[++i])
	{
		j = -1;
		if (!ft_strncmp(arg[i],"",1))
			return 0;
		splited = ft_split(arg[i],' ');
		while(splited[++j])
		{
			if(!ft_checkformat(splited[j]))
				return 0;
			ft_lstadd_back(head,ft_lstnew(ft_atoi(splited[j])));
			free(splited[j]);
		}
		free(splited);
	}
	return (1);
}

void ft_makezeros(t_list **stack)
{
	t_list *tmp;
	tmp = *stack;
	while(tmp)
	{
		tmp->lis = 1;
		tmp->mark = 0;
		tmp = tmp->next;
	}
}
int main(int a, char **arg)
{
	if (a == 1 )
		return 0;
	t_list *stack;
	t_list *tmp;
	
	if (!ft_createstack(arg,&stack))
		{
			ft_putendl_fd("error",1);
			return 0;
		}
	ft_makezeros(&stack);
	tmp = stack;
	ft_longsort(&stack);
	return 0;
}