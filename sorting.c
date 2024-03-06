/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:42:29 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/06 19:18:38 by mstefano         ###   ########.fr       */
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

// void	sort3_stack(t_stack_node **stack_a)
// {
// 	int	a;
// 	int	b;
// 	int	c;

// 	a = (*stack_a)->value;
// 	b = (*stack_a)->next->value;
// 	c = (*stack_a)->next->next->value;
// 	if (a > b && a > c && b < c)
// 		ra(stack_a);
// 	else if (a > b && a > c && b > c)
// 	{
// 		ra(stack_a);
// 		sa(stack_a);
// 	}
// 	else if (a > b && a < c)
// 		sa(stack_a);
// 	else if (a > b && b < c)
// 		rra(stack_a);
// 	else if (a < b && a > c)
// 		rra(stack_a);
// 	else if (a < b && b > c)
// 	{
// 		ft_putstr_fd("ok\n", 1);
// 		rra(stack_a);
// 		ft_putstr_fd("ok\n", 1);
// 		sa(stack_a);
// 	}
// }

void	sort3_stack(t_stack_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && a > c)
	{
		ra(stack_a);
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (b > c && b > a)
	{
		if (a > c)
			rra(stack_a);
		else
		{
			rra(stack_a);
			sa(stack_a);
		}
	}
	else if (a > b)
		sa(stack_a);
}
