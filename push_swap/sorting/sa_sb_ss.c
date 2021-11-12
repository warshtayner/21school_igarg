/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:25:50 by igarg             #+#    #+#             */
/*   Updated: 2021/11/02 09:13:56 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../utilus/libft.h"
#include "../push_swap.h"

void	sa(t_stack_list	**stack)
{
	t_stack_list	*tmp;

	tmp = (*stack)->next->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next->next = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = 0;
	(*stack)->next->next = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack_list	**stack)
{
	t_stack_list	*tmp;

	tmp = (*stack)->next->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next->next = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = 0;
	(*stack)->next->next = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack_list	**stack1, t_stack_list **stack2)
{
	t_stack_list	*tmp;

	tmp = (*stack1)->next->next;
	(*stack1)->prev = (*stack1)->next;
	(*stack1)->next->next = (*stack1);
	*stack1 = (*stack1)->next;
	(*stack1)->prev = 0;
	(*stack1)->next->next = tmp;
	tmp = (*stack2)->next->next;
	(*stack2)->prev = (*stack2)->next;
	(*stack2)->next->next = (*stack2);
	*stack2 = (*stack2)->next;
	(*stack2)->prev = 0;
	(*stack2)->next->next = tmp;
	write(1, "ss\n", 3);
}
