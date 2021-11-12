/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:35:45 by igarg             #+#    #+#             */
/*   Updated: 2021/11/11 12:27:12 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utilus/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	char			*str;
	char			**str_arr;
	t_stack_list	*stack1;
	int				count_arg;
	int				*array_int;

	if (argc > 1)
	{
		str = ft_join(argv + 1);
		str_arr = ft_split(str, ' ');
		count_arg = ft_count_arg(str, ' ');
		check_equal(str_arr, count_arg);
		stack1 = creat_list(str_arr);
		array_int = full_int(str_arr, count_arg);
		free(str);
		leaks(str_arr);
		main_sorting(&stack1, count_arg, array_int);
		ft_lst_leaks(stack1);
		free(array_int);
	}
	return (0);
}
