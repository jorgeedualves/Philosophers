/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:28:25 by joeduard          #+#    #+#             */
/*   Updated: 2022/07/01 16:54:30 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		main(int argc, char **argv)
{
	
	if (!error_check(argc, argv))
		return (EXIT_FAILURE);
	// get_arguments(argc, argv, &philo_struct);
	// if (!init_simulation(&philo_struct)
		// return (EXIT_FAILURE);
	// print_end_message(&philo_struct);
	// destroy_mutexes();

	return (0);	
}

/*
1 - Erros:
	- poucos ou muitos argumentos OK
	- não pode número negativo
	- apenas números (não pode letras)
	- número entre 0 e INTMAX	
2 - Pegar argumentos da linha de comando e colocar na struct
3 - Fazer a simulação com base na linha de comando: criar threads (filósofos) e mutex (garfos)
4 - Encerrar o programa e destruir mutes
*/