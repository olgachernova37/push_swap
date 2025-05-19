/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:16:14 by olcherno          #+#    #+#             */
/*   Updated: 2025/05/19 18:23:53 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	free_argvnew(char **argvnew)
{
	int	i;

	if (!argvnew)
		return ;
	i = 0;
	while (argvnew[i])
	{
		free(argvnew[i]);
		i++;
	}
	free(argvnew);
}

char	**create_stack_a(t_stack_node **a, int argc, char **argv)
{
	char	**argvnew;

	argvnew = NULL;
	if (argc == 2)
	{
		argvnew = fft_split(argv[1], ' ');
		fill_stack_a(a, argvnew + 1);
	}
	else
		fill_stack_a(a, argv + 1);
	return (argvnew);
}

// int	main(int argc, char **argv)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;
// 	char **argvnew =NULL;

// 	a = NULL;
// 	b = NULL;
// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (1);
// 	else if (argc == 2)
// 	{
// 		argvnew = fft_split(argv[1], ' ');
// 		fill_stack_a(&a, argvnew + 1);
// 	}
// 	else
// 		fill_stack_a(&a, argv + 1);
// 	if (!is_stack_sorted(a))
// 	{
// 		if (stack_length(a) == 2)
// 			sa(&a, false);
// 		else if (stack_length(a) == 3)
// 			sort_three(&a);
// 		else
// 			sorting(&a, &b);
// 	}
// 	free_argvnew(argvnew);
// 	free_stack_errors(&a);
// 	return (0);
// }

// int a = 777;
// ft_printf("%d\n", a);
//

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**argvnew;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	argvnew = create_stack_a(&a, argc, argv);
	if (!is_stack_sorted(a))
	{
		if (stack_length(a) == 2)
			sa(&a, false);
		else if (stack_length(a) == 3)
			sort_three(&a);
		else
			sorting(&a, &b);
	}
	free_argvnew(argvnew);
	free_stack_errors(&a);
	return (0);
}
