/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:41:43 by igarg             #+#    #+#             */
/*   Updated: 2021/11/05 13:50:57 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../utilus/libft.h"
#include "../push_swap.h"

void	pb(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*tmp_a;
	t_stack_list	*tmp_b;

	if (!*b)
	{
		tmp_a = (*a)->next;
		*b = *a;
		*a = tmp_a;
		(*a)->prev = 0;
		(*b)->next = 0;
	}
	else
	{
		tmp_b = (*b);
		tmp_a = (*a)->next;
		*b = *a;
		(*b)->next = tmp_b;
		tmp_b->prev = (*b);
		*a = tmp_a;
		(*a)->prev = 0;
	}
	write(1, "pb\n", 3);
}

void	pa(t_stack_list **b, t_stack_list **a)
{
	t_stack_list	*tmp_b;
	t_stack_list	*tmp_a;

	if (!(*b)->next)
	{
		tmp_a = (*a);
		tmp_b = (*b)->next;
		*a = *b;
		(*a)->next = tmp_a;
		tmp_a->prev = (*a);
		*b = tmp_b;
	}
	else
	{
		tmp_a = (*a);
		tmp_b = (*b)->next;
		*a = *b;
		(*a)->next = tmp_a;
		tmp_a->prev = (*a);
		*b = tmp_b;
		(*b)->prev = 0;
	}
	write(1, "pa\n", 3);
}
