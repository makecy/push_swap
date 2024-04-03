/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allsorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:23:02 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/03 23:07:18 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_node *stack)
{
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

void	sorts(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	ss;

	if (!stack_a)
	{
		free_stack(stack_a);
		error();
	}
	ss = stack_size(stack_a);
	if (is_sorted(stack_a))
		return (free_stack(stack_a));
	if (ss == 1)
		error();
	else if ((!is_sorted(stack_a)) && (ss == 2))
		sa(&stack_a);
	else if (ss == 3)
		sort_three(&stack_a);
	else if (ss <= 10)
		sort_middle(&stack_a, &stack_b);
	else
	{
		ksort1(&stack_a, &stack_b, ss);
		ksort2(&stack_a, &stack_b, ss);
	}
	free_stack(stack_a);
	free_stack(stack_b);
}
