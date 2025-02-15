/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:14:41 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/04 18:44:56 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_dinner		table;
	t_philo			philo[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc == 5 || argc == 6)
	{
		if (check_input(argv) == 1)
			return (error_input(), FAILURE);
		init_all(&table, philo, forks, argv);
		start_simulation(&table, forks);
		free_program(NULL, &table, forks);
	}
	else
		return (error_arguments(), FAILURE);
	return (SUCCESS);
}
