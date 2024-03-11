/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:22:11 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/11 15:32:24 by mstefano         ###   ########.fr       */
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
	if (!stack_a)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (is_sorted(stack_a))
	{
		ft_printf("The stack is already Sorted\n");
		return (0);
	}
	else if ((!is_sorted(stack_a)) && (argc == 3))
		sa(&stack_a);
	else if (argc == 4)
		sort_three(&stack_a);
	return (0);
}
	// else if (argc == 6)
	// 	sort_five(&stack_a, &stack_b);
