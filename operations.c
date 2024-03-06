/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:19:33 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/06 19:20:13 by mstefano         ###   ########.fr       */
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
	ft_putstr_fd("sa\n", 1);
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
	ft_printf("sb\n");
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
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
	ft_printf("pa\n");
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
	ft_printf("pb\n");
}
