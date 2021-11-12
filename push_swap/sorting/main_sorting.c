/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:37:35 by igarg             #+#    #+#             */
/*   Updated: 2021/11/10 13:55:11 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../utilus/libft.h"
#include "../push_swap.h"

void	ft_sorting_2(t_stack_list **stack1)
{
	if ((*stack1)->num > (*stack1)->next->num)
		sa(stack1);
}

void	ft_sorting_3(t_stack_list **stack1)
{
	int	a;
	int	b;
	int	c;

	a = (*stack1)->num;
	b = (*stack1)->next->num;
	c = (*stack1)->next->next->num;
	if (a > b && b > c)
	{
		sa(stack1);
		rra(stack1);
	}
	else if (a < b && b > c && c > a)
	{
		sa(stack1);
		ra(stack1);
	}
	else if (a < b && b > c && c < a)
		rra(stack1);
	else if (a > b && b < c && c > a)
		sa(stack1);
	else if (a > b && b < c && c < a)
		ra(stack1);
}

void	min_in_b(t_stack_list **a, t_stack_list **b)
{
	while (check_len_list(a) > 3)
	{
		if (check_position_list(a, check_min_list(a)) == 0)
			pb(a, b);
		else if (check_position_list(a, check_min_list(a)) < (check_len_list
				(a) / 2 + 1))
			ra(a);
		else
			rra(a);
	}
}

void	ft_sorting_5(t_stack_list **stack1, t_stack_list **stack2)
{
	min_in_b(stack1, stack2);
	ft_sorting_3(stack1);
	while (check_len_list(stack2) > 0)
		pa(stack2, stack1);
}

void	main_sorting(t_stack_list **stack1, int count, int *arr_int)
{
	t_stack_list	*stack2;

	stack2 = NULL;
	set_index(*stack1, arr_int, count);
	if (count == 2)
		ft_sorting_2(stack1);
	else if (count == 3)
		ft_sorting_3(stack1);
	else if (count > 3 && count < 6)
		ft_sorting_5(stack1, &stack2);
	else if (count > 5)
		progress_sorting(stack1, &stack2, count);
	else
		return ;
}
