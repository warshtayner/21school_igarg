/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:54:15 by igarg             #+#    #+#             */
/*   Updated: 2021/11/30 18:15:57 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>

typedef struct s_philo
{
	int		n;
	long	last_eat;

}	t_philo;

typedef struct s_seating
{
	int				count;
	int				time_die;
	int				time_eat;
	int				time_slip;
	int				quantity_day;
	int				id;
	unsigned long	start_time;
	pthread_t		*stream;
	t_philo			*philo;
	pid_t			*pid;
	sem_t			*sem_print;
	sem_t			*sem_fork;
	sem_t			*sem_dead;

}	t_seating;

int		ft_atoi(const char *str);
int		set_argv(char **argv, t_seating *seat);
long	time_now(void);
void	my_usleep(long time);
void	start_life(t_seating *p);
void	*check_exit(void *seating);

#endif
