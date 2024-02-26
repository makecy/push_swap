/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:19:33 by mstefano          #+#    #+#             */
/*   Updated: 2024/02/26 04:39:15 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **stack_a)
{
	t_stack_node	*temp;

	if (stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		stack_a = (*stack_a)->next;
		temp->next = (*stack_a)->next;
		(*stack_a)->next = temp;
		temp->next->prev = temp;
		(*stack_a)->prev = NULL;
	}
}

void	sb(t_stack_node **stack_b)
{
	t_stack_node	*temp;

	if (stack_b && (*stack_b)->next)
	{
		temp = *stack_b;
		stack_b = (*stack_b)->next;
		temp->next = (*stack_b)->next;
		(*stack_b)->next = temp;
		temp->next->prev = temp;
		(*stack_b)->prev = NULL;
	}
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp;

	if (stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		temp->next = *stack_a;
		(*stack_a)->prev = temp;
		(*stack_a) = temp;
		(*stack_a)->prev = NULL;
	}
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp;

	if (stack_a && stack_b)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		temp->next = *stack_b;
		(*stack_b)->prev = temp;
		(*stack_b) = temp;
		(*stack_b)->prev = NULL;
	}
	else
	{
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		(*stack_b)->next = NULL;
	}
}

void	ra(t_stack_node **stack_a)
{
	t_stack_node	*last;
	t_stack_node	*temp;

	temp = *stack_a;
	while (last->next)
		last = last->next;
	last->next = temp;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	temp->next = NULL;
	temp->prev = last;
}

void	rb(t_stack_node **stack_b)
{
	
}
