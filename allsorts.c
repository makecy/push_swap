/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allsorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:23:02 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/27 18:01:45 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorts(t_stack_node *stack_a, t_stack_node *stack_b, int argc)
{
	if ((stack_size(stack_a) == 1))
		error();
	if (!stack_a)
		error();
	if (is_sorted(stack_a))
	{
		ft_printf("The stack is already Sorted\n");
		return ;
	}
	else if ((!is_sorted(stack_a)) && (argc == 3))
		sa(&stack_a);
	else if (argc == 4)
		sort_three(&stack_a);
	else if (argc <= 11)
		sort_middle(&stack_a, &stack_b);
	else
	{
		ksort1(&stack_a, &stack_b, argc - 1);
		ksort2(&stack_a, &stack_b, argc - 1);
	}
}
