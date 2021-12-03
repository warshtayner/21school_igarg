/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:08:55 by igarg             #+#    #+#             */
/*   Updated: 2021/11/29 10:03:50 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	my_usleep(long time)
{
	long	t;

	t = time_now();
	while (time_now() - t < time)
		usleep(10);
}

long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long)time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	my_exit(t_seating *s)
{
	free(s->stream);
	free(s->philo);
	free(s->fork);
	printf("\n    the end\nTHE WORLD IS DEAD\n");
	return (0);
}
