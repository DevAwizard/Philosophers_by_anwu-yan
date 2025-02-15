/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:20:31 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/11 13:42:53 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	init_argv(t_philo *philo, char **argv)
{
	philo->num_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoi(argv[5]);
	else
		philo->num_times_to_eat = BUFFET_TIME;
}

static void	init_philos(t_philo *philos, t_dinner *table, \
	pthread_mutex_t *forks, char **argv)
{
	int	i;
	int	num_philo;

	num_philo = ft_atoi(argv[1]);
	i = 0;
	while (i < num_philo)
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_argv(&philos[i], argv);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].write_lock = &table->write_lock;
		philos[i].dead_lock = &table->dead_lock;
		philos[i].meal_lock = &table->meal_lock;
		philos[i].found_dead = &table->dead_flag;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

static void	init_forks(pthread_mutex_t *forks, int total_philo)
{
	int	i;

	i = 0;
	while (i < total_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

static void	init_program(t_dinner *table, t_philo *philos)
{
	table->dead_flag = 0;
	table->philos = philos;
	pthread_mutex_init(&table->dead_lock, NULL);
	pthread_mutex_init(&table->write_lock, NULL);
	pthread_mutex_init(&table->meal_lock, NULL);
}

void	init_all(t_dinner *table, t_philo *philos, pthread_mutex_t *forks, \
	char **argv)
{
	init_program(table, philos);
	init_philos(philos, table, forks, argv);
	init_forks(forks, ft_atoi(argv[1]));
}
