
#include "philo.h"

int	ft_init(int argc, char **argv, t_main *main)
{
	main->philo_count = ft_atoi(argv[1]);
	main->time_to_die = ft_atoi(argv[2]);
	main->time_to_eat = ft_atoi(argv[3]);
	main->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		main->total_meals = ft_atoi(argv[5]);
	else
		main->total_meals = -1;
	if (main->philo_count < 2 || main->total_meals == 0)
	{
		ft_print_error(1);
		return (ERROR);
	}
	main->start_time = get_time();
	return (SUCESS);
}

int	ft_fork_init(t_main *main)
{
	int	i;

	i = 0;
	main->forks = malloc(sizeof(pthread_mutex_t) * main->philo_count);
	if (!main->forks)
		return (ERROR);
	while (i < main->philo_count)
	{
		if (pthread_mutex_init(&main->forks[i], NULL) != 0)
			return (ERROR);
		i++;
	}
	if (pthread_mutex_init(&main->write_mutex, NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&main->is_eating, NULL) != 0)
		return (ERROR);
	return (SUCESS);
}

int	ft_philo_init(t_main *main)
{
	int i;

	i = 0;
	main->philos = malloc(sizeof(t_philo) * main->philo_count);
	if (!main->philos)
		return (ERROR);
	while (i < main->philo_count)
	{
		main->philos[i].position = i + 1;
		main->philos[i].is_dead = 0;
		main->philos[i].meal_count = 0;
		main->philos[i].last_meal = 0;
		main->philos[i].left_fork = i;
		main->philos[i].right_fork = (i + 1) % main->philo_count;
		main->philos[i].main = main;
		i++;
	}
	return (SUCESS);
}