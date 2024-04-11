/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allsorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:23:02 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/09 18:42:32 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorts(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	ss;

	if (!stack_a)
		free_stack(*stack_a, true);
	ss = stack_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	else if ((!is_sorted(*stack_a)) && (ss == 2))
		sa(stack_a, true);
	else if (ss == 3)
		sort_three(stack_a);
	else if (ss <= 10)
		sort_middle(stack_a, stack_b);
	else
	{
		ksort1(stack_a, stack_b, ss);
		ksort2(stack_a, stack_b, ss);
	}
}
