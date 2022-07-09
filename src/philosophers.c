/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:57:11 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/08 22:23:16 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_info(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)					// philo[0]		|	philo[1]	|	philo[2]
	{
		data->philo[i].philo_ID = i + 1;					//   ID 1		|	ID 2		|	ID 3
		data->philo[i]. left_fork = i;					//	LEFT = 0	|	= 1			|	= 2
		data->philo[i].right_fork = i + 1;				//	RIGHT = 1	|	= 2			|	= 0
		data->philo[i].struct_data = data;
		data->philo[i].last_dinner = get_time();
		data->philo[i].had_dinner = 0;
		if (i + 1 == data->number_of_philos)
			data->philo[i].right_fork = 0;
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	start_struct(t_data *data, int argc, char **argv)
{
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		data->have_to_dinner = ft_atoi(argv[5]);
	else
		data->have_to_dinner = 0;
	data->forks = NULL;
	data->philo = malloc(data->number_of_philos * sizeof(t_philo));
	data->forks = malloc(data->number_of_philos * sizeof(pthread_mutex_t));
	data->ate_dinner = 0;
	ft_bzero(data->philo, sizeof(t_philo));
	return (philo_info(data));
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = param;
	if (philo->struct_data->number_of_philos == 1)
		return (one_philo(philo));
	if (philo->philo_ID % 2 == 0)
		usleep(1600);
	while (philo->struct_data->checker != 1)
	{
		eat(philo);
		print_status(get_time(), philo, "is sleeping");
		usleep(philo->struct_data->time_to_sleep * 1000);
		print_status(get_time(), philo, "is thinking");
		philo->had_dinner++;
	}
	return (NULL);
}

int	creat_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philos)
		pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]);
	return (i);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	pthread_mutex_init(&data.print, NULL);
	if (!error_check(argc, argv))
		return (EXIT_FAILURE);
	data.start_dinner = get_time();
	start_struct(&data, argc, argv);
	creat_philo(&data);
	pthread_create(&data.monitor, NULL, &died, &data);
	while (++i < data.number_of_philos)
		pthread_join(data.philo[i].thread, NULL);
	pthread_join(data.monitor, NULL);
	free(data.philo);
	free(data.forks);
	return (0);
}
