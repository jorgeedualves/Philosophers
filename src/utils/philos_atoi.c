/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:32:29 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/05 07:01:26 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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