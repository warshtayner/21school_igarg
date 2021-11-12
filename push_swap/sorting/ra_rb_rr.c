/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:17:57 by igarg             #+#    #+#             */
/*   Updated: 2021/11/05 18:26:10 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../utilus/libft.h"
#include "../push_swap.h"

void	ra(t_stack_list **stack)
{
	t_stack_list	*tmp;

	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = ft_lstlast(*stack);
	ft_lstlast(*stack)->next = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack_list **stack)
{
	t_stack_list	*tmp;

	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = ft_lstlast(*stack);
	ft_lstlast(*stack)->next = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stack_list **stack, t_stack_list **stack2)
{
	t_stack_list	*tmp;

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
	write(1, "rr\n", 3);
}
