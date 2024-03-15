/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:43:47 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/14 17:44:18 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	min;
	int	position;

	min = find_min(*stack_a);
	position = find_position(*stack_a, min);
	rotate_to_position(stack_a, position);
	pb(stack_a, stack_b);
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

void	rotate_to_position(t_stack_node **stack, int position)
{
	int	size;

	size = stack_size(*stack);
	if (position < size / 2)
	{
		while (position--)
			ra(stack);
	}
	else
	{
		position = size - position;
		while (position--)
			rra(stack);
	}
}

int	find_insert_position(t_stack_node *stack, int value)
{
	int	position;

	position = 0;
	while (stack && stack->value < value)
	{
		position++;
		stack = stack->next;
	}
	return (position);
}
