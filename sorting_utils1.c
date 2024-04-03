/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:44:11 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/03 22:57:17 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack_node **stack_a)
{
	int				temp_value;
	t_stack_node	*min_node;
	t_stack_node	*i;
	t_stack_node	*j;

	i = *stack_a;
	while (i != NULL)
	{
		min_node = i;
		j = i->next;
		while (j != NULL)
		{
			if (j->value < min_node->value)
				min_node = j;
			j = j->next;
		}
		temp_value = i->value;
		i->value = min_node->value;
		min_node->value = temp_value;
		i = i->next;
	}
}

int	ft_sqrt(int number)
{
	int	i;

	i = 0;
	if (number < 0)
		return (-1);
	while (i * i < number)
		i++;
	return (i - 1);
}

int	find_max_value(t_stack_node *stack)
{
	int	max_value;

	max_value = INT_MIN;
	while (stack)
	{
		if (stack->value > max_value)
			max_value = stack->value;
		stack = stack->next;
	}
	return (max_value);
}

