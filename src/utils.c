
#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				ft_print_error(2);
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (SUCESS);
}

void	clear_data(t_main *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

void	ft_exit(t_main *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
	{
		ft_unlocker(&data->philos[i]);
		pthread_mutex_destroy(&data->forks[i]);
	}
	pthread_mutex_destroy(&data->write_mutex);
	clear_data(data);
}

size_t	get_last_meal(t_philo *philo)
{
	size_t	last_meal;

	pthread_mutex_lock(&philo->main->write_mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->main->write_mutex);
	return (last_meal);
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
