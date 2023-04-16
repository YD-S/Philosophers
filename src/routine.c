/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:08:22 by ysingh            #+#    #+#             */
/*   Updated: 2023/04/14 15:30:15 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->main->forks[philo->left_fork]) != 0)
		return ;
	if (pthread_mutex_lock(&philo->main->forks[philo->right_fork]) != 0)
		return ;
	ft_print_status(philo, get_time(), 1);
	ft_print_status(philo, get_time(), 1);
	if (pthread_mutex_lock(&philo->main->is_eating) != 0)
		return ;
	ft_print_status(philo, get_time(), 2);
	if (pthread_mutex_unlock(&philo->main->is_eating) != 0)
		return ;
	set_last_meal(philo);
	ft_usleep(philo->main->time_to_eat, philo->main);
	set_meal_count(philo);
	if (pthread_mutex_unlock(&philo->main->forks[philo->left_fork]) != 0)
		return ;
	if (pthread_mutex_unlock(&philo->main->forks[philo->right_fork]) != 0)
		return ;
}

void	ft_sleep(t_philo *philo)
{
	ft_print_status(philo, get_time(), 3);
	ft_usleep(philo->main->time_to_sleep, philo->main);
}

void	ft_think(t_philo *philo)
{
	ft_print_status(philo, get_time(), 4);
}

void	*routine(void *temp_philo)
{
	t_philo	*philo;

	philo = (t_philo *)temp_philo;
	if (philo->position % 2 == 0)
		usleep(100);
	else
		usleep(50);
	while (!get_is_dead(philo) && !ft_get_out(philo->main))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	ft_unlocker(philo);
	return (NULL);
}
