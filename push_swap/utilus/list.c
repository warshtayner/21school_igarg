/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:37:04 by igarg             #+#    #+#             */
/*   Updated: 2021/11/01 09:53:45 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	ft_lst_leaks(t_stack_list *lst)
{
	t_stack_list	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

t_stack_list	*ft_lstlast(t_stack_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack_list	*ft_lstfirst(t_stack_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

t_stack_list	*ft_lstnew(int num)
{
	t_stack_list	*new;

	new = malloc(sizeof(t_stack_list));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = 0;
	new->flag = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back(t_stack_list **lst, t_stack_list *new)
{
	if (!new || !lst)
		return ;
	if (*lst)
	{
		ft_lstlast(*lst)->next = new;
		new->prev = *lst;
	}
	else
		*lst = new;
}
