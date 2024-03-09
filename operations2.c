/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 05:21:33 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/09 23:51:07 by mstefano         ###   ########.fr       */
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
	if (last->prev)
		last->prev->next = NULL;
	last->next = *stack_a;
	temp->next = NULL;
	last->prev = NULL;
	(*stack_a)->prev = last;
	*stack_a = last;
	ft_printf("rra\n");
}

void	rrb(t_stack_node **stack_b)
{
	t_stack_node	*last;
	t_stack_node	*temp;

	last = *stack_b;
	temp = *stack_b;
	while (last->next)
		last = last->next;
	if (last->prev)
		temp = last->prev;
	last->next = *stack_b;
	temp->next = NULL;
	last->prev = NULL;
	stack_b = &last;
	(*stack_b)->prev = last;
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}
