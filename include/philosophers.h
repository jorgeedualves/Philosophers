/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:12:02 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/06 22:36:23 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <limits.h>
#include <sys/time.h>

#define MIN_ARGS	5
#define MAX_ARGS	6

//error messages
#define USAGE        "Usage: ./philo n_philo ms_to_die ms_to_eat ms_to_sleep [number_times_each_philo_must_eat]"
#define NOT_UNINT    "Arguments must be integers greater than 0"

typedef struct s_data
{
	int			number_of_philos;
	int 		time_to_die;
	int			time_to_eat;
	int 		time_to_sleep;
	int			must_eat;
	int			checker;
	int			ate_meal;
	long int	start_meal;
//	t_philo		*philo;
	pthread_t	monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}				t_data;


bool	error_check(int argc, char **argv);

#endif