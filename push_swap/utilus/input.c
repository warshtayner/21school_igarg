/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 12:38:19 by igarg             #+#    #+#             */
/*   Updated: 2021/11/03 13:31:17 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "../push_swap.h"

char	*ft_join(char **str)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (!ret)
		{
			ret = ft_strdup(str[i++]);
		}
		else
		{
			tmp = ret;
			ret = ft_strjoin(ret, " ");
			free(tmp);
			tmp = ret;
			ret = ft_strjoin(ret, str[i++]);
			free(tmp);
		}
	}
	return (ret);
}

int	atoi_swap(char *str)
{
	int			i;
	int			is_neg;
	long int	res;

	i = 0;
	res = 0;
	is_neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			is_neg *= -1;
	}
	if (!ft_isdigit(str[i]))
		error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + is_neg * (str[i++] - 48);
		if (res < -2147483648 || res > 2147483647 )
			error();
	}
	if (!ft_isdigit(str[i]) && str[i] != '\0')
		error();
	return (res);
}

int	ft_count_arg(char const *s, char c)
{
	int	i;
	int	word;

	i = -1;
	word = 0;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
	}
	return (word);
}

t_stack_list	*creat_list(char **str_arr)
{
	t_stack_list	*ret;
	int				i;

	i = -1;
	ret = 0;
	while (str_arr[++i])
		ft_lstadd_back(&ret, ft_lstnew(atoi_swap(str_arr[i])));
	return (ret);
}
