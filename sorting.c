/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:42:29 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/03 23:05:32 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_middle(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	i;
	int	size;
	int	value1;
	int	position;

	i = 0;
	size = stack_size(*stack_a);
	while (size > 3)
	{
		push_min_to_b(stack_a, stack_b);
		size--;
		i++;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		value1 = (*stack_b)->value;
		position = find_insert_position(*stack_a, value1);
		rotate_to_position(stack_a, position);
		pa(stack_b, stack_a);
	}
}
