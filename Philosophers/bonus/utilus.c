/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:11:34 by igarg             #+#    #+#             */
/*   Updated: 2021/11/30 18:08:23 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

void	my_usleep(long time)
{
	long	t;

	t = time_now();
	time /= 1000;
	while (time_now() - t < time)
		usleep(10);
}

long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long)time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	set_philo(t_seating *p)
{
	int	i;

	i = 0;
	sem_close(p->sem_print);
	sem_close(p->sem_fork);
	sem_unlink("/fork");
	sem_unlink("/print");
	sem_unlink("/ded");
	p->sem_fork = sem_open("/fork", O_CREAT, 0644, p->count);
	p->sem_print = sem_open("/print", O_CREAT, 0644, 1);
	p->sem_dead = sem_open("/dead", O_CREAT, 0644, 0);
	while (i < p->count)
	{
		p->philo[i].n = i + 1;
		i++;
	}
}

void	set_argv_dop(char **argv, t_seating *seat)
{
	seat->count = ft_atoi(argv[1]);
	seat->time_die = ft_atoi(argv[2]) * 1000;
	seat->time_eat = ft_atoi(argv[3]) * 1000;
	seat->time_slip = ft_atoi(argv[4]) * 1000;
	seat->id = -1;
}

int	set_argv(char **argv, t_seating *seat)
{
	set_argv_dop(argv, seat);
	if (argv[5])
		seat->quantity_day = ft_atoi(argv[5]);
	else
		seat->quantity_day = -1;
	seat->philo = malloc(sizeof(t_philo) * seat->count);
	if (!seat->philo)
		return (1);
	seat->pid = malloc(sizeof(pid_t) * seat->count);
	if (!seat->pid)
	{
		free(seat->philo);
		return (1);
	}
	seat->stream = malloc(sizeof(pthread_t) * seat->count);
	if (!seat->stream)
	{
		free(seat->pid);
		free(seat->philo);
		return (1);
	}
	set_philo(seat);
	return (0);
}
