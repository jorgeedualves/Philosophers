/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:28:22 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/08 21:59:58 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

double	philos_atoi(const char *ptr)
{
	double	number;

	number = 0;
	while (ft_isdigit(*ptr))
	{
		number *= 10;
		number += (*ptr - '0');
		ptr++;
	}
	return (number);
}

static bool	is_out_of_range(double number)
{
	if (number > INT_MAX || number == 0)
		return (true);
	return (false);
}

static bool	only_digits(char **argv, int i, int j)
{
	while (argv[i][++j])
		if (!ft_isdigit(argv[i][j]))
			return (false);
	return (true);
}

static	bool	only_unsigned_integers(int argc, char **argv, int i)
{
	while (++i < argc)
	{
		if (!only_digits(argv, i, -1))
			return (false);
		if (is_out_of_range(philos_atoi(argv[i])))
			return (false);
	}
	return (true);
}

bool	error(char *message)
{
	printf("%s\n", message);
	return (false);
}

bool	error_check(int argc, char **argv)
{
	if (argc < MIN_ARGS || argc > MAX_ARGS)
		return (error(USAGE));
	if (!only_unsigned_integers(argc, argv, 0))
		return (error(NOT_UNINT));
	return (true);
}
