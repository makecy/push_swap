/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 05:21:33 by mstefano          #+#    #+#             */
/*   Updated: 2024/02/27 03:04:51 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **stack_a)
{
	t_stack_node	*last;
	t_stack_node	*temp;

	last = *stack_a;
	temp = *stack_a;
	while (last->next)
		last = last->next;
	if (last == *stack_a)
		error();
	temp = last->prev;
	last->next = *stack_a;
	temp->next = NULL;
	last->prev = NULL;
	(*stack_a)->prev = last;
}

void	rrb(t_stack_node **stack_b)
{
	t_stack_node	*last;
	t_stack_node	*temp;

	last = *stack_b;
	temp = *stack_b;
	while (last->next)
		last = last->next;
	if (last == *stack_b)
		error();
	temp = last->prev;
	last->next = *stack_b;
	temp->next = NULL;
	last->prev = NULL;
	(*stack_b)->prev = last;
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
