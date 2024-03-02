/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:22:14 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/02 15:04:17 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libraries/Libft/libft.h"
# include "libraries/get_next_line/get_next_line.h"
# include "libraries/ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					*value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int		main(int argc, char **argv);
void	rra(t_stack_node **stack_a);
void	rrb(t_stack_node **stack_b);
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void	ra(t_stack_node **stack_a);
void	rb(t_stack_node **stack_b);
void	rr(t_stack_node **stack_a, t_stack_node **stack_b);
void	pa(t_stack_node **stack_a, t_stack_node **stack_b);
void	pb(t_stack_node **stack_a, t_stack_node **stack_b);
void	sa(t_stack_node **stack_a);
void	sb(t_stack_node **stack_b);
void	ss(t_stack_node **stack_a, t_stack_node **stack_b);
void	error(void);
void	*create_stack(int argc, char **argv, t_stack_node *stack);
int		*is_sorted(t_stack_node *stack);
void	*sort_stack(t_stack_node **stack_a, t_stack_node **stack_b);

#endif // PUSH_SWAP_H
