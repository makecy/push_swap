/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:19:33 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/02 19:37:40 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **stack_a)
{
	t_stack_node	*temp;

	if (stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = (*stack_a)->next;
		(*stack_a)->next = temp;
	}
	printf("sa\n");
}

void	sb(t_stack_node **stack_b)
{
	t_stack_node	*temp;

	if (stack_b && (*stack_b)->next)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = (*stack_b)->next;
		(*stack_b)->next = temp;
		temp->next->prev = temp;
		(*stack_b)->prev = NULL;
	}
	printf("sb\n");
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	printf("ss\n");
}

// void	pa(t_stack_node **stack_b, t_stack_node **stack_a)
// {
// 	t_stack_node	*new_head;

// 	if (!*stack_b)
// 		return ;
// 	new_head = new_node((*stack_b)->value);
// 	new_head->next = *stack_a;
// 	*stack_a = new_head;
// 	*stack_b = (*stack_b)->next;
// 	printf("pa\n");
// }

void	pa(t_stack_node **stack_b, t_stack_node **stack_a)
{
	t_stack_node	*move;
	t_stack_node	*last;
	
	if (!*stack_b)
		return ;
	move = (*stack_b);
	if (*stack_b && (*stack_b)->next)
		*stack_b = (*stack_b)->next;
	else
		*stack_b = NULL;
	if (*stack_b != NULL)
		(*stack_b)->prev = NULL;
	move->next = *stack_a;
	move->prev = NULL;
	if (*stack_a != NULL)
		(*stack_a)->prev = move;
	*stack_a = move;
	last = last_node(*stack_a);
	last->next = NULL;
	printf("pa\n");
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*move;
	t_stack_node	*last;

	if (!*stack_a)
		return ;
	move = (*stack_a);
	if (*stack_a && (*stack_a)->next)
		*stack_a = (*stack_a)->next;
	else
		*stack_a = NULL;
	if (*stack_a != NULL)
		(*stack_a)->prev = NULL;
	move->next = *stack_b;
	move->prev = NULL;
	if (*stack_b != NULL)
		(*stack_b)->prev = move;
	*stack_b = move;
	last = last_node(*stack_b);
	last->next = NULL;
	printf("pb\n");
}
