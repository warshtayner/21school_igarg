/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:12:31 by igarg             #+#    #+#             */
/*   Updated: 2021/11/10 12:59:58 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../utilus/libft.h"
#include "../push_swap.h"

void	in_a(t_stack_list **a, t_stack_list **b, t_list_param *param_t)
{
	int	i;
	int	len;

	i = -1;
	len = check_len_list(b);
	while (++i < len)
	{
		if ((*b)->index == param_t->min)
			check_min(a, b, param_t);
		else if ((*b)->index >= param_t->mid)
		{
			(*b)->flag = param_t->flag;
			pa(b, a);
		}
		else
			rb(b);
		if (!(*b))
			break ;
	}
	ft_set_param_flag(param_t);
}

void	in_b(t_stack_list **a, t_stack_list **b, t_list_param *param_t)
{
	int	flag_max;

	flag_max = (*a)->flag;
	if ((*a)->flag != 0)
	{
		while ((*a)->flag == flag_max)
			in_b_dop(a, b, param_t);
		if (*b)
			param_t->max = check_max_list(b)->index;
		param_t->mid = (param_t->max - param_t->min) / 2 + param_t->min;
	}
	else if ((*a)->flag == 0)
	{
		while ((*a)->flag != -1)
			in_b_dop(a, b, param_t);
		if (*b)
			param_t->max = check_max_list(b)->index;
		param_t->mid = (param_t->max - param_t->min) / 2 + param_t->min;
	}
}

void	progress_sorting(t_stack_list **a, t_stack_list **b, int count)
{
	t_list_param	*param_t;

	param_t = ft_lstnew_param();
	ft_set_stack_param(param_t, a);
	while (check_sort_list(a, count) != 1)
	{
		if (!*b && param_t->flag == 0)
			in_b_first(a, b, param_t);
		else if (!*b)
			in_b(a, b, param_t);
		else
			in_a(a, b, param_t);
	}
	free(param_t);
}
