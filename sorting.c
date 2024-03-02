/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:42:29 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/02 18:52:57 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_node *stack)
{
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

void	sort3_stack(t_stack_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a > b && b < c)
		ra(stack_a);
	else if (a < b && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a < b && b > c)
		rra(stack_a);
}
