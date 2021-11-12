/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:07:40 by igarg             #+#    #+#             */
/*   Updated: 2021/11/05 15:25:12 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	check_sort_list(t_stack_list **stack, int count)
{
	t_stack_list	*list;

	list = *stack;
	if (check_len_list(stack) != count)
		return (0);
	while (list->next)
	{
		if (list->index > list->next->index)
			return (0);
		list = list->next;
	}
	return (1);
}

int	check_len_list(t_stack_list **stack)
{
	int				len;
	t_stack_list	*list;

	len = 0;
	list = *stack;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

void	set_index(t_stack_list *stack, int *arr, int count)
{
	int				i;
	t_stack_list	*list;

	list = stack;
	while (list)
	{
		i = 0;
		while (i < count)
		{
			if (arr[i] == list->num)
				list->index = i;
			i++;
		}
		list = list->next;
	}
}

int	check_position_list(t_stack_list **stack, t_stack_list *list)
{
	t_stack_list	*tmp_list;
	int				i;

	i = 0;
	tmp_list = *stack;
	while (tmp_list != list)
	{
		tmp_list = tmp_list->next;
		i++;
	}
	return (i);
}

t_stack_list	*check_min_list(t_stack_list **stack)
{
	t_stack_list	*min_list;
	t_stack_list	*tmp_list;

	min_list = *stack;
	tmp_list = *stack;
	while (tmp_list)
	{
		if (min_list->num > tmp_list->num)
			min_list = tmp_list;
		tmp_list = tmp_list->next;
	}
	return (min_list);
}
