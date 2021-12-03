/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:25:09 by igarg             #+#    #+#             */
/*   Updated: 2021/11/29 10:14:24 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	is_eating(int n, t_seating *p)
{
	unsigned long	time;

	if (p->stop_life != p->count)
	{
		pthread_mutex_lock(&p->fork[p->philo[n].fork_one].mutex_taken);
		time = time_now() - p->start_time;
		printf("%lu\t %d has taken a fork\n", time, p->philo[n].name);
		pthread_mutex_lock(&p->fork[p->philo[n].fork_two].mutex_taken);
		time = time_now() - p->start_time;
		printf("%lu\t %d has taken a fork\n", time, p->philo[n].name);
		printf("%lu\t %d is eating\n", time, p->philo[n].name);
	}
	my_usleep(p->time_eat / 1000);
	p->philo[n].last_eat = time_now();
	pthread_mutex_unlock(&p->fork[p->philo[n].fork_one].mutex_taken);
	pthread_mutex_unlock(&p->fork[p->philo[n].fork_two].mutex_taken);
}

void	sliping(int n, t_seating *p)
{
	unsigned long	time;

	time = time_now() - p->start_time;
	if (p->stop_life != p->count)
		printf("%lu\t %d is sleeping\n", time, p->philo[n].name);
	my_usleep(p->time_slip / 1000);
}

void	think(int n, t_seating *p)
{
	unsigned long	time;

	time = time_now() - p->start_time;
	if (p->stop_life != p->count)
		printf("%lu\t %d is think\n", time, p->philo[n].name);
}

void	*start_life(void *seating)
{
	t_seating	*p;
	int			n;
	int			i;

	p = (t_seating *)seating;
	n = p->num_philo;
	i = 0;
	while (i < p->quantity_day || p->quantity_day == -1)
	{
		is_eating(n, p);
		sliping(n, p);
		think(n, p);
		i++;
	}
	p->stop_life++;
	return (0);
}
