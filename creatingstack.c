/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creatingstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:47:45 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/02 19:01:20 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	check_args(int argc, char **argv)
// {
// 	int			i;
// 	int			j;
// 	int			count;

// 	i = 1;
// 	count = 0;
// 	while (i < argc)
// 	{
// 		j = 0;
// 		if (argv[i][0] == '\0')
// 			error();
// 		while (argv[i][j])
// 		{
// 			if (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
// 				error();
// 			if ((!ft_isdigit(argv[i][j]) && (argv[i][j] != ' '
// 						&& argv[i][j] != '-')))
// 				error();
// 			if ((ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' ' || argv[i][j
// 						+ 1] == '\0')))
// 				count += 1;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }

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

static int	num_count(char *str)
{
	int	i;
	int	nc;

	i = 0;
	nc = 0;
	while (str[i])
	{
		if (str[i] != '-' && !ft_isdigit(str[i]))
			error();
		if (str[i] == '-' && str[i + 1] != '-')
			i++;
		if (ft_isdigit(str[i]))
			nc++;
		while (ft_isdigit(str[i]) == 1)
			i++;
		if (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	return (nc);
}

static t_stack_node	*handel_string_inputs(char *arg, t_stack_node *a)
{
	char	**nums;
	int		i;

	nums = ft_split(arg, ' ');
	i = 0;
	if (nums == NULL)
		error();
	while (nums[i])
	{
		check_int_range(nums[i], a);
		a = push_stack(a, ft_atoi(nums[i]));
		free(nums[i]);
		i++;
	}
	free(nums);
	return (a);
}

t_stack_node	*create_stack(int argc, char **argv, t_stack_node *stack_a)
{
	int	i;
	int	nc;

	i = 1;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		nc = num_count(argv[i]);
		if (nc == 0)
			error();
		else if (nc == 1)
			stack_a = push_stack(stack_a, ft_atoi(argv[i]));
		else
			stack_a = handel_string_inputs(argv[i], stack_a);
		i++;
	}
	return (stack_a);
}
