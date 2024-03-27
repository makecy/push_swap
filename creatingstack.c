/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creatingstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:47:45 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/27 22:33:32 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
				error();
			if ((!ft_isdigit(argv[i][j]) && (argv[i][j] != ' '
				&& argv[i][j] != '-')))
				error();
			if ((ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' ' || argv[i][j
				+ 1] == '\0')))
				count += 1;
			j++;
		}
		i++;
	}
	return (count);
}

t_stack_node	*push_stack(t_stack_node *stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*temp;

	if (is_dup(stack, value))
		error();
	new_node = (t_stack_node *)ft_calloc(sizeof(t_stack_node), 1);
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
	new_node->prev = temp;
	return (stack);
}

t_stack_node	*create_stack(int argc, char **argv, t_stack_node *stack_a)
{
	int		i;
	char	**split;

	i = 0;
	if (argc < 2)
		error();
	if (argc == 2)
	{
		split = ft_split(argv[1], 32);
		while (split[i])
			stack_a = push_stack(stack_a, ft_atoi(split[i++]));
		free_split(split);
	}
	else
	{
		i = 1;
		while (i < argc)
			stack_a = push_stack(stack_a, ft_atoi(argv[i++]));
	}
	return (stack_a);
}

int	is_dup(t_stack_node *stack, int value)
{
	t_stack_node	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->value == value)
			return (1);
		temp = temp->next;
	}
	return (0);
}
