#include "push_swap.h"


void ft_printlist(t_list *stack)
{
	t_list *tmp;
	tmp = stack;
	while(tmp)
	{
		printf( "num == %d || lis == %d || mark == %d \n ",tmp->num,tmp->lis,tmp->mark);
		tmp = tmp->next;
	}
}


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

void ft_pushtob(t_list **stack,t_list **b,int size,int count)
{
	int k;
	if(count <= size / 2)
	{
		while(count-- > 1)
		{
			 rotate(stack);
			 ft_putstr_fd("ra\n",1);
		}
		push(b,stack);
		ft_putstr_fd("pb\n",1);
	}

	else
	{
		while(count++ <= size)
		{
			 rrotate(stack);
			 ft_putstr_fd("rra\n",1);
		}
		push(b,stack);
		ft_putstr_fd("pb\n",1);
	}
}

int ft_counter(t_list **stack,t_list *tofind)
{
	t_list *tmp;
	int count = 1;

	tmp = *stack;
	while(tmp)
	{
		if(tmp == tofind)
			return count;
		count++;
		tmp = tmp->next;
	}
	return 0;
}

int ft_findposinstacka(t_list **stack,int num)
{
	t_list	*tmp;
	int count = 0;
	tmp = *stack;
	int count2 = 0;
	int min = 2147483647;
	while(tmp)
	{
		if(tmp->num <= min && tmp->num >= num )
		{
			min = tmp->num;
			count2 = count;
		}
		count++;
		tmp = tmp->next;
	}
	return count2;
}

int	ft_findmoves(int count,int posa,int sizea,int sizeb)
{
	if(count <= sizeb / 2 && posa <= sizea / 2)
		return (2);
	else if(count >= sizeb / 2 && posa >= sizea / 2)
		return (1);
	else if(count <= sizeb / 2 && posa >= sizea / 2)
		return (3);
	else if(count >= sizeb / 2 && posa <= sizea / 2)
		return (4);
	return 0;
}

int	ft_longbtwn(int count,int posa,int sizea,int sizeb)
{
	if(count < sizeb / 2 && posa < sizea / 2 && count >= posa)
		return (count);
	else if(count < sizeb / 2 && posa < sizea / 2 && count <= posa)
		return (posa);
	else if(count >= sizeb / 2 && posa >= sizea / 2 && sizeb - count <= sizea - posa)
		return (sizeb - count);
	else if(count >= sizeb / 2 && posa >= sizea / 2 && sizeb - count >= sizea - posa)
		return (sizea - posa);
	else if(count <= sizeb / 2 && posa >= sizea / 2)
		return (count + (sizea - posa));
	else if(count >= sizeb / 2 && posa <= sizea / 2)
		return (posa + (sizeb - count));
	return 0;
}
void ft_dorotate(int count,t_list **stack,t_list **b)
{
	if(stack && b)
		{
			while(count-- > 0)
			{
				ft_putendl_fd("rr",1);
				rotate(stack);
				rotate(b);
			}
		}
	else if(stack && !b)
		{
			while(count-- > 0)
			{
				rotate(stack);
				ft_putendl_fd("ra",1);
			}
		}
	else if(!stack && b)
		{
			while(count-- > 0)
			{
				rotate(b);
				ft_putendl_fd("rb",1);
			}
		}
}

void ft_dorrotate(int count,t_list **stack,t_list **b)
{
	if(stack && b)
		{
			while(count-- > 0)
			{
				ft_putendl_fd("rrr",1);
				rrotate(stack);
				rrotate(b);
			}
		}
	else if(stack && !b)
		{
			while(count-- > 0)
			{
				rrotate(stack);
				ft_putendl_fd("rra",1);
			}
		}
	else if(!stack && b)
		{
			while(count-- > 0)
			{
				rrotate(b);
				ft_putendl_fd("rrb",1);
			}
		}
}
void ft_rotateandpushtoa(t_list **stack,t_list **b,int index,int count,int posa)
{
	int sizeb = ft_lstsize(*b);
	int sizea = ft_lstsize(*stack);
	if(count == 0)
	{
		//printf("count == 0 \n");
		if(posa > sizea / 2)
			ft_dorrotate(sizea - posa,stack,NULL);
		else
			ft_dorotate(posa ,stack,NULL);
	}
	else if(posa == 0)
	{
		//printf("posa == 0 \n");
		if(count > sizeb / 2)
			ft_dorrotate(sizeb - count,NULL,b);
		else
			ft_dorotate(count ,NULL,b);
	}
	else if(index == 1)
		{
			//printf("index is 1 \n");
			if(sizea - posa <= sizeb - count)
			{
				ft_dorrotate(sizea - posa ,stack,b);
				ft_dorrotate((sizeb - count) - (sizea - posa) ,NULL,b);
			}
			else
				{
				ft_dorrotate(sizeb - count,stack,b);
				ft_dorrotate((sizea - posa) - (sizeb - count),stack,NULL);
				}
		}
	else if(index == 2)
	{
		//printf("index is 2 \n");

			if(posa >= count)
			{
				ft_dorotate(count,stack,b);
				ft_dorotate(posa - count ,stack,NULL);
				
			}
			else
				{
				ft_dorotate(posa,stack,b);
				ft_dorotate(count - posa ,NULL,b);
				}
	}
	else if(index == 3)
	{
		//printf("index is 3 \n");
				ft_dorotate(count,NULL,b);
				ft_dorrotate(sizea-posa ,stack,NULL);
	}
	else if(index == 4)
	{
		//printf("index is 4 \n");
		ft_dorotate(posa,stack,NULL);
		ft_dorrotate(sizeb-count ,NULL,b);
	}
	push(stack,b);
	ft_putendl_fd("pa",1);
}

void ft_movenumtoa(int num,t_list **stack,t_list **b,int sizea,int sizeb)
{
	t_list	*tmp;
	int count = 0;
	tmp = *b;
	int posa = ft_findposinstacka(stack,num);
	while(tmp)
	{
		if(tmp->num == num)
		{
			//printf("num == %d count == %d  pos a == %d\n",num,count,posa);
			ft_rotateandpushtoa(stack,b,ft_findmoves(count,posa,sizea,sizeb),count,posa);
			break;
		}
		count++;
		tmp = tmp->next;
	}
}

void findshortway(t_list **stack, t_list **b,int sizea,int sizeb)
{
	t_list	*tmp;
	int		num;
	int		count;
	int		moves;
	int		minmoves;
	int		posa;

	tmp = *b;
	count = 0;
	minmoves = 2147483647;
	while(tmp)
	{
		posa = ft_findposinstacka(stack,tmp->num);
		moves = ft_longbtwn(count,posa,sizea,sizeb);
		if(minmoves == 2147483647)
		{
			num = tmp->num;
			minmoves = moves;
		}
		if(moves < minmoves)
		{
			minmoves = moves;
			num = tmp->num;
		}
		count++;
		tmp = tmp->next;
	}
	ft_movenumtoa(num,stack,b,sizea,sizeb);
}

void ft_push0marktoa(t_list **stack, t_list **b)
{
	int sizea = ft_lstsize(*stack);
	int sizeb = ft_lstsize(*b);
	while(sizeb)
	{
		// printf("stack a : \n");
		// ft_printlist(*stack);
		// printf("stack b : \n");
		// ft_printlist(*b);
		findshortway(stack,b,sizea,sizeb);
		sizeb = ft_lstsize(*b);
		sizea = ft_lstsize(*stack);
	}
}

void ft_push0marktob(t_list **stack, t_list **b,int size)
{
	t_list *tmp;
	
	int count;
	t_list *tmp2;

	tmp = *stack;
	while(tmp)
	{
		tmp2 = tmp->next;
		if(tmp->mark == 0)	
		{
			count = ft_counter(stack,tmp);
			ft_pushtob(stack,b,size,count);
			size--;
		}
		tmp = tmp2;
	}
}
void ft_mintomoon(t_list **stack,int count,int size)
{
	t_list *tmp = *stack;
	if (count > size/2)
	{
		while(size - count > 0)
		{
			rrotate(stack);
			ft_putendl_fd("rra",1);
			count++;
		}
	}
	else 
	{
		while(count-- > 0)
		{
			rrotate(stack);
			ft_putendl_fd("ra",1);
		}
	}

}
void ft_mintotop(t_list **stack,int size)
{
	t_list *tmp;
	int min;
	int count = 0;
	int tmpcount;
	tmp = *stack;
	min = tmp->num;
	while(tmp)
	{

		if(tmp->num <= min)
		{
			min = tmp->num;
			tmpcount = count;
		}
		count++;
		tmp = tmp->next;
	}
	ft_mintomoon(stack,tmpcount,size);
}
void ft_longsort(t_list **stack, t_list **b)
{
	t_list *tmp;
	int size = ft_lstsize(*stack);
	tmp = *stack;
	int min;
	ft_findlis(stack);
	ft_push0marktob(stack,b,ft_lstsize(*stack));
	ft_push0marktoa(stack,b);
	ft_mintotop(stack,size);
	
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
		splited = ft_split(arg[i],' ');
		if (!ft_strncmp(arg[i],"",1) || splited[0] == NULL)
			return 0;
		while(splited[++j])
		{
			if(!ft_checkformat(splited[j]) || !ft_strncmp(splited[j],"",1))
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
	t_list *b;

	b = NULL;
	if (!ft_createstack(arg,&stack))
		{
			ft_putendl_fd("Error",1);
			exit (1);
		}
	ft_makezeros(&stack);
	tmp = stack;
	ft_longsort(&stack,&b);
	tmp = stack;
	while(tmp)
	{
		//printf("stack a :: ||  num == %d || lis == %d || mark == %d \n ",tmp->num,tmp->lis,tmp->mark);
		tmp = tmp->next;
	}
	
	return 0;
}	