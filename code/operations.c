/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:19:33 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/09 03:50:33 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **stack_a, bool print)
{
	t_stack_node	*temp;

	if (stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = (*stack_a)->next;
		(*stack_a)->next = temp;
	}
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **stack_b, bool print)
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
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	sa(stack_a, false);
	sb(stack_b, false);
	if (print)
		ft_printf("ss\n");
}

void	pa(t_stack_node **stack_b, t_stack_node **stack_a, bool print)
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
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
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
	if (print)
		ft_printf("pb\n");
}
