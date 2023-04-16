/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:08:18 by ysingh            #+#    #+#             */
/*   Updated: 2023/04/14 19:03:14 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_one_philo(t_philo *philo)
{
	printf(FBLUE "[%lu ms] philo %d has taken a fork 🥶\n" NONE, get_time(), 1);
	ft_usleep(philo->main->time_to_die, philo->main);
	printf(FRED "[%lu ms] philo %d has met his creator 🫡\n"NONE, get_time(), 1);
}

int	ft_start(t_main *main)
{
	int			i;
	pthread_t	*tid;

	tid = ft_calloc(sizeof(pthread_t), main->philo_count + 1);
	i = 0;
	while (i < main->philo_count)
	{
		if (pthread_create(&tid[i], NULL, &routine, (void *)&main->philos[i]))
			return (ft_print_error(3));
		i++;
	}
	if (pthread_create(&tid[i], NULL, &ft_check_death, (void *)main))
		return (ft_print_error(3));
	i = 0;
	while (i < main->philo_count + 1)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	*main;

	main = ft_calloc(sizeof(t_main), 1);
	if (argc != 5 && argc != 6)
		return (ft_print_error(1));
	if (ft_check_args(argv) == ERROR)
		return (FALIURE);
	if (ft_init(argc, argv, main) == ERROR || ft_fork_init(main) == ERROR
		|| ft_philo_init(main) == ERROR)
		return (FALIURE);
	if (main->philo_count == 1)
	{
		ft_one_philo(main->philos);
		return (0);
	}
	if (ft_start(main) == ERROR)
		return (FALIURE);
	ft_exit(main);
	return (SUCESS);
}
