/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_monitor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:20:59 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/14 18:48:06 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	philosopher_is_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die
		&& philo->eating == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (FAILURE);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (SUCCESS);
}

static int	found_philo_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].num_of_philos)
	{
		if (philosopher_is_dead(&philo[i], philo[i].time_to_die))
		{
			print_message(DEAD_MSG, &philo[i], philo[i].id);
			pthread_mutex_lock(philo->dead_lock);
			*(philo->found_dead) = 1;
			pthread_mutex_unlock(philo->dead_lock);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

static int	track_meals(t_philo *philo)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philo[0].num_times_to_eat == BUFFET_TIME)
		return (SUCCESS);
	while (i < philo[0].num_of_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[0].num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (finished_eating == philo[0].num_of_philos)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*(philo->found_dead) = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (FAILURE);
	}
	return (SUCCESS);
}

void	*monitor(void *pointer)
{
	t_philo		*philo;
	int			loop_condition;

	philo = (t_philo *)pointer;
	loop_condition = 1;
	while (loop_condition)
	{
		if ((found_philo_death(philo) == FAILURE) || \
		(track_meals(philo) == FAILURE))
			break ;
	}
	return (pointer);
}
