/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:22:11 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/02 21:00:00 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	stack_a = create_stack(argc, argv, stack_a);
	if (is_sorted(stack_a))
	{
		printf("The stack is already Sorted\n");
		return (0);
	}
	else if ((!is_sorted(stack_a)) && (argc == 2))
	{
		sa(&stack_a);
		printf("sa\n");
	}
	else if (argc > 2)
	{
		sort3_stack(&stack_a);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
