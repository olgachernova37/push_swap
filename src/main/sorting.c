/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:28:46 by olcherno          #+#    #+#             */
/*   Updated: 2025/05/13 16:35:45 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorting(t_stack_node **a, t_stack_node **b)
{
    int size_a;

    size_a = stack_length(*a);
    if (size_a-- > 3 && !is_stack_sorted(*a))
        pb(b, a, false)
    
}