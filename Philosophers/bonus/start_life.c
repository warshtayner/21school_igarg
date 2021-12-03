/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:40:41 by igarg             #+#    #+#             */
/*   Updated: 2021/11/30 18:19:28 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

void	*check_dead(void *seating)
{
	t_seating		*p;
	unsigned long	time;
	int				i;

	p = (t_seating *)seating;
	i = 0;
	while (1)
	{
		if (p->time_die < (time_now() - p->philo[p->id].last_eat) * 1000)
		{
			time = time_now() - p->start_time;
			sem_wait(p->sem_print);
			while (i++ <= p->count)
				sem_post(p->sem_dead);
			printf("%lu\t %d died\n", time, p->philo[p->id].n);
			exit(0);
			break ;
		}
	}
	return (0);
}

void	is_eating(t_seating *p)
{
	unsigned long	time;

	sem_wait(p->sem_fork);
	sem_wait(p->sem_fork);
	time = time_now() - p->start_time;
	sem_wait(p->sem_print);
	printf("%lu\t %d has taken a fork\n", time, p->philo[p->id].n);
	printf("%lu\t %d has taken a fork\n", time, p->philo[p->id].n);
	printf("%lu\t %d is eating\n", time, p->philo[p->id].n);
	sem_post(p->sem_print);
	my_usleep(p->time_eat);
	sem_post(p->sem_fork);
	sem_post(p->sem_fork);
	p->philo[p->id].last_eat = time_now();
}

void	sliping(t_seating *p)
{
	unsigned long	time;

	time = time_now() - p->start_time;
	sem_wait(p->sem_print);
	printf("%lu\t %d is sleeping\n", time, p->philo[p->id].n);
	sem_post(p->sem_print);
	my_usleep(p->time_slip);
}

void	think(t_seating *p)
{
	unsigned long	time;

	time = time_now() - p->start_time;
	sem_wait(p->sem_print);
	printf("%lu\t %d is think\n", time, p->philo[p->id].n);
	sem_post(p->sem_print);
}

void	start_life(t_seating *p)
{
	int			i;
	pthread_t	stream;

	i = 0;
	pthread_create(&stream, NULL, &check_exit, (void *)p);
	pthread_create(&p->stream[p->id], NULL, &check_dead, (void *)p);
	while (i < p->quantity_day || p->quantity_day == -1)
	{
		is_eating(p);
		sliping(p);
		think(p);
		i++;
	}
}
