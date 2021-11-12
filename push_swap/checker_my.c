/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:15:03 by igarg             #+#    #+#             */
/*   Updated: 2021/11/10 19:48:15 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utilus/libft.h"
#include "push_swap.h"

int	get_next_line(char **line)
{
	int		i;
	int		j;
	char	*buf;

	i = -1;
	buf = (char *)malloc(5);
	j = read(0, &buf[++i], 1);
	while (j > 0 && buf[i] != '\n' && buf[i] != '\0')
		j = read(0, &buf[++i], 1);
	buf[i] = '\0';
	*line = buf;
	return (j);
}

void	command(t_stack_list **a, t_stack_list **b, char *str)
{
	if (!(ft_strncmp(str, "sa", 3)))
		sa_com(a);
	else if (!(ft_strncmp(str, "sb", 3)))
		sb_com(b);
	else if (!(ft_strncmp(str, "ss", 3)))
		ss_com(a, b);
	else if (!(ft_strncmp(str, "pb", 3)))
		pb_com(a, b);
	else if (!(ft_strncmp(str, "pa", 3)))
		pa_com(b, a);
	else if (!(ft_strncmp(str, "ra", 3)))
		ra_com(a);
	else if (!(ft_strncmp(str, "rb", 3)))
		rb_com(b);
	else if (!(ft_strncmp(str, "rr", 3)))
		rr_com(a, b);
	else if (!(ft_strncmp(str, "rra", 4)))
		rra_com(a);
	else if (!(ft_strncmp(str, "rrb", 4)))
		rrb_com(b);
	else if (!(ft_strncmp(str, "rrr", 4)))
		rrr_com(a, b);
	else
		error();
}

void	main_checker(t_stack_list **a, int count, int *arr_int)
{
	t_stack_list	*b;
	char			*str;

	b = NULL;
	set_index(*a, arr_int, count);
	while (get_next_line(&str))
		command(a, &b, str);
	if (check_sort_list(a, count))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(str);
}

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
		free(str);
		stack1 = creat_list(str_arr);
		array_int = full_int(str_arr, count_arg);
		main_checker(&stack1, count_arg, array_int);
		leaks(str_arr);
		ft_lst_leaks(stack1);
		free(array_int);
	}
	return (0);
}
