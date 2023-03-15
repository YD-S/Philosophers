
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define SUCESS 1
# define FALIURE 0
# define ERROR (-1)

//Colors Start
# define FRED "\033[31;"
# define FGREEN "\033[32;"
# define FYELLOW "\033[33;"
# define FBLUE "\033[34;"
# define FPURPLE "\033[35;"
# define NONE "\033[0m"
//Colors End

typedef struct s_main
{
	struct s_philo	*philos;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				total_meals;
	size_t			start_time;
	pthread_mutex_t	is_eating;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
}					t_main;

typedef struct s_philo
{
	int				position;
	int				meal_count;
	int				is_dead;
	int				left_fork;
	int				right_fork;
	size_t			last_meal;
	t_main			*main;
}					t_philo;

void				ft_print_status(t_philo *philo, size_t timestamp,
						int action);
int					ft_print_error(int error);
void				ft_usleep(size_t ms);
size_t				get_time(void);
int					ft_init(int argc, char **argv, t_main *main);
int					ft_atoi(const char *str);
int					ft_philo_init(t_main *main);
int					ft_fork_init(t_main *main);
int					ft_check_args(char **argv);
void				ft_exit(t_main *data);
int					ft_start(t_main *main);
void				*routine(void *temp_philo);
int					ft_is_dead(t_philo *philo);
void				*ft_check_death(void *temp_main);
size_t				get_last_meal(t_philo *philo);
void				set_last_meal(t_philo *philo);
void				set_meal_count(t_philo *philo);
int					get_meal_count(t_philo *philo);
void				set_is_dead(t_philo *philo);

#endif
