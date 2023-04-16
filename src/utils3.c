/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:37:03 by ysingh            #+#    #+#             */
/*   Updated: 2023/04/13 15:46:22 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_is_dead(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->main->write_mutex);
	dead = philo->is_dead;
	pthread_mutex_unlock(&philo->main->write_mutex);
	return (dead);
}

int	ft_get_out(t_main *main)
{
	int	out;

	pthread_mutex_lock(&main->write_mutex);
	out = main->out;
	pthread_mutex_unlock(&main->write_mutex);
	return (out);
}

void	ft_set_out(t_main *main)
{
	pthread_mutex_lock(&main->write_mutex);
	main->out = 1;
	pthread_mutex_unlock(&main->write_mutex);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

void	ft_unlocker(t_philo *philo)
{
	pthread_mutex_unlock(&philo->main->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->main->forks[philo->right_fork]);
}
