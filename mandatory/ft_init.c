/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagame <yagame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:10:54 by otzarwal          #+#    #+#             */
/*   Updated: 2025/06/01 18:31:01 by yagame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


static int init_philos(t_info *info)
{
    int i;

    i = -1;
    while(++i < info->philo_nbr)
    {
        info->philos[i].id = i + 1;
        info->philos[i].last_meal = 0;
        info->philos[i].right_fork = &info->forks[i];
        info->philos[i].left_fork = &info->forks[(i + 1) % info->philo_nbr];
        info->philos[i].info = info;
    }
    return (0);
}

static int init_forks(t_info *info)
{
    int i;

    i = -1;
    while(++i < info->philo_nbr)
    {
        if(pthread_mutex_init(&info->forks[i], NULL))
            return 1;
    }
    return (0);
}

int     ft_init_info(t_info *info)
{
    if(init_philos(info) == 1)
        return(1);
    if (init_forks(info) == 1)
        return (1);
    return (0);
}