/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:25:14 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/11 18:25:56 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute(t_stack_node **stack_a, t_stack_node **stack_b, char *line);

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			*line;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!check_args(argc, argv))
		return (0);
	stack_a = create_stack(argc, argv, stack_a);
	line = get_next_line(0);
	while (line)
	{
		execute(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (stack_a && is_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(stack_a, stack_b);
	return (0);
}

static void	execute(t_stack_node **stack_a, t_stack_node **stack_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(stack_a, false);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(stack_b, false);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(stack_a, stack_b, false);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(stack_b, stack_a, false);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(stack_a, stack_b, false);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(stack_a, false);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(stack_b, false);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(stack_a, stack_b, false);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(stack_a, false);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(stack_b, false);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(stack_a, stack_b, false);
	else
		error();
}

void	free_stacks(t_stack_node *stack_a, t_stack_node *stack_b)
{
	free_stack(stack_a, false);
	free_stack(stack_b, false);
}
