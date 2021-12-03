/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:50:04 by igarg             #+#    #+#             */
/*   Updated: 2021/11/29 10:03:50 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				name;
	int				fork_one;
	int				fork_two;
	long			last_eat;
	pthread_t		dead;

}	t_philo;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex_taken;

}	t_fork;

typedef struct s_seating
{
	int				stop_life;
	int				count;
	int				time_die;
	int				time_eat;
	int				time_slip;
	int				quantity_day;
	int				num_philo;
	unsigned long	start_time;
	pthread_t		*stream;
	t_philo			*philo;
	t_fork			*fork;
	pthread_mutex_t	mutex;

}	t_seating;

void	*start_life(void *seat);
int		set_arg(char **argv, t_seating *seat);
int		ft_atoi(const char *str);
int		my_exit(t_seating *s);
void	my_usleep(long time);
long	time_now(void);
void	control_ft(t_seating *st);

//void	*check_dead(void *seating);
//void	time_die(int n, t_seating *p);

#endif
