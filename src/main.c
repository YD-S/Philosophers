
#include "philo.h"

int	ft_start(t_main *main)
{
	int			i;
	pthread_t	tid;

	i = 0;
	while (i < main->philo_count)
	{
		if (pthread_create(&tid, NULL, &routine, (void *)&main->philos[i]))
			return (ft_print_error(3));
		pthread_detach(tid);
		if (main->philo_count % 2 == 0)
			ft_usleep(100);
		else
			ft_usleep(50);
		i++;
	}
	if (pthread_create(&tid, NULL, &ft_check_death, (void *)main))
		return (ft_print_error(3));
	pthread_detach(tid);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	main;

	if (argc != 5 && argc != 6)
		return (ft_print_error(1));
	if (ft_check_args(argv) == ERROR)
		return (FALIURE);
	if (ft_init(argc, argv, &main) == ERROR || ft_fork_init(&main) == ERROR
		|| ft_philo_init(&main) == ERROR)
		return (FALIURE);
	if (ft_start(&main) == ERROR)
		return (FALIURE);
	ft_exit(&main);
	return (SUCESS);
}
