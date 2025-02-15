/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_check_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:13:26 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/04 16:24:40 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	arg_valid(char *argv)
{
	int	i;

	i = 0;
	if (!argv || argv[i] == '\0')
		return (FAILURE);
	if (argv[i] == ' ' || argv[i] == '0')
		i++;
	if (argv[i] == '+')
		i++;
	if (argv[i] == '-')
		return (FAILURE);
	while (argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_input(char **argv)
{
	if (!argv[1] || ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > PHILO_MAX || \
		arg_valid(argv[1]) == 1)
		return (print_error(ERR_NUM_PHILO), FAILURE);
	if (!argv[2] || ft_atoi(argv[2]) <= 0 || arg_valid(argv[2]) == 1)
		return (print_error(ERR_DIE), FAILURE);
	if (!argv[3] || ft_atoi(argv[3]) <= 0 || arg_valid(argv[3]) == 1)
		return (print_error(ERR_EAT), FAILURE);
	if (!argv[4] || ft_atoi(argv[4]) <= 0 || arg_valid(argv[4]) == 1)
		return (print_error(ERR_SLEEP), FAILURE);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || arg_valid(argv[5]) == 1))
		return (print_error(ERR_TIME_EAT), FAILURE);
	return (SUCCESS);
}
