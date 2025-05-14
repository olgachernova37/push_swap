/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:27:53 by olcherno          #+#    #+#             */
/*   Updated: 2025/05/14 15:55:53 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a; //To store the pointer to the current `a` node
	t_stack_node	*target_node; //To store the pointer of the target node for `b` node
	long			closest_bigger; //To store the "closest bigger" number so far

	while (b)
	{
		closest_bigger = LONG_MAX; //Set the current best match to the max long
		current_a = a; //Assign the pointer to point to the current `a` node
		while (current_a) //While the pointer is not set to NULL
		{
			if (current_a->nbr > b->nbr 
				&& current_a->nbr < closest_bigger) //Check if the `a` node's value is bigger than `b` node, && smaller than the "closest bigger" so far
			{
				closest_bigger = current_a->nbr; //Set the best match as the value in the current `a` node
				target_node = current_a; //Set `b` node's target node pointer to point to the current `a` node
			}
			current_a = current_a->next; //Move to the next `a` node for processing
		}
		if (closest_bigger == LONG_MAX) //If the best match value has not changed
			b->target_node = find_min_nbr(a); //Set `b` node's target node pointer to point to the smallest number in stack `a`
		else
			b->target_node = target_node; //If the best match value has been updated, then we have a target node for the current `b` node
		b = b->next; //Move to the next `b` node for processing
	}
}

void	set_param_b_to_a(t_stack_node *a, t_stack_node *b) //Define a function that prepares the nodes for pushing `b` to `a`
{
	set_index(a);
	set_index(b);
	find_target_b(a, b);
}