/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:22:11 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/06 18:29:20 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;

	stack_a = NULL;
	stack_a = create_stack(argc, argv, stack_a);
	if (is_sorted(stack_a))
	{
		printf("The stack is already Sorted\n");
		return (0);
	}
	else if ((!is_sorted(stack_a)) && (argc == 3))
	{
		sa(&stack_a);
	}
	else if (argc > 3)
	{
		sort3_stack(&stack_a);
	}
	free_stack(stack_a);
	return (0);
}
