/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:30:26 by ysingh            #+#    #+#             */
/*   Updated: 2023/06/02 15:44:07 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_check_death(void *temp_main)
{
	t_main	*main;
	t_count	cont;

	cont.is_dead = 0;
	main = (t_main *)temp_main;
	while (!cont.is_dead)
	{
		cont.finished = 0;
		cont.i = 0;
		while (cont.i < main->philo_count)
		{
			ft_death_check(main, &cont.is_dead, &cont.i);
			if (cont.is_dead)
				break ;
			if (get_meal_count(&main->philos[cont.i]) >= main->total_meals
				&& main->total_meals != -1)
				cont.finished++;
			cont.i++;
		}
		if (cont.finished == main->philo_count)
			break ;
		ft_usleep(5, main);
	}
	ft_set_out(main);
	return (NULL);
}

int	ft_is_dead(t_philo *philo)
{
	if (get_time() - get_last_meal(philo) > (size_t)philo->main->time_to_die)
	{
		set_is_dead(philo);
		ft_print_status(philo, get_time(), 5);
		return (1);
	}
	return (0);
}

void	ft_meal_check(t_main *main, int *finished, int i)
{
	if (get_meal_count(&main->philos[i]) >= main->total_meals
		&& main->total_meals != -1)
		finished++;
}
