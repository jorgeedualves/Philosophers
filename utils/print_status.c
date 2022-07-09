/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:51:20 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/08 22:23:16 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(long int time_now, t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->struct_data->print);
	if (philo->struct_data->checker != 1)
		printf("%6ld %3d %s\n", time_now - philo->struct_data->start_dinner,
			philo->philo_ID, status);
	pthread_mutex_unlock(&philo->struct_data->print);
}
