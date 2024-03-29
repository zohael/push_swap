/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:32:55 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/27 16:07:09 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack)
{
	t_list	*tmp;
	int		max;

	max = get_max(*stack);
	tmp = *stack;
	if ((*stack)->value == max)
		ra(stack);
	else if ((*stack)->next->value == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	mini_sort_5(t_list **stack_a, t_list **stack_b, int number)
{
	while (is_be(*stack_a, number))
	{
		if (number == (*stack_a)->value)
		{
			pb(stack_a, stack_b);
			break ;
		}
		else if (number == (*stack_a)->next->value)
		{
			sa(stack_a);
			pb(stack_a, stack_b);
			break ;
		}
		else
			rra(stack_a);
	}
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	max;

	min = get_min(*stack_a);
	max = get_max(*stack_a);
	mini_sort_5(stack_a, stack_b, max);
	mini_sort_5(stack_a, stack_b, min);
	sort_3(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	ra(stack_a);
}

void	mini_sort(t_list **stack, t_list **stack_b)
{
	if (ft_lstsize(*stack) == 2)
		sa(stack);
	else if (ft_lstsize(*stack) == 3)
		sort_3(stack);
	else if (ft_lstsize(*stack) == 5)
		sort_5(stack, stack_b);
}
