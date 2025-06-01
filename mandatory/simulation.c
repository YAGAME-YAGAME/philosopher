/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:46:53 by otzarwal          #+#    #+#             */
/*   Updated: 2025/06/01 13:37:13 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long ft_get_time()
{
    struct timeval time;

    if (gettimeofday(&time, NULL))
        return (-1);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void *routine(void *arg)
{
    t_philos *philo;

    philo = (t_philos *)arg;
    
}

int    start_simulation(t_info *info)
{
    int i;

    info->start_simulation = ft_get_time();
    i = -1;
    while (++i < info->philo_nbr)
        info->philos[i].last_meal = info->start_simulation;
    
    i = -1;
    while (++i < info->philo_nbr)
    {
        if (pthread_create(&info->philos[i].thread_philo, NULL, routine, &info->philos))
            return (1);
    }

}