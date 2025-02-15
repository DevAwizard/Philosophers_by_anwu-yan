/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:19:03 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/04 12:19:06 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_atoi(char *string)
{
	int	index;
	int	sign;
	int	number;

	index = 0;
	while ((string[index] >= 9 && string[index] <= 12) || string[index] == 32)
		index++;
	sign = 1;
	if (string[index] == '+' || string[index] == '-')
	{
		if (string[index] == '-')
			sign = -1;
		index++;
	}
	number = 0;
	while (string[index] >= '0' && string[index] <= '9')
	{
		number = (number * 10) + string[index] - 48;
		index++;
	}
	return (number * sign);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i] != 0)
		i++;
	return (i);
}
