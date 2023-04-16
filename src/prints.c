/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:08:30 by ysingh            #+#    #+#             */
/*   Updated: 2023/04/13 15:38:41 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_status(t_philo *philo, size_t timestamp, int action)
{
	if (ft_get_out(philo->main))
		return ;
	pthread_mutex_lock(&philo->main->write_mutex);
	if (action == 1)
		printf(FBLUE "[%lu ms] philo %d has taken a fork 🥶\n" NONE,
			timestamp,
			philo->position);
	else if (action == 2)
		printf(FGREEN "[%lu ms] philo %d is eating 🤌\n" NONE, timestamp,
			philo->position);
	else if (action == 3)
		printf(FYELLOW "[%lu ms] philo %d is sleeping 😴\n" NONE, timestamp,
			philo->position);
	else if (action == 4)
		printf(FPURPLE "[%lu ms] philo %d is thinking 🤔\n" NONE, timestamp,
			philo->position);
	else if (action == 5)
		printf(FRED "[%lu ms] philo %d has met his creator 🫡\n" NONE, timestamp,
			philo->position);
	pthread_mutex_unlock(&philo->main->write_mutex);
}

int	ft_print_error(int error)
{
	if (error == 1)
		printf(FRED "Error: Invalid number of arguments\n" NONE);
	else if (error == 2)
		printf(FRED "Error: Invalid argument\n" NONE);
	else if (error == 3)
		printf(FRED "Error: Failed to create thread\n" NONE);
	else if (error == 4)
		printf(FRED "Error: Failed to create mutex\n" NONE);
	return (FALIURE);
}
