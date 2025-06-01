/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagame <yagame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:46:53 by otzarwal          #+#    #+#             */
/*   Updated: 2025/06/01 18:51:13 by yagame           ###   ########.fr       */
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
    if(philo->id % 2 == 0)
        usleep(philo->info->time_to_eat / 2);
    while (true)
    {
        pthread_mutex_lock(philo->left_fork);
        printf("%sPhilosopher %d has taken left fork%s\n", CYAN, philo->id, RESET);
        pthread_mutex_lock(philo->right_fork);
        printf("%sPhilosopher %d has taken right fork%s\n", CYAN, philo->id, RESET);
        printf("%sPhilosopher %d is eating%s\n", GREEN, philo->id, RESET);
        while(1)
        {
            usleep(philo->info->time_to_eat);
            break;
        }
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
    }
    return (NULL);
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
        if (pthread_create(&info->philos[i].thread_philo, NULL, routine, &info->philos[i]))
            return (1);
    }
    return (0);
}