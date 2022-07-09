/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:12:02 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/08 22:23:16 by joeduard         ###   ########.fr       */
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
# define	USAGE		"Usage: ./philo philo_ID ms_to_die ms_to_eat ms_to_sleep [number_times_each_philo_have_to_dinner]"
# define	NOT_UNINT	"Arguments must be integers greater than 0"

typedef struct s_data		t_data;

typedef struct s_philo
{
	int				left_fork;		// BRAÇO ESQUERDO É CRIADO
	int				right_fork;		// BRAÇO/GARFO É CRIADO
	int				philo_ID;		// ID DO PHILO
	int				had_dinner;		// QUANTIDADE DE VEZES QUE COMEU
	long int		last_dinner;		// O HORA INICIAL DA ULTIMA REFEIÇÃO 
	pthread_mutex_t	mutex;
	pthread_t		thread;
	t_data			*struct_data;	// DO PHILO  [STRCT DATA]
}					t_philo;

typedef struct	s_data		// STRUCT DATA DO TERMINAL
{
	int				number_of_philos;	//2
	int				time_to_die;		// 100
	int				time_to_eat;		// 200
	int				time_to_sleep;		// 50
	int				have_to_dinner;			// 7
	int				checker;			// 0
	int				ate_dinner;			// 0
	long int		start_dinner;			// HORA ATUAL QUANDO É CHAMADO
	t_philo			*philo;				// O PHILO É CRIADO 
	pthread_t		monitor;			// O ADMINISTRADO É CRIADO
	pthread_mutex_t	*forks;				// O MUTEX PARA TRAVAR E DESTRAVA GARFOS É CRIADO
	pthread_mutex_t	print;				// O MUTEX PARA TRAVAR E DESTRAVA A MENSAGEM
}				t_data;

//error_check.c
bool		error_check(int argc, char **argv);

//utils.c
int			ft_atoi(const char *ptr);
long int	get_time(void);
void		ft_bzero(void *s, size_t n);

//utils_dinner.c
void *died(void *param);
void *one_philo(t_philo *philo);
void eat(t_philo *philo);

//print_status.c
void	print_status(long int time_now, t_philo *philo, char *status);

#endif