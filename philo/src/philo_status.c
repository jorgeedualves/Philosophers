/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:51:20 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/14 01:03:53 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(long int time_now, t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->struct_data->print);
	pthread_mutex_lock(&philo->struct_data->m_checker);
	if (philo->struct_data->checker != 1)
		printf("Time:%6ld | Philo:%3d |Status: %s\n",
			time_now - philo->struct_data->start_dinner,
			philo->philo_id, status);
	pthread_mutex_unlock(&philo->struct_data->m_checker);
	pthread_mutex_unlock(&philo->struct_data->print);
}

int	if_philo_died(t_data *data, int i)
{
	if (get_time() - data->philo[i].last_dinner > data->time_to_die)
	{
		print_status(get_time(), data->philo + i, "DIED");
		pthread_mutex_lock(&data->m_checker);
		data->checker = 1;
		pthread_mutex_unlock(&data->m_checker);
		pthread_mutex_unlock(&data->meal);
		return (1);
	}
	return (0);
}
