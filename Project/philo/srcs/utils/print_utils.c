/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:11:54 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/04 18:39:03 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_message(char *str, t_philo *philo, int id)
{
	pthread_mutex_lock(philo->write_lock);
	if (!no_death_detected(philo))
		printf("%zu %d %s\n", get_current_time() - philo->start_time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
}
