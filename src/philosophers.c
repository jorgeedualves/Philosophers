/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:57:11 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/07 00:05:16 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    philo_info(t_data *data)
{
    int i;

    i = 0;
    while(i < data->number_of_philos)
    {
        data->philo[i].n_philo = i + 1;
        data->philo[i]. left_fork = i;
        data->philo[i].right_fork = i + 1;
        data->philo[i].struct_data = data;
        data->philo[i].last_meal = get_time();
        data->philo[i].n_meals = 0;
        if( i + 1 == data->number_of_philos)
            data->philo[i].right_fork = 0;
        pthread_mutex_init(&data->forks[i], NULL);
        i++;        
    }
}

 void   start_struct(t_data *data, int argc, char **argv)
 {
    data->number_of_philos = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    if(argc > 5)
        data->must_eat = ft_atoi(argv[5]);
    else
        data->must_eat = 0;
    data->forks = NULL;
    data->philo = malloc(data->number_of_philos * sizeof(t_philo));
    data->forks = malloc(data->number_of_philos *sizeof(pthread_mutex_t));
    data->ate_meal = 0;
    ft_bzero(data->philo, sizeof(t_philo));
    return(philo_info(data));
 }

int	creat_philo(t_data *data)
{
	int i;

	i=-1;
	while(++i < data->number_of_philos)
		pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]);
	return(i);
}

int main(int argc, char **argv)
{
    t_data data;
    int i;

    i = 0;
    pthread_mutex_init(&data.print, NULL);
    if (!error_check(argc, argv))
        return (EXIT_FAILURE);
    data.start_meal = get_time();
    start_struct(&data, argc, argv);
    creat_philo(&data);

    (void)i;

    return (0);
}