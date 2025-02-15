/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   used_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:02:16 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/04 18:40:03 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USED_FUNCTIONS_H
# define USED_FUNCTIONS_H

# include "structs.h"

// Input validation
int		check_input(char **argv);

// String operations
int		ft_atoi(char *string);
int		ft_isdigit(int c);
size_t	ft_strlen(char *string);

// Erro handling
void	error_arguments(void);
void	error_input(void);
void	print_error(char *msg);

// Program initialization
void	init_all(t_dinner *table, t_philo *philos, pthread_mutex_t *forks, \
	char **argv);

// Resource management
void	free_program(char *msg, t_dinner *table, pthread_mutex_t *forks);
void	free_monitor(t_philo *philo);

// Simulation control
int		start_simulation(t_dinner *table, pthread_mutex_t *forks);
void	*philo_routine(void *pointer);
void	*monitor(void *pointer);

// Time management
size_t	get_current_time(void);
int		precise_sleep(size_t sleep_time);

// State checking
int		no_death_detected(t_philo *philo);

// Output
void	print_message(char *str, t_philo *philo, int id);

// Philosopher actions
void	dream(t_philo *philo);
void	think(t_philo *philo);
void	eat(t_philo *philo);

#endif