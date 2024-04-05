/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:46:08 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/05 18:50:41 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ksort1(t_stack_node **stack_a, t_stack_node **stack_b, int length)
{
	int	i;
	int	j;

	put_index(stack_a);
	i = 0;
	j = ft_sqrt(length) * 14 / 10;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + j)
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

void	ksort2(t_stack_node **stack_a, t_stack_node **stack_b, int length)
{
	int	max_value;
	int	max_position;
	int	stack_b_size;
	int	i;

	while (length-- > 0)
	{
		max_value = find_max_value(*stack_b);
		if (max_value == INT_MIN)
			break ;
		max_position = find_position(*stack_b, max_value);
		stack_b_size = stack_size(*stack_b);
		i = 0;
		if (max_position < stack_b_size / 2)
			while (i++ < max_position)
				rb(stack_b);
		else
			while (i++ < stack_b_size - max_position)
				rrb(stack_b);
		pa(stack_b, stack_a);
	}
}

int	find_next_min(t_stack_node *stack, int curr_min)
{
	int	next_min;
	int	found;

	next_min = INT_MAX;
	found = 0;
	while (stack)
	{
		if (stack->value > curr_min && stack->value < next_min)
		{
			next_min = stack->value;
			found = 1;
		}
		stack = stack->next;
	}
	if (found)
		return (next_min);
	else
		return (INT_MAX);
}

void	put_index(t_stack_node **stack)
{
	int				i;
	int				curr_min;
	t_stack_node	*tmp;

	i = 0;
	curr_min = INT_MIN;
	while (i < stack_size(*stack))
	{
		curr_min = find_next_min(*stack, curr_min);
		tmp = *stack;
		while (tmp)
		{
			if (tmp->value == curr_min)
			{
				tmp->index = i;
				i++;
				break ;
			}
			tmp = tmp->next;
		}
	}
}
