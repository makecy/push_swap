/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creatingstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:47:45 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/12 17:29:25 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc, char **argv)
{
	int	i[3];

	i[0] = 1;
	i[2] = 0;
	while (i[0] < argc)
	{
		i[1] = 0;
		if (argv[i[0]][0] == '\0')
			error();
		while (argv[i[0]][i[1]])
		{
			if (argv[i[0]][i[1]] == '-' && !ft_isdigit(argv[i[0]][(i[1]) + 1]))
				error();
			if ((!ft_isdigit(argv[i[0]][i[1]]) && (argv[i[0]][i[1]] != ' '
				&& argv[i[0]][i[1]] != '-')))
				error();
			if ((ft_isdigit(argv[i[0]][i[1]]) && (argv[i[0]][(i[1]) + 1] == ' '
				|| argv[i[0]][(i[1]) + 1] == '\0')))
				i[2] += 1;
			i[1]++;
		}
		i[0]++;
	}
	return (i[2]);
}

t_stack_node	*push_stack(t_stack_node *stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*temp;

	new_node = ft_calloc(1, sizeof(t_stack_node));
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

int	num_count(char *str)
{
	int	nc;
	int	i;

	nc = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && !ft_isdigit(str[i]))
			i++;
		if (str[i])
			nc++;
		while (ft_isdigit(str[i]))
			i++;
		while (str[i] == ' ' && str[i + 1] == ' ')
			i++;
	}
	return (nc);
}

static t_stack_node	*handel_string_inputs(char *arg, t_stack_node *stack_a)
{
	char	**nums;
	int		i;
	bool	num_too_big;

	num_too_big = false;
	nums = ft_split(arg, ' ');
	i = 0;
	if (nums == NULL)
		error();
	while (nums[i])
	{
		if (check_int_range(nums[i]))
			num_too_big = true;
		stack_a = push_stack(stack_a, ft_atoi(nums[i]));
		free(nums[i]);
		i++;
	}
	free(nums);
	if (is_dup(stack_a) || num_too_big)
		free_stack(stack_a, true);
	return (stack_a);
}

t_stack_node	*create_stack(int argc, char **argv, t_stack_node *stack_a)
{
	int		i;
	int		nc;
	bool	num_too_big;

	i = 1;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		nc = num_count(argv[i]);
		if (nc == 0)
			error();
		else if (nc == 1)
		{
			if (check_int_range(argv[i]))
				num_too_big = true;
			stack_a = push_stack(stack_a, ft_atoi(argv[i]));
		}
		else
			stack_a = handel_string_inputs(argv[i], stack_a);
		i++;
	}
	if (is_dup(stack_a) || num_too_big)
		free_stack(stack_a, true);
	return (stack_a);
}
