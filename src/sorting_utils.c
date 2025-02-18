/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:43:47 by mstefano          #+#    #+#             */
/*   Updated: 2025/02/18 16:11:38 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_position(t_stack_node *stack, int value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->value == value)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

int	find_min(t_stack_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	push_min_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	min;
	int	position;

	min = find_min(*stack_a);
	position = find_position(*stack_a, min);
	rotate_to_position(stack_a, position);
	pb(stack_a, stack_b, true);
}

void	rotate_to_position(t_stack_node **stack, int position)
{
	int	size;

	size = stack_size(*stack);
	if (position < size / 2)
	{
		while (position--)
			ra(stack, true);
	}
	else
	{
		position = size - position;
		while (position--)
			rra(stack, true);
	}
}
