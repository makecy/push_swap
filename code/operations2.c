/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 05:21:33 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/09 02:13:10 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **stack_a, bool print)
{
	t_stack_node	*last;
	t_stack_node	*temp;

	last = *stack_a;
	temp = *stack_a;
	while (last && last->next)
		last = last->next;
	if (last && last->prev)
	{
		temp = last->prev;
		if (last->prev)
			last->prev->next = NULL;
		last->next = *stack_a;
		if (temp)
			temp->next = NULL;
		(*stack_a)->prev = last;
		*stack_a = last;
	}
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **stack_b, bool print)
{
	t_stack_node	*last;
	t_stack_node	*temp;

	last = *stack_b;
	temp = *stack_b;
	while (last && last->next)
		last = last->next;
	if (last && last->prev)
	{
		temp = last->prev;
		last->prev->next = NULL;
		last->next = *stack_b;
		temp->next = NULL;
		(*stack_b)->prev = last;
		*stack_b = last;
	}
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	rra(stack_a, false);
	rrb(stack_b, false);
	if (print)
		ft_printf("rrr\n");
}
