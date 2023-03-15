
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
	ft_usleep(philo->main->time_to_eat);
	set_meal_count(philo);
	if (pthread_mutex_unlock(&philo->main->forks[philo->left_fork]) != 0)
		return ;
	if (pthread_mutex_unlock(&philo->main->forks[philo->right_fork]) != 0)
		return ;
}

void	ft_sleep(t_philo *philo)
{
	ft_print_status(philo, get_time(), 3);
	ft_usleep(philo->main->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_print_status(philo, get_time(), 4);
}

void	*ft_check_death(void *temp_main)
{
	t_main	*main;
	int		i;
	int 	finished;

	main = (t_main *)temp_main;
	while (1)
	{
		finished = 0;
		i = 0;
		while (i < main->philo_count)
		{
			if (ft_is_dead(&main->philos[i]))
				return (NULL);
			if (get_meal_count(&main->philos[i]) >= main->total_meals)
				finished++;
			i++;
		}
		if (finished == main->philo_count)
			return (NULL);
		ft_usleep(5);
	}
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

void	*routine(void *temp_philo)
{
	t_philo *philo;

	philo = (t_philo *)temp_philo;
	while (!philo->is_dead)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}