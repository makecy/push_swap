/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:46:08 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/27 22:31:06 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ksort1(t_stack_node **stack_a, t_stack_node **stack_b, int length)
{
	int	i;
	int	j;

	i = 0;
	j = ft_sqrt(length) * 14 / 10;
	while (*stack_a)
	{
		if ((*stack_a)->value <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->value <= i + j)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if (!(*stack_a)->next)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

// void	ksort2(t_stack_node **stack_a, t_stack_node **stack_b, int length)
// {
// 	int				i;
// 	int				j;

// 	while (length - 1 >= 0)
// 	{
// 		i = count(*stack_b, length - 1);
// 		j = (length + 3) - i;
// 		if (i <= j)
// 		{
// 			while ((*stack_b)->value != length - 1)
// 				rb(stack_b);
// 			pa(stack_b, stack_a);
// 		}
// 		// length--;
// 		else
// 		{
// 			while ((*stack_b)->value != length - 1)
// 				rrb(stack_b);
// 			pa(stack_b, stack_a);
// 		}
// 		length--;
// 	}
// }

void	ksort2(t_stack_node **stack_a, t_stack_node **stack_b, int length)
{
	int	i;
	int	max_value;

	while (length > 0)
	{
		max_value = find_max_value(*stack_b);
		i = find_position(*stack_b, max_value);
		if (i <= stack_size(*stack_b) / 2)
			while ((*stack_b)->value != max_value)
				rb(stack_b);
		else
			while ((*stack_b)->value != max_value)
				rrb(stack_b);
		pa(stack_b, stack_a);
		length--;
	}
}
