/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:43:51 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/08 22:22:49 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*died(void *param)
{
	int		i;
	t_data	*data;

	data = param;
	i = -1;
	while (++i < data->number_of_philos)
	{
		if (get_time() - data->philo[i].last_dinner > data->time_to_die)
		{
			print_status(get_time(), data->philo, "DIED");
			data->checker = 1;
			return (NULL);
		}
		if (data->philo[i].had_dinner == data->have_to_dinner && data->have_to_dinner > 0)
			data->ate_dinner++;
		if (data->ate_dinner == data->number_of_philos)
		{
			data->checker = 1;
			return (NULL);
		}
		if (i + 1 == data->number_of_philos)
			i = -1;
		usleep (1600);
	}
	return (NULL);
}

void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->struct_data->forks[philo->right_fork]);
	philo->last_dinner = get_time();
	print_status(get_time(), philo, "has taken a fork");
	pthread_mutex_unlock(&philo->struct_data->forks[philo->right_fork]);
	print_status(get_time(), philo, "DIED");
	philo->struct_data->checker = 1;
	return (NULL);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->struct_data->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->struct_data->forks[philo->right_fork]);
	philo->last_dinner = get_time();
	print_status(get_time(), philo, "has taken a fork");
	print_status(get_time(), philo, "has taken a fork");
	print_status(get_time(), philo, "is eating");
	usleep(philo->struct_data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->struct_data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->struct_data->forks[philo->right_fork]);
}
