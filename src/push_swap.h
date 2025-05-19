/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:26:08 by olcherno          #+#    #+#             */
/*   Updated: 2025/05/19 18:21:33 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/libftprintf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					steps_to_push;
	bool				above_mid;
	bool				min_commands;

	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

void					fill_stack_a(t_stack_node **a, char **argv);
long					ft_atoli(const char *str);
int						error_check(char *str);
void					free_pars_errors(t_stack_node **stack);
void					free_stack_errors(t_stack_node **stack);
int						duplicate_errors(t_stack_node *a, int n);

void					append_node(t_stack_node **a, int n);
t_stack_node			*find_last_node(t_stack_node *stack);
t_stack_node			*find_min_nbr(t_stack_node *stack);
t_stack_node			*find_max_nbr(t_stack_node *stack);
int						stack_length(t_stack_node *a);
bool					is_stack_sorted(t_stack_node *a);
t_stack_node			*find_last_node(t_stack_node *a);

void					sort_three(t_stack_node **a);

void					sorting(t_stack_node **a, t_stack_node **b);
void					set_param_a_to_b(t_stack_node *a, t_stack_node *b);
void					set_index(t_stack_node *stack);
void					find_target_a(t_stack_node *a, t_stack_node *b);
void					set_steps_a(t_stack_node *a, t_stack_node *b);
void					find_cheapest(t_stack_node *stack);

void					push(t_stack_node **dest, t_stack_node **src);
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);

void					rotate(t_stack_node **stack);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);

void					r_rotate(t_stack_node **stack);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);

void					swap(t_stack_node **start);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);

t_stack_node			*search_cheapest(t_stack_node *a);
void					rot_a_b(t_stack_node **a, t_stack_node **b,
							t_stack_node *pointer_cheapest);
void					rev_rot_a_b(t_stack_node **a, t_stack_node **b,
							t_stack_node *pointer_cheapest);
void					prep_for_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
void					push_b_to_a(t_stack_node **a, t_stack_node **b);
void					push_a_to_b(t_stack_node **a, t_stack_node **b);
void					set_param_b_to_a(t_stack_node *a, t_stack_node *b);
void					find_target_b(t_stack_node *a, t_stack_node *b);
void					is_top_min(t_stack_node **a);

void					free_argvnew(char **argvnew);
char					**create_stack_a(t_stack_node **a, int argc,
							char **argv);

char					**fft_split(char *s, char c);
int						count_words(char *s, char c);
char					*get_next_word(char *s, char c);

#endif
