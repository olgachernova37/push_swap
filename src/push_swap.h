/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:26:08 by olcherno          #+#    #+#             */
/*   Updated: 2025/05/13 17:25:10 by olcherno         ###   ########.fr       */
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
	int					push_cost;
	bool				above_mid;
	bool				min_commands;

	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

void					fill_stack_a(t_stack_node **a, char **argv);
static long				ft_atoli(const char *str);
int						error_check(char *str);
void					free_pars_errors(t_stack_node **stack);
void					free_stack_errors(t_stack_node **stack);
int						duplicate_errors(t_stack_node *a, int n);

static void				append_node(t_stack_node **a, int n);
t_stack_node			*find_last_node(t_stack_node *stack);
t_stack_node			*find_min_nbr(t_stack_node *stack);
t_stack_node			*find_max_nbr(t_stack_node *stack);
int						stack_length(t_stack_node *a);
bool					is_stack_sorted(t_stack_node *a);
t_stack_node			*find_last_node(t_stack_node *a);

void					sort_three(t_stack_node **a);

void	sorting(t_stack_node **a, t_stack_node **b);


static void	push(t_stack_node **dest, t_stack_node **src);
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);

static void	rotate(t_stack_node **stack);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);



#endif
