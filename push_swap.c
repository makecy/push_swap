/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:22:11 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/14 20:06:52 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_args(argc, argv))
		return (0);
	stack_a = create_stack(argc, argv, stack_a);
	// stack_b = create_stack(argc, argv, stack_b);
	sorts(stack_a, stack_b, argc);
}
