
#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	if (argc != 5 && argc != 6)
	{
		ft_print_error(1);
		return (FALIURE);
	}
	if (ft_check_args(argv) == ERROR)
		return (FALIURE);
	if (ft_init(argc, argv, &main) == ERROR || ft_fork_init(&main) == ERROR
		|| ft_philo_init(&main) == ERROR)
		return (FALIURE);

	return (SUCESS);
}
