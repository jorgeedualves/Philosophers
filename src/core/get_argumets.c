/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argumets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:39:53 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/04 22:40:10 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	*define_variable(int id, t_dinner *dinner)
{
	if (id == 1)
		return (&dinner->number_of_philos);
	if (id == 2)
		return (&dinner->time_to_die);
	if (id == 3)
		return (&dinner->time_to_eat);
	if (id == 4)
		return (&dinner->time_to_sleep);
	else
		return (&dinner->must_eat);
}

static void	assign_value(int id, int value, t_dinner *dinner)
{
	long *variable;

	variable = define_variable(id, dinner);
	*variable =  value;
	
	printf("data: %lu\n", *variable);
}

void	get_arguments(int argc, char **argv, t_dinner *dinner)
{
	int	i;

	i = 0;
	ft_memset(dinner, 0, sizeof(t_dinner));
	while (++i < argc)
		assign_value(i, (long)philos_atoi(argv[i]), dinner);
}
