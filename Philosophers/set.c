/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:01:32 by igarg             #+#    #+#             */
/*   Updated: 2021/11/29 10:10:30 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	set_philo_dop(t_seating *st)
{
	int	i;

	i = 0;
	while (i < st->count)
	{
		st->philo[i].name = i + 1;
		st->philo[i].fork_one = i;
		if (i - 1 < 0)
			st->philo[i].fork_two = st->count - 1;
		else
			st->philo[i].fork_two = i - 1;
		st->fork[i].id = i + 1;
		pthread_mutex_init(&st->fork[i].mutex_taken, NULL);
		i++;
	}
}

int	set_philo(t_seating *st)
{
	st->philo = malloc(sizeof(t_philo[st->count]));
	if (!st->philo)
	{
		free(st->stream);
		return (0);
	}
	st->fork = malloc(sizeof(t_fork[st->count]));
	if (!st->philo)
	{
		free(st->stream);
		free(st->philo);
		return (0);
	}
	set_philo_dop(st);
	return (1);
}

int	set_arg(char **argv, t_seating *seat)
{
	seat->count = ft_atoi(argv[1]);
	seat->time_die = ft_atoi(argv[2]) * 1000;
	seat->time_eat = ft_atoi(argv[3]) * 1000;
	seat->time_slip = ft_atoi(argv[4]) * 1000;
	seat->num_philo = 0;
	seat->stop_life = 0;
	seat->stream = malloc(sizeof(pthread_t[seat->count]));
	if (seat->stream == NULL)
		return (0);
	if (argv[5])
		seat->quantity_day = ft_atoi(argv[5]);
	else
		seat->quantity_day = -1;
	set_philo(seat);
	return (1);
}
