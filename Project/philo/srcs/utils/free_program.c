/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:01:34 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/04 18:53:28 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	free_program(char *msg, t_dinner *table, pthread_mutex_t *forks)
{
	int	i;
	int	num_philos;

	if (msg)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	if (table)
	{
		num_philos = table->philos[0].num_of_philos;
		pthread_mutex_destroy(&table->dead_lock);
		pthread_mutex_destroy(&table->meal_lock);
		pthread_mutex_destroy(&table->write_lock);
		if (forks)
		{
			i = 0;
			while (i < num_philos)
			{
				pthread_mutex_destroy(&forks[i]);
				i++;
			}
		}
	}
}
