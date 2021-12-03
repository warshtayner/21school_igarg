/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:48:55 by igarg             #+#    #+#             */
/*   Updated: 2021/11/30 18:35:13 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "philo.h"

void	time_die(int n, t_seating *p)
{
	unsigned long	time;
	int				i;

	time = time_now() - p->start_time;
	printf("%lu\t %d died\n", time, p->philo[n].name);
	p->stop_life = p->count;
	i = 0;
	while (i < p->count)
	{
		pthread_detach(p->stream[i]);
		i++;
	}
}

void	*check_dead(t_seating *p)
{
	int			i;

	i = 0;
	usleep(p->time_die);
	while (p->stop_life != p->count)
	{
		if (p->time_die < (time_now() - p->philo[i].last_eat) * 1000)
			time_die(i, p);
		i++;
		if (i == p->count)
			i = 0;
	}
	return (0);
}

void	control_ft(t_seating *st)
{
	st->start_time = time_now();
	while (st->num_philo < st->count)
	{
		st->philo[st->num_philo].last_eat = st->start_time;
		pthread_create(&st->stream[st->num_philo],
			NULL, start_life, (void *)st);
		usleep(50);
		st->num_philo += 2;
	}
	st->num_philo = 1;
	while (st->num_philo < st->count)
	{
		st->philo[st->num_philo].last_eat = st->start_time;
		pthread_create(&st->stream[st->num_philo],
			NULL, start_life, (void *)st);
		usleep(50);
		st->num_philo += 2;
	}
}

int	main(int argc, char **argv)
{
	t_seating	seat;

	if (argc == 5 || argc == 6)
	{
		if (!set_arg(argv, &seat))
			return (0);
		control_ft(&seat);
		check_dead(&seat);
	}
	else
	{
		printf("incorrect argument\n");
		return (0);
	}
	return (my_exit(&seat));
}
