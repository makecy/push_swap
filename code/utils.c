/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:48:14 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/05 18:49:47 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stack(t_stack_node *stack)
// {
// 	while (stack)
// 	{
// 		printf("NODE\n");
// 		printf("current address = %p \n", stack);
// 		printf("%d \n", stack->value);
// 		printf("next - %p \n", stack->next);
// 		printf("prev - %p \n", stack->prev);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

int	stack_size(t_stack_node *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_stack(t_stack_node *stack, bool error_and_exit)
{
	t_stack_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	if (error_and_exit)
		error();
}
