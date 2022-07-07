/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:58:05 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/06 23:55:01 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int    ft_atoi(const char *ptr)
{
    int    res;
    int    sign;
    int    i;

    res = 0;
    sign = 1;
    i = 0;
    while (ptr[i] == ' ' || (ptr[i] >= '\t' && ptr[i] <= '\r' ))
        i++;
    if (ptr[i] == '+' || ptr[i] == '-')
    {
        if (ptr[i] == '-')
            sign *= -1;
        i++;
    }
    while (ptr[i] >= '0' && ptr[i] <= '9')
    {
        res = ptr[i] - '0' + (res * 10);
        i++;
    }
    return (res * sign);
}

long int	get_time(void)
{
	struct timeval	tv;
	long int		milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_s;
	size_t			i;

	i = 0;
	s_s = (unsigned char *)s;
	while (i < n)
	{
		s_s[i] = '\0';
		i++;
	}
}
