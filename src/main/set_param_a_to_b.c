/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:27:53 by olcherno          #+#    #+#             */
/*   Updated: 2025/05/19 18:22:24 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_stack_node *a)
{
	int	i;
	int	mid;

	i = 0;
	if (!a)
		return ;
	mid = stack_length(a) / 2;
	while (a)
	{
		a->index = i;
		if (i <= mid)
			a->above_mid = true;
		else
			a->above_mid = false;
		a = a->next;
		i++;
	}
}

// Find `a` node's target in stack `b`
void	find_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_b;
	t_stack_node	*target;
	long			closest_s_nbr;

	while (a)
	{
		closest_s_nbr = LONG_MIN;
		cur_b = b;
		while (cur_b)
		{
			if (cur_b->nbr < a->nbr && cur_b->nbr > closest_s_nbr)
			{
				closest_s_nbr = cur_b->nbr;
				target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (closest_s_nbr == LONG_MIN)
			a->target_node = find_max_nbr(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

// both the nodes to rotate to the top of their stacks
void	set_steps_a(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_length(a);
	size_b = stack_length(b);
	while (a)
	{
		a->steps_to_push = a->index;
		if (!(a->above_mid))
			a->steps_to_push = size_a - (a->index);
		if (a->target_node->above_mid)
			a->steps_to_push += a->target_node->index;
		else
			a->steps_to_push += size_b - (a->target_node->index);
		a = a->next;
	}
}

void	find_cheapest(t_stack_node *stack)
{
	long			value_cheapest;
	t_stack_node	*pointer_cheapest;

	if (!stack)
		return ;
	value_cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->steps_to_push < value_cheapest)
		{
			value_cheapest = stack->steps_to_push;
			pointer_cheapest = stack;
		}
		stack = stack->next;
	}
	pointer_cheapest->min_commands = true;
}

void	set_param_a_to_b(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	find_target_a(a, b);
	set_steps_a(a, b);
	find_cheapest(a);
}
