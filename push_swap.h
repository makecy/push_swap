/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:22:14 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/04 23:56:11 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libraries/Libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"
# include "libraries/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// operations

void					rra(t_stack_node **stack_a);
void					rrb(t_stack_node **stack_b);
void					ra(t_stack_node **stack_a);
void					rb(t_stack_node **stack_b);
void					pa(t_stack_node **stack_b, t_stack_node **stack_a);
void					pb(t_stack_node **stack_a, t_stack_node **stack_b);
void					sa(t_stack_node **stack_a);
void					sb(t_stack_node **stack_b);

// parsing

t_stack_node			*create_stack(int argc, char **argv,
							t_stack_node *stack_a);
int						check_args(int argc, char **argv);

// sorting
void					sort_three(t_stack_node **stack_a);
void					sort_middle(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					ksort1(t_stack_node **stack_a, t_stack_node **stack_b,
							int length);
void					ksort2(t_stack_node **stack_a, t_stack_node **stack_b,
							int length);

void					sorts(t_stack_node **stack_a, t_stack_node **stack_b);
void					sort_stack(t_stack_node **stack_a);
// allutils
int						stack_size(t_stack_node *stack);
void					error(void);
void					free_stack(t_stack_node *stack, bool error_and_exit);
void					print_stack(t_stack_node *stack);
void					rotate_to_position(t_stack_node **stack, int position);
void					push_min_to_b(t_stack_node **stack_a,
							t_stack_node **stack_b);
int						find_position(t_stack_node *stack, int value);
int						find_insert_position(t_stack_node *stack, int value);
int						ft_sqrt(int number);
int						find_max_value(t_stack_node *stack);
// int						is_dup(t_stack_node *stack, int value);
int						is_dup(t_stack_node *stack);
long long				ft_atoll(const char *str);
// bool					check_int_range(char *num_str, t_stack_node *stack);
bool					check_int_range(char *num_str);
void					put_index(t_stack_node **stack);

int						is_sorted(t_stack_node *stack);

#endif // PUSH_SWAP_H
