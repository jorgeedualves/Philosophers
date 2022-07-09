/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:12:02 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/09 00:04:48 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>

# define MIN_ARGS	5
# define MAX_ARGS	6

//error messages
# define USAGE "Usage: ./philo philo_id ms_to_die ms_eat ms_sleep [have_to_eat]"
# define NOT_UNINT "Arguments must be integers greater than 0"
# define PTHREAD_FAILURE "Could not create thread"

typedef struct s_data		t_data;

typedef struct s_philo
{
	int				left_fork;
	int				right_fork;
	int				philo_id;
	int				had_dinner;
	long int		last_dinner;
	pthread_mutex_t	mutex;
	pthread_t		thread;
	t_data			*struct_data;
}					t_philo;

typedef struct s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				have_to_dinner;
	int				checker;
	int				ate_dinner;
	long int		start_dinner;
	t_philo			*philo;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}				t_data;

//error_check.c
bool		error_check(int argc, char **argv);
bool		error(char *message);
//utils.c
int			ft_atoi(const char *ptr);
long int	get_time(void);
void		ft_bzero(void *s, size_t n);

//utils_dinner.c
void		*died(void *param);
void		*one_philo(t_philo *philo);
void		eat(t_philo *philo);

//print_status.c
void		print_status(long int time_now, t_philo *philo, char *status);

#endif