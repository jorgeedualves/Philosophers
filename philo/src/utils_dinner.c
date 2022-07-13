/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:43:51 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/13 16:40:18 by joeduard         ###   ########.fr       */
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
		pthread_mutex_lock(&data->meal);
		if (get_time() - data->philo[i].last_dinner > data->time_to_die)
		{
			print_status(get_time(), data->philo + i, "DIED");
			pthread_mutex_lock(&data->m_checker);
			data->checker = 1;
			pthread_mutex_unlock(&data->m_checker);
			pthread_mutex_unlock(&data->meal);
			return (NULL);
		}
		if (data->philo[i].had_dinner == data->to_dinner && data->to_dinner > 0)
			data->ate_dinner++;
		pthread_mutex_unlock(&data->meal);
		if (data->ate_dinner == data->number_of_philos)
		{
			pthread_mutex_lock(&data->m_checker);
			data->checker = 1;
			pthread_mutex_unlock(&data->m_checker);
			return (NULL);
		}
		if (i + 1 == data->number_of_philos)
			i = -1;
	usleep (1000);
	}
	return (NULL);
}

void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->struct_data->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->struct_data->meal);
	philo->last_dinner = get_time();
	pthread_mutex_unlock(&philo->struct_data->meal);
	print_status(get_time(), philo, "has taken a fork");
	pthread_mutex_unlock(&philo->struct_data->forks[philo->left_fork]);
	print_status(get_time(), philo, "DIED");
	pthread_mutex_lock(&philo->struct_data->m_checker);
	philo->struct_data->checker = 1;
	pthread_mutex_unlock(&philo->struct_data->m_checker);
	return (NULL);
}

void	eat(t_philo *philo)
{
	if (philo->philo_id == philo->struct_data->number_of_philos)
	{
		pthread_mutex_lock(&philo->struct_data->forks[philo->right_fork]);
		pthread_mutex_lock(&philo->struct_data->forks[philo->left_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->struct_data->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->struct_data->forks[philo->right_fork]);
	}
	pthread_mutex_lock(&philo->struct_data->meal);
	philo->last_dinner = get_time();
	pthread_mutex_unlock(&philo->struct_data->meal);
	print_status(get_time(), philo, "has taken a fork");
	print_status(get_time(), philo, "has taken a fork");
	print_status(get_time(), philo, "is eating");
	usleep(philo->struct_data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->struct_data->meal);
	philo->had_dinner++;
	pthread_mutex_unlock(&philo->struct_data->meal);
	if (philo->philo_id == philo->struct_data->number_of_philos)
	{
		pthread_mutex_unlock(&philo->struct_data->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->struct_data->forks[philo->left_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->struct_data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->struct_data->forks[philo->right_fork]);
	}
}
