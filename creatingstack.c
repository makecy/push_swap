/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creatingstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:47:45 by mstefano          #+#    #+#             */
/*   Updated: 2024/02/29 18:09:28 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(char **stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		free(stack[i]);
		i++;
	}
	free(stack);
}

t_stack_node	*push_stack(t_stack_node *stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*temp;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		error();
	new_node->value = value;
	new_node->next = NULL;
	if (!stack)
		return (new_node);
	temp = stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	return (stack);
}

t_stack_node	*create_stack(int argc, char **argv, t_stack_node *stack_a)
{
	int				i;
	char			**split;

	i = 0;
	if (argc < 2)
		error();
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		while (split[i])
			stack_a = push_stack(stack_a, ft_atoi(split[i++]));
		free_stack(split);
	}
	else
	{
		i = 1;
		while (i < argc)
			stack_a = push_stack(stack_a, ft_atoi(argv[i++]));
	}
	return (stack_a);
}