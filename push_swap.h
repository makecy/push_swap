/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:22:14 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/10 19:21:52 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libraries/Libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"
# include "libraries/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

int						main(int argc, char **argv);
// operations
void					rra(t_stack_node **a);
void					rrb(t_stack_node **stack_b);
void					rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void					ra(t_stack_node **stack_a);
void					rb(t_stack_node **stack_b);
void					rr(t_stack_node **stack_a, t_stack_node **stack_b);
void					pa(t_stack_node **stack_a, t_stack_node **stack_b);
void					pb(t_stack_node **stack_a, t_stack_node **stack_b);
void					sa(t_stack_node **stack_a);
void					sb(t_stack_node **stack_b);
void					ss(t_stack_node **stack_a, t_stack_node **stack_b);

// error message
void					error(void);

// parsing
t_stack_node			*create_stack(int argc, char **argv,
							t_stack_node *stack_a);
t_stack_node			*push_stack(t_stack_node *stack, int value);
void					free_stack(t_stack_node *stack);

// sorting
int						is_sorted(t_stack_node *stack);
void					sort_three(t_stack_node **stack_a);
void					sort_five(t_stack_node **stack_a,
							t_stack_node **stack_b);
// utils
void					ft_print_stack(t_stack_node *stack);
int						stack_size(t_stack_node *stack);

#endif // PUSH_SWAP_H
