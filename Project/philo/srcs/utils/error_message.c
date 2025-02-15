/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:17:05 by anwu-yan          #+#    #+#             */
/*   Updated: 2025/02/04 12:57:16 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	error_arguments(void)
{
	printf("%s", ERR_USAGE_1);
	printf("%s", ERR_USAGE_2);
	printf("%s", ERR_USAGE_3);
	printf("%s", ERR_USAGE_4);
	printf("%s", ERR_USAGE_5);
	printf("%s", ERR_ARG);
}

void	error_input(void)
{
	printf("%s", ERR_INPUT);
}
