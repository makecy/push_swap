/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:42:29 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/11 17:19:49 by mstefano         ###   ########.fr       */
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

void	sort_three(t_stack_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && a > c)
		ra(stack_a);
	else if (b > a && b > c)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}
// void	sort_three(t_stack_node **stack_a)
// {
// 	int	a;
// 	int	b;
// 	int	c;

// 	a = (*stack_a)->value;
// 	b = (*stack_a)->next->value;
// 	c = (*stack_a)->next->next->value;
// 	if (a > b && a > c)
// 	{
// 		stack_size(*stack_a);
// 		print_stack(*stack_a);
// 		ra(stack_a);
// 		stack_size(*stack_a);
// 		print_stack(*stack_a);
// 	}
// 	else if (b > a && b > c)
// 	{
// 		stack_size(*stack_a);
// 		print_stack(*stack_a);
// 		rra(stack_a);
// 		stack_size(*stack_a);
// 		print_stack(*stack_a);
// 	}
// 	if ((*stack_a)->value > (*stack_a)->next->value)
// 	{
// 		stack_size(*stack_a);
// 		print_stack(*stack_a);
// 		sa(stack_a);
// 		stack_size(*stack_a);
// 		print_stack(*stack_a);
// 	}
// }

// void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
// {
// 	int	i;
// 	int	size;

// 	i = 0;
// 	size = stack_size(*stack_a);
// 	while (i < 2)
// 	{
// 		pb(stack_a, stack_b);
// 		i++;
// 	}
// 	sort_three(stack_a);
// 	while (i < size)
// 	{
// 		pa(stack_a, stack_b);
// 		i++;
// 	}
// 	sort_three(stack_a);
// }
