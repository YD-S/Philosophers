/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:37:06 by ysingh            #+#    #+#             */
/*   Updated: 2023/04/13 15:37:08 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	static struct timeval	start;
	struct timeval			tv;

	gettimeofday(&tv, NULL);
	if (!start.tv_sec && !start.tv_usec)
		start = tv;
	return (((tv.tv_sec - start.tv_sec) * 1000) + ((tv.tv_usec - start.tv_usec)
			/ 1000));
}

void	ft_usleep(size_t ms, t_main *main)
{
	size_t	end;

	end = get_time() + ms;
	while (get_time() < end && !ft_get_out(main))
		usleep(50);
}
