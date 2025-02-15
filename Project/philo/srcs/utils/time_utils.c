/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:24:44 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/10 17:48:58 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, ERR_TIME, ft_strlen(ERR_TIME));
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	precise_sleep(size_t sleep_time)
{
	size_t	start;
	size_t	initial_sleep;

	start = get_current_time();
	initial_sleep = (sleep_time * 1000) + (start % 100);
	usleep(initial_sleep);
	while ((get_current_time() - start) < sleep_time)
	{
		usleep(1000);
	}
	return (SUCCESS);
}
