/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:37:11 by ysingh            #+#    #+#             */
/*   Updated: 2023/04/13 15:38:17 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_death_check(t_main *main, int *is_dead, int *i)
{
	if (ft_is_dead(&main->philos[*i]))
		*is_dead = 1;
}

void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->write_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->main->write_mutex);
}

void	set_meal_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->write_mutex);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->main->write_mutex);
}

int	get_meal_count(t_philo *philo)
{
	int	meal_count;

	pthread_mutex_lock(&philo->main->write_mutex);
	meal_count = philo->meal_count;
	pthread_mutex_unlock(&philo->main->write_mutex);
	return (meal_count);
}

void	set_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->write_mutex);
	philo->is_dead = 1;
	pthread_mutex_unlock(&philo->main->write_mutex);
}
