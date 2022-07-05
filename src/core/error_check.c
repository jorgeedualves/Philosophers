/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:28:22 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/05 07:45:40 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	is_out_of_range(double number)
{
	if (number > INT_MAX || number == 0)
		return (true);
	return (false);	
}

static bool	only_digits(char **argv, int i, int j)
{
	while (argv[i][++j])
		if (ft_isdigit(argv[i][j]))
			return (false);
	return (true);	
}

static bool	only_unsigned_integers(int argc, char **argv, int i)
{
	while (i < argc)
	{
		if (!only_digits(argv, i, -1))
			return false;
		if (is_out_of_range(ft_atoi(argv[i])))
			return false;
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
	argc--;
	argv++;
	if (argc < MIN_ARGS || argc > MAX_ARGS)
		return (error(USAGE));
	if (!only_unsigned_integers(argc, argv, 0))
		return (error(NOT_UNINT));
	return (true);
}