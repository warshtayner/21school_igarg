/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:28:45 by igarg             #+#    #+#             */
/*   Updated: 2021/11/10 14:11:14 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				num;
	int				index;
	int				flag;
	struct s_list	*next;
	struct s_list	*prev;
}	t_stack_list;

typedef struct s_list_param
{
	int				min;
	int				max;
	int				mid;
	int				flag;
}	t_list_param;

int				check_position_list(t_stack_list **stack, t_stack_list *list);
int				check_sort_list(t_stack_list **stack, int count);
int				check_len_list(t_stack_list **stack);
int				ft_count_arg(char const *s, char c);
int				*full_int(char **str, int count);
int				atoi_swap(char *str);

char			*ft_join(char **str);

void			error(void);
void			leaks(char **res);
void			sa(t_stack_list **stack);
void			sb(t_stack_list	**stack);
void			ra(t_stack_list **stack);
void			rb(t_stack_list **stack);
void			rra(t_stack_list **stack);
void			rrb(t_stack_list **stack);
void			ft_lst_leaks(t_stack_list *lst);
void			ft_sorting_2(t_stack_list **stack1);
void			ft_sorting_3(t_stack_list **stack1);
void			ft_set_param_flag(t_list_param *param);
void			pa(t_stack_list **b, t_stack_list **a);
void			pb(t_stack_list **a, t_stack_list **b);
void			check_equal(char **str, int count_arg);
void			min_in_b(t_stack_list **a, t_stack_list **b);
void			rr(t_stack_list **stack, t_stack_list **stack2);
void			rrr(t_stack_list **stack, t_stack_list **stack2);
void			ss(t_stack_list	**stack1, t_stack_list **stack2);
void			set_index(t_stack_list *stack, int *arr, int count);
void			ft_lstadd_back(t_stack_list **lst, t_stack_list *new);
void			main_sorting(t_stack_list **stack1, int count, int *arr_int);
void			ft_set_stack_param(t_list_param *new, t_stack_list **stack);
void			progress_sorting(t_stack_list **a, t_stack_list **b, int count);
void			in_rr(t_stack_list **a, t_stack_list **b,
					t_list_param*param_t);
void			in_b_dop(t_stack_list **a, t_stack_list **b,
					t_list_param *param_t);
void			check_min(t_stack_list **a, t_stack_list **b,
					t_list_param *param_t);
void			in_b_first(t_stack_list **a, t_stack_list **b,
					t_list_param *param_t);

t_stack_list	*ft_lstnew(int num);
t_list_param	*ft_lstnew_param(void);
t_stack_list	*creat_list(char **str);
t_stack_list	*ft_lstlast(t_stack_list *lst);
t_stack_list	*ft_lstfirst(t_stack_list *lst);
t_stack_list	*check_last(t_stack_list **stack);
t_stack_list	*check_min_list(t_stack_list **stack);
t_stack_list	*check_max_list(t_stack_list **stack);

void			pb_com(t_stack_list **a, t_stack_list **b);
void			pa_com(t_stack_list **b, t_stack_list **a);
void			ra_com(t_stack_list **stack);
void			rb_com(t_stack_list **stack);
void			rr_com(t_stack_list **stack, t_stack_list **stack2);
void			rra_com(t_stack_list **stack);
void			rrb_com(t_stack_list **stack);
void			rrr_com(t_stack_list **stack, t_stack_list **stack2);
void			sa_com(t_stack_list	**stack);
void			sb_com(t_stack_list	**stack);
void			ss_com(t_stack_list	**stack1, t_stack_list **stack2);

#endif
