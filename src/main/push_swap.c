/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:16:14 by olcherno          #+#    #+#             */
/*   Updated: 2025/05/19 17:55:24 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char **argv_;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = fft_split(argv[1], ' ');
	fill_stack_a(&a, argv + 1);
	if (!is_stack_sorted(a))
	{
		if (stack_length(a) == 2)
			sa(&a, false);
		else if (stack_length(a) == 3)
			sort_three(&a);
		else
			sorting(&a, &b);
	}
	free_stack_errors(&a);

	return (0);
}

// int a = 777;
// ft_printf("%d\n", a);
//

