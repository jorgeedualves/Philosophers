/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:43:51 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/07 22:55:39 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *one_philo(t_philo *philo)
{
    pthread_mutex_lock(&philo->struct_data->forks[philo->right_fork]);
    philo->last_meal = get_time();
    print_status(get_time(), philo, "has taken a fork");
    pthread_mutex_unlock(&philo->struct_data->forks[philo->right_fork]);
    philo->struct_data->checker = 1;							
	return (NULL);
}

void eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->struct_data->forks[philo->left_fork]);
    pthread_mutex_lock(&philo->struct_data->forks[philo->right_fork]);
    philo->last_meal = get_time();
    print_status(get_time(), philo, "has taken a fork");
    print_status(get_time(), philo, "has taken a fork");
    print_status(get_time(), philo, "is eating");
    usleep(philo->struct_data->time_to_eat *1000);
    pthread_mutex_unlock(&philo->struct_data->forks[philo->left_fork]);
    pthread_mutex_unlock(&philo->struct_data->forks[philo->right_fork]);
}