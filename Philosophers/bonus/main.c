/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:53:30 by igarg             #+#    #+#             */
/*   Updated: 2021/12/01 08:51:30 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"
//// <-----------(((_!_)))
////printf("------> quantity = %d\n", st->quantity_day);

void	*check_exit(void *seating)
{
	t_seating	*p;

	p = (t_seating *)seating;
	sem_wait(p->sem_dead);
	exit(0);
}

int	my_exit(t_seating *p)
{
	usleep(500);
	kill(*p->pid, 9);
	free(p->stream);
	free(p->philo);
	free(p->pid);
	sem_close(p->sem_dead);
	sem_close(p->sem_fork);
	sem_close(p->sem_print);
	printf("\n    the end\nTHE WORLD IS DEAD\n");
	return (0);
}

void	control_ft(t_seating *p)
{
	int	i;

	i = 0;
	p->start_time = time_now();
	while (i < p->count)
	{
		p->philo[i].last_eat = p->start_time;
		p->pid[i] = fork();
		if (!p->pid[i])
		{
			p->id = i;
			start_life(p);
			break ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_seating	p;

	if (argc == 5 || argc == 6)
	{
		if (set_argv(argv, &p))
			return (0);
		control_ft(&p);
	}
	else
	{
		printf("incorrect argument\n");
		return (0);
	}
	sem_wait(p.sem_dead);
	return (my_exit(&p));
}
