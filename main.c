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
			ft_lstadd_front(head,ft_lstnew(ft_atoi(splited[j])));
			free(splited[j]);
		}
		free(splited);
	}
	return (1);
}
void ft_sort(t_list **stack)
{
	t_list *b;
	b = NULL;
	t_list *tmp;
	tmp = *stack;
	swap(stack);
	push(&b,stack);
	push(&b,stack);
	push(&b,stack);
	rotate(&b);
	rotate(stack);
	rrotate(&b);
	rrotate(stack);
	push(stack,&b);
	push(stack,&b);
	push(stack,&b);

}

int main(int a, char **arg)
{
	t_list *tmp;
	if (a == 1 )
		return 0;
	t_list *stack;
	
	if (!ft_createstack(arg,&stack))
		{
			ft_putendl_fd("error",1);
			return 0;
		}
	ft_sort(&stack);
	while (stack)
	{
		printf("stack == %d\n",stack->num);
		stack = stack->next;
	}
	
	return 0;
}