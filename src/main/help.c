/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:07:02 by olcherno          #+#    #+#             */
/*   Updated: 2025/04/29 17:05:09 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	lstadd_front(t_stack_node **lst, t_stack_node *new)
// {
// 	if (lst && new)
// 	{
// 		new->next = *lst;
// 		*lst = new;
// 	}
// }

// int	lst_size(t_stack_node *lst)
// {
// 	int	counter;

// 	counter = 0;
// 	while (lst != NULL)
// 	{
// 		counter++;
// 		lst = lst->next;
// 	}
// 	return (counter);
// }

// t_stack_node	*lst_last(t_stack_node *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	return (lst);
// }

// void	lstadd_back(t_stack_node **lst, t_stack_node *new)
// {
// 	t_stack_node	*last;

// 	if (lst == NULL)
// 		return ;
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	last = lst_last(*lst);
// 	if (last->next == NULL)
// 	{
// 		last->next = new;
// 		new->next = NULL;
// 	}
// }

// void	lstdelone(t_stack_node *lst, void (*del)(void *))
// {
// 	if (!lst || !del)
// 		return ;
// 	del(lst->nbr);
// 	free(lst);
// }

// void	lstclear(t_stack_node **lst, void (*del)(void *))
// {
// 	t_stack_node	*current;
// 	t_stack_node	*tmp;

// 	if (!lst || !del)
// 		return ;
// 	current = *lst;
// 	while (current != NULL)
// 	{
// 		tmp = current;
// 		current = current->next;
// 		del(tmp->nbr);
// 		free(tmp);
// 	}
// 	*lst = NULL;
// }

// void	lstiter(t_stack_node *lst, void (*f)(void *))
// {
// 	if (!lst || !f)
// 		return ;

// 	while (lst != NULL)
// 	{
// 		f(lst->nbr);
// 		lst = lst->next;
// 	}
// }

// t_stack_node	*ft_lstmap(t_stack_node *lst, void *(*f)(void *),
// 		void (*del)(void *))
// {
// 	t_stack_node	*new_list;
// 	t_stack_node	*new_node;

// 	if (!lst)
// 		return (NULL);

// 	new_list = NULL;
// 	while (lst)
// 	{
// 		if (f)
// 			new_node = lstnew(f(lst->nbr));
// 		else
// 			new_node = lstnew(lst->nbr);
// 		if (!new_node)
// 		{
// 			lstclear(&new_list, del);
// 			return (NULL);
// 		}
// 		lstadd_back(&new_list, new_node);
// 		lst = lst->next;
// 	}
// 	return (new_list);
// }
