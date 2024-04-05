/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 05:09:34 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/02 21:22:32 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **stack_a)
{
	t_stack_node	*last;
	t_stack_node	*temp;

	last = *stack_a;
	temp = *stack_a;
	while (last->next)
		last = last->next;
	if (last == *stack_a)
		error();
	last->next = temp;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	temp->next = NULL;
	temp->prev = last;
	printf("ra\n");
}

void	rb(t_stack_node **stack_b)
{
	t_stack_node	*last;
	t_stack_node	*temp;

	last = *stack_b;
	temp = *stack_b;
	while (last->next)
		last = last->next;
	if (last == *stack_b)
		return ;
	last->next = temp;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	temp->next = NULL;
	temp->prev = last;
	printf("rb\n");
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	printf("rr\n");
}
