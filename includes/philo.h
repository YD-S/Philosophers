/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:37:30 by ysingh            #+#    #+#             */
/*   Updated: 2023/06/02 15:43:04 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define FRED "\033[0;31m"
# define FGREEN "\033[0;32m"
# define FYELLOW "\033[0;33m"
# define FBLUE "\033[0;34m"
# define FPURPLE "\033[0;35m"
# define NONE "\033[0;37m"
//Colors End

typedef struct s_main
{
	struct s_philo	*philos;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				total_meals;
	int				out;
	pthread_mutex_t	is_eating;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
}					t_main;

typedef struct s_count
{
	int				i;
	int				finished;
	int				is_dead;
}					t_count;

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
void				ft_usleep(size_t ms, t_main *main);
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
void				*ft_calloc(size_t count, size_t size);
void				ft_unlocker(t_philo *philo);
int					get_is_dead(t_philo *philo);
int					ft_get_out(t_main *main);
void				ft_set_out(t_main *main);
void				ft_one_philo(t_philo *philo);
void				ft_death_check(t_main *main, int *is_dead, int *i);
void				ft_meal_check(t_main *main, int *finished, int i);

#endif
