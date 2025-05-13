/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:28:18 by olcherno          #+#    #+#             */
/*   Updated: 2025/05/13 16:27:55 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// loop until the end of the a is reached
t_stack_node	*find_last_node(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

bool	is_stack_sorted(t_stack_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (false);
		a = a->next;
	}
	return (true);
}

int	stack_length(t_stack_node *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

t_stack_node	*find_min_nbr(t_stack_node *stack)
{
	t_stack_node	*min_nbr_node;
	long			min_nbr;

	if (!stack)
		return (NULL);
	min_nbr = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min_nbr)
		{
			min_nbr = stack->nbr;
			min_nbr_node = stack;
		}
		stack = stack->next;
	}
	return (min_nbr_node);
}

t_stack_node	*find_max_nbr(t_stack_node *stack)
{
	long			max_nbr;
	t_stack_node	*max_node_nbr;

	if (!stack)
		return (NULL);
	max_nbr = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max_nbr)
		{
			max_nbr = stack->nbr;
			max_node_nbr = stack;
		}
		stack = stack->next;
	}
	return (max_node_nbr);
}
