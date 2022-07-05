/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:12:02 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/04 22:41:28 by joeduard         ###   ########.fr       */
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

typedef struct	s_dinner
{
	long	number_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	must_eat;
}				t_dinner;


//error messages
#define USAGE		"Usage: ./philo n_philo ms_to_die ms_to_eat ms_to_sleep [number_times_each_philo_must_eat]"
#define NOT_UNINT	"Arguments must be integers greater than 0"

//philos.c

//get_arguments.c
void			get_arguments(int argc, char **argv, t_dinner *dinner);

//error_check
bool			error_check(int argc, char **argv);
bool			error(char *message);

//utils
double			philos_atoi(const char *ptr);
int				ft_isdigit(int c);
void			*ft_memset(void *b, int c, size_t len);

#endif