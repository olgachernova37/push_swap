/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:26:37 by olcherno          #+#    #+#             */
/*   Updated: 2025/05/14 16:32:05 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// swaps the positions of the top node and second node of a stack
void	swap(t_stack_node **start)
{
	if (!*start || !(*start)->next)
		return ;
	*start = (*start)->next;
	(*start)->prev->prev = *start;
	(*start)->prev->next = (*start)->next;
	if ((*start)->next)
		(*start)->next->prev = (*start)->prev;
	(*start)->next = (*start)->prev;
	(*start)->prev = NULL;
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
