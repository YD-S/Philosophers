/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:30:26 by ysingh            #+#    #+#             */
/*   Updated: 2023/04/14 15:35:31 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_check_death(void *temp_main)
{
	t_main	*main;
	int		i;
	int		finished;
	int		is_dead;

	is_dead = 0;
	main = (t_main *)temp_main;
	while (!is_dead)
	{
		finished = 0;
		i = 0;
		while (i < main->philo_count)
		{
			ft_death_check(main, &is_dead, &i);
			if (is_dead)
				break ;
			ft_meal_check(main, &finished, i);
			i++;
		}
		if (finished == main->philo_count)
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
