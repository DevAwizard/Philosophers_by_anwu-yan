/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_philo_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:13:59 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/14 18:49:16 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	no_death_detected(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->found_dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (FAILURE);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (SUCCESS);
}

static void	one_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_message(FORK_MSG, philo, philo->id);
	precise_sleep(philo->time_to_die);
	pthread_mutex_unlock(philo->r_fork);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		precise_sleep(100);
	while (!no_death_detected(philo))
	{
		if (philo->num_of_philos == 1)
			one_philo_eat(philo);
		else
		{
			if (philo[0].num_times_to_eat == 0)
				return (pointer);
			if (*philo->found_dead)
				return (pointer);
			eat(philo);
			if (*philo->found_dead)
				return (pointer);
			dream(philo);
			if (*philo->found_dead)
				return (pointer);
			think(philo);
		}
	}
	return (pointer);
}
