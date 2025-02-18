/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:22:11 by mstefano          #+#    #+#             */
/*   Updated: 2025/02/18 16:11:40 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_args(argc, argv))
		return (0);
	stack_a = create_stack(argc, argv, stack_a);
	if (!stack_a)
		error();
	sorts(&stack_a, &stack_b);
	free_stack(stack_a, false);
	free_stack(stack_b, false);
}
