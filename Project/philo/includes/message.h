/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:57:59 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/04 18:44:23 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

# define RESET_COLOR "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"

# define ERR_CREATE "\033[31mThread creation error\033[0m"
# define ERR_JOIN "\033[31mThread join error\033[0m"
# define ERR_MUTEX "\033[31mMutex creation error\033[0m"
# define ERR_FREE "\033[31mFree error\033[0m"
# define ERR_ARG "\033[31mInvalid num of arguments, please try again.\n\033[0m"
# define ERR_INPUT "\033[31mRemember to use numbers greater than 1.\n \033[0m"
# define ERR_MONITOR "\033[31mError monitor\n \033[0m"
# define ERR_TIME "\033[31mGettimeofday error\n \033[0m"

# define ERR_USAGE_1 "\033[32mUsage: ./philo [1]number_of_philosophers \033[0m"
# define ERR_USAGE_2 "\033[32m[2]time_to_die [3]time_to_eat \033[0m"
# define ERR_USAGE_3 "\033[32m[4]time_to_sleep \033[0m"
# define ERR_USAGE_4 "\033[32m[5 opt]num_times_each_philo_must_eat.\n \033[0m"
# define ERR_USAGE_5 "\033[31mRemember to use numbers greater than 1.\n \033[0m"

# define FORK_MSG "\033[34mhas taken a fork\033[0m"
# define EAT_MSG "\033[32mis eating\033[0m"
# define SLEEP_MSG "\033[33mis sleeping\033[0m"
# define THINK_MSG "\033[36mis thinking\033[0m"
# define DEAD_MSG "\033[31mdied\033[0m"

# define ERR_DIE "\033[31mInvalid time to die\n \033[0m"
# define ERR_EAT "\033[31mInvalid time to eat\n \033[0m"
# define ERR_SLEEP "\033[31mInvalid time to sleep\n \033[0m"
# define ERR_TIME_EAT "\033[31mInvalid times to eat\n \033[0m"
# define ERR_NUM_PHILO "\033[31mInvalid philosophers number\n \033[0m"

#endif