/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:27:22 by olcherno          #+#    #+#             */
/*   Updated: 2025/05/14 15:55:10 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// str to long int
long	ft_atoli(const char *str) 
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		nbr = nbr * 10 + (*str++ - '0');
	return (nbr * sign);
}

t_stack_node	*search_cheapest(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->min_commands)
			return (a);
		a = a->next;
	}
	return (NULL);
}


void	append_node(t_stack_node **a, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*l_node;

	if (!a)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->nbr = n;
	new_node->min_commands = 0;
	if (!(*a))
	{
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		l_node = find_last_node(*a);
		l_node->next = new_node;
		new_node->prev = l_node;
	}
}

void	fill_stack_a(t_stack_node **a, char **argv)
{
	long	nbr;
	int		index;

	index = 0;
	while (argv[index])
	{
		if (error_check(argv[index]))
		{
			free_pars_errors(a);
		}
		nbr = ft_atoli(argv[index]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_pars_errors(a);
		if (duplicate_errors(*a, (int)nbr))
			free_pars_errors(a);
		append_node(a, (int)nbr);
		index++;
	}
}

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_mid)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_mid)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}
