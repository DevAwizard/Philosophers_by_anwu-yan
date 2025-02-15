/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_philo_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:10:11 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/14 18:48:50 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	check_time_and_eat(t_philo *philo)
{
	size_t	time_left;

	if (*philo->found_dead)
		return ;
	time_left = philo->time_to_die - (get_current_time() - philo->last_meal);
	if (time_left < 0)
	{
		print_message(DEAD_MSG, philo, philo->id);
		pthread_mutex_lock(philo->dead_lock);
		*(philo->found_dead) = 1;
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	if (time_left < philo->time_to_eat)
		precise_sleep(time_left);
	else
		precise_sleep(philo->time_to_eat);
}

void	eat(t_philo *philo)
{
	if (*philo->found_dead)
		return ;
	pthread_mutex_lock(philo->r_fork);
	print_message(FORK_MSG, philo, philo->id);
	pthread_mutex_lock(philo->l_fork);
	print_message(FORK_MSG, philo, philo->id);
	philo->eating = 1;
	print_message(EAT_MSG, philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	check_time_and_eat(philo);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	think(t_philo *philo)
{
	print_message(THINK_MSG, philo, philo->id);
}

void	dream(t_philo *philo)
{
	size_t	time_left;

	if (*philo->found_dead)
		return ;
	print_message(SLEEP_MSG, philo, philo->id);
	time_left = philo->time_to_die - (get_current_time() - philo->last_meal);
	if (time_left < 0)
	{
		print_message(DEAD_MSG, philo, philo->id);
		pthread_mutex_lock(philo->dead_lock);
		*(philo->found_dead) = 1;
		pthread_mutex_unlock(philo->dead_lock);
		return ;
	}
	if (time_left < philo->time_to_sleep)
		precise_sleep(time_left);
	else
		precise_sleep(philo->time_to_sleep);
}
