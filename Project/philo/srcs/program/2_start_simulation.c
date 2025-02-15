/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_start_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:58:38 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/04 18:47:41 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	start_simulation(t_dinner *table, pthread_mutex_t *forks)
{
	pthread_t	host;
	int			i;

	if (pthread_create(&host, NULL, &monitor, table->philos) != 0)
		free_program(ERR_CREATE, table, forks);
	i = 0;
	while (i < table->philos[0].num_of_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &philo_routine, \
			&table->philos[i]) != 0)
			free_program(ERR_CREATE, table, forks);
		i++;
	}
	i = 0;
	if (pthread_join(host, NULL) != 0)
		free_program(ERR_JOIN, table, forks);
	while (i < table->philos[0].num_of_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			free_program(ERR_JOIN, table, forks);
		i++;
	}
	return (0);
}
