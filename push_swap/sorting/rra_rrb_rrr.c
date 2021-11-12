/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:59:20 by igarg             #+#    #+#             */
/*   Updated: 2021/11/06 09:32:51 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../utilus/libft.h"
#include "../push_swap.h"

void	rra(t_stack_list **stack)
{
	t_stack_list	*tmp;
	t_stack_list	*lst;

	lst = *stack;
	tmp = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack)->next = 0;
	*stack = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack_list **stack)
{
	t_stack_list	*tmp;
	t_stack_list	*lst;

	lst = *stack;
	tmp = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack)->next = 0;
	*stack = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_list **stack, t_stack_list **stack2)
{
	t_stack_list	*tmp;
	t_stack_list	*lst;

	lst = *stack;
	tmp = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack)->next = 0;
	*stack = tmp;
	lst = *stack2;
	tmp = ft_lstlast(*stack2);
	while ((*stack2)->next->next)
		*stack = (*stack2)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack2)->next = 0;
	*stack2 = tmp;
	write(1, "rrr\n", 4);
}
