/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:10:08 by igarg             #+#    #+#             */
/*   Updated: 2021/11/09 16:53:35 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

t_stack_list	*check_max_list(t_stack_list **stack)
{
	t_stack_list	*max_list;
	t_stack_list	*tmp_list;

	max_list = *stack;
	tmp_list = *stack;
	while (tmp_list)
	{
		if (max_list->num < tmp_list->num)
			max_list = tmp_list;
		tmp_list = tmp_list->next;
	}
	return (max_list);
}

void	ft_set_stack_param(t_list_param *new, t_stack_list **stack)
{
	if (!(*stack))
		return ;
	new->min = check_min_list(stack)->index;
	new->max = check_max_list(stack)->index;
	new->mid = new->max / 2 + new->min;
}

void	ft_set_param_flag(t_list_param *param)
{
	param->max = param->mid;
	param->mid = (param->max - param->min) / 2 + param->min;
	param->flag++;
}

t_list_param	*ft_lstnew_param(void)
{
	t_list_param	*new;

	new = malloc(sizeof(t_list_param));
	if (!new)
		return (NULL);
	new->min = 0;
	new->max = 0;
	new->mid = 0;
	new->flag = 0;
	return (new);
}

t_stack_list	*check_last(t_stack_list **stack)
{
	t_stack_list	*tmp;

	tmp = *stack;
	if (!tmp)
		return (tmp);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
