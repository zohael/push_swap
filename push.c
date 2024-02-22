// 



#include "push_swap.h"

int	ft_check_max(t_list *stack, int max)
{
	while (stack)
	{
		if (max == stack->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
int	find_max(t_list *stack, int max)
{
	while (stack)
	{
		if (stack->value == max)
			return (stack->moves);
		stack = stack->next;
	}
	return (-1);
}

int find_near(t_list *stack_a,int *table,int the_end,int start)
{
	int save;
	save =start;
  while(stack_a)
  {
	while(save <= the_end)
	{
		if(stack_a->value == table[save])
			return stack_a->moves;
			save++;
	}
	stack_a=stack_a->next;
	save=start;

	}
	return -1;
}
int find_near1(t_list *stack_a,int *table,int the_end,int start)
{
	int save;
	int k;
	save =start;
	k =-1;
  while(stack_a)
  {
	while(save <= the_end)
	{
		if(stack_a->value == table[save])
			k= stack_a->moves;
		save++;
	}
	stack_a=stack_a->next;
	save=start;

	}
	return k;
}
void choice_move(t_list **stack_a,int *table,int the_end,int start)
{
	
	int i;
	int j;
	i = find_near(*stack_a,table,the_end,start);
	j = find_near(*stack_a,table,the_end,start);
	if(i < ft_lstsize(*stack_a)-j)
	{
		while(i > 0)
		{
			ra(stack_a);
			i--;
		}
	}
	else if(i > ft_lstsize(*stack_a)-j)
	{
		while(j <= ft_lstsize(*stack_a) )
		{
			rra(stack_a);
			j++;
		}
	}
	else if (i == ft_lstsize(*stack_a)-j)
	{
		while(i > 0)
		{
			ra(stack_a);
			i--;
		}
	}

}

void	push_a_to_b(t_list **stack_a, t_list **stack_b, int *table,int size_stack)
{
	int	mid;
	int	offset;
	int	start;
	int	the_end;

	offset = 0;
	mid = (size_stack / 2) - 1;
	if (size_stack > 3)
		offset = 1;
	if (size_stack > 5)
		offset = 2;
	if (size_stack > 50)
		offset = 8;
	if (size_stack > 150)
		offset =size_stack/20;
	start = mid - offset;
	the_end = mid + offset;
	while ((*stack_a))
	{
		if (ft_lstsize(*stack_a) == 1)
			pb(stack_a, stack_b);
		while (ft_lstsize(*stack_b) < the_end - start)
		{
			if ((*stack_a)->value >= table[start]
				&& (*stack_a)->value <= table[the_end])
			{
				pb(stack_a, stack_b);
				if ((*stack_b)->value < table[mid])
					rb(stack_b);
			}
			else
			{
				full_moves(stack_a);
				choice_move(stack_a,table,the_end,start);
				pb(stack_a, stack_b);
				if ((*stack_b)->value < table[mid])
					rb(stack_b);
				// ra(stack_a);
			}
				// ra(stack_a);
		}
		start = start - offset;
		if (start < 0)
			start = 0;
		the_end = the_end + offset;
		if (the_end >= size_stack)
			the_end = size_stack - 1;
	}
}
void	push_b_to_a(t_list **stack_a, t_list **stack_b, int *table,
		int size_stack)
{
	int	max;
	int k;
	k=0;
	max = size_stack - 1;
	while (*stack_b)
	{
		while (ft_check_max(*stack_b, table[max]))
		{
			if ((*stack_b)->value == table[max])
			{
				pa(stack_b, stack_a);
				max--;
			}
			// else if ((*stack_b)->value == table[max - 1]
			// 	&& (*stack_b)->next->value == table[max])
			// {
			// 	pa(stack_b, stack_a);
			// 	pa(stack_b, stack_a);
			// 	sa(stack_a);
			// 	max--;
			// }
			else if (ft_lstlast(*stack_b)->value == table[max])
			{
				rrb(stack_b);
				pa(stack_b, stack_a);
				max--;
			}
			else if((k==0 || ft_lstlast(*stack_a) -> value <  (*stack_b) -> value ) ) //1
			{
				// printf("llll\n");
				pa(stack_b, stack_a);
				ra(stack_a);
				k++;
			}
			else
			{
				full_moves(stack_b);
				if (find_max(*stack_b, table[max]) < (ft_lstsize(*stack_b) / 2))
				{
					if (find_max(*stack_b, table[max]) != 0)
						rb(stack_b);
				}
				else
				{
					if (find_max(*stack_b, table[max]) != 0)
						rrb(stack_b);
				}
			}
			
		}
		while(ft_check_max(*stack_a, table[max]) &&  ft_lstlast(*stack_a)->value == table[max])
		 {
			rra(stack_a);
			max--;
			k--;

		 }
	}
}


// void	push_b_to_a1(t_list **stack_a, t_list **stack_b, int *table,
// 		int size_stack)
// {
// 	int	max;
// 	int k;
// 	k=0;

// 	max = size_stack - 1;
// 	while (*stack_b)
// 	{
// 		if (ft_check_max(*stack_b, table[max]))
// 		{
// 			if ((*stack_b)->value == table[max])
// 			{
// 				pa(stack_b, stack_a);
// 				max--;
// 			}
// 			// else if ((*stack_b)->value == table[max - 1] && (*stack_b)->next->value == table[max])
// 			// {
// 			// 	pa(stack_b, stack_a);
// 			// 	pa(stack_b, stack_a);
// 			// 	sa(stack_a);
// 			// 	max=max-2;
// 			// }
// 			else if (ft_lstlast(*stack_b)->value == table[max])
// 			{
// 				rrb(stack_b);
// 				pa(stack_b, stack_a);
// 				max--;
// 			}
// 			else if((k==0 || ft_lstlast(*stack_a) -> value <  (*stack_b) -> value ) ) //1
// 			{
// 				// printf("llll\n");
// 				pa(stack_b, stack_a);
// 				ra(stack_a);
// 				k++;
// 			}
// 			else 
// 			{
// 				while(k--)
// 				{
// 					full_moves(stack_b);
// 			  		int i;
// 					i= find_max(*stack_b,table[max]);
// 					if(i < ft_lstsize(*stack_b)/2)
// 					{
// 						while(i >0)
// 						{
// 							rb(stack_b);
// 							i--;
// 						}
// 						pa(stack_b, stack_a);
// 					}
// 					else
// 					{
// 						while(i > ft_lstsize(*stack_b))
// 						{
// 							rrb(stack_b);
// 							i++;
// 						}
// 						pa(stack_b, stack_a);

// 					}
// 				}
// 				//rb(stack_)
// 			}
      
// 		}
// 	    else if(ft_check_max(*stack_a, table[max]) &&  ft_lstlast(*stack_a)->value == table[max])
// 		{
// 			// printf("not in b\n");
// 			while(k--)
// 			{
// 				rra(stack_a);
// 				max--;
// 			}
// 			// k--;
// 		}
		
// 	}
//  }
