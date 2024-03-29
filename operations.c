/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:15:06 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/27 15:52:49 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	if (*stack_1 == NULL)
		return ;
	tmp = *stack_1;
	*stack_1 = tmp->next;
	tmp->next = *stack_2;
	*stack_2 = tmp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
}
