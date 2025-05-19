/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:27:53 by olcherno          #+#    #+#             */
/*   Updated: 2025/05/19 18:22:54 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			closest_bigger;

	while (b)
	{
		closest_bigger = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < closest_bigger)
			{
				closest_bigger = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_bigger == LONG_MAX)
			b->target_node = find_min_nbr(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_param_b_to_a(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	find_target_b(a, b);
}
