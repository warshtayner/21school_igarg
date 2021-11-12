/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:17:57 by igarg             #+#    #+#             */
/*   Updated: 2021/11/11 09:19:01 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../utilus/libft.h"
#include "../push_swap.h"

void	ra_com(t_stack_list **stack)
{
	t_stack_list	*tmp;

	if (!(*stack))
		return ;
	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = ft_lstlast(*stack);
	ft_lstlast(*stack)->next = tmp;
}

void	rb_com(t_stack_list **stack)
{
	t_stack_list	*tmp;

	if (!(*stack))
		return ;
	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = ft_lstlast(*stack);
	ft_lstlast(*stack)->next = tmp;
}

void	rr_com(t_stack_list **stack, t_stack_list **stack2)
{
	t_stack_list	*tmp;

	if (!(*stack2))
		return ;
	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = ft_lstlast(*stack);
	ft_lstlast(*stack)->next = tmp;
	tmp = *stack2;
	*stack2 = tmp->next;
	(*stack2)->prev = 0;
	tmp->next = 0;
	tmp->prev = ft_lstlast(*stack2);
	ft_lstlast(*stack2)->next = tmp;
}
