/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:28:46 by olcherno          #+#    #+#             */
/*   Updated: 2025/05/14 15:54:40 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rot_a_b(t_stack_node **a, t_stack_node **b,
		t_stack_node *pointer_cheapest)
{
	while (*b != pointer_cheapest->target_node && *a != pointer_cheapest)
		rr(a, b, false);
	set_index(*a);
	set_index(*b);
}

void	rev_rot_a_b(t_stack_node **a, t_stack_node **b,
		t_stack_node *pointer_cheapest)
{
	while (*b != pointer_cheapest->target_node && *a != pointer_cheapest)
		rrr(a, b, false);
	set_index(*a);
	set_index(*b);
}

// until there are three nodes left in `a`
void	push_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*pointer_cheapest;

	pointer_cheapest = search_cheapest(*a);
	if (pointer_cheapest->above_mid && pointer_cheapest->target_node->above_mid)
		rot_a_b(a, b, pointer_cheapest);
	else if (!(pointer_cheapest->above_mid)
		&& !(pointer_cheapest->target_node->above_mid))
		rev_rot_a_b(a, b, pointer_cheapest);
	prep_for_push(a, pointer_cheapest, 'a');
	prep_for_push(b, pointer_cheapest->target_node, 'b');
	pb(b, a, false);
}

void	push_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	is_top_min(t_stack_node **a)
{
	while ((*a)->nbr != find_min_nbr(*a)->nbr)
	{
		if (find_min_nbr(*a)->above_mid)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sorting(t_stack_node **a, t_stack_node **b)
{
	int	size_a;

	size_a = stack_length(*a);
	if (size_a-- > 3 && !is_stack_sorted(*a))
		pb(b, a, false);
	if (size_a-- > 3 && !is_stack_sorted(*a))
		pb(b, a, false);
	while (size_a-- > 3 && !is_stack_sorted(*a))
	{
		set_param_a_to_b(*a, *b);
		push_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_param_b_to_a(*a, *b);
		push_b_to_a(a, b);
	}
	set_index(*a);
	is_top_min(a);
}
