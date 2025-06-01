/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:20:31 by yagame            #+#    #+#             */
/*   Updated: 2025/06/01 11:05:18 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


static int ft_itol(char *s)
{
    int res;

    res = 0;
    s = is_valid(s);
    res = ft_atoi(s);
    return (res);
}

int    ft_parser(t_info *info, char **av)
{
    info->philo_nbr = ft_itol(av[1]);
    info->time_to_die = ft_itol(av[2]) * 1e3;
    info->time_to_eat = ft_itol(av[3]) * 1e3;
    info->time_to_sleep = ft_itol(av[4]) * 1e3;
    if(av[5])
        info->meal_limit = ft_itol(av[5]) * 1e3;
    else
        info->meal_limit = -1;
        
    if(info->time_to_die < 6e4 || info->time_to_eat < 6e4
        || info->time_to_sleep < 6e4)
            ft_error("timestamps must be mojer than 60ms");
            
    info->end_simulation = 0;
    if(pthread_mutex_init(&info->print_lock, NULL))
        return (1);
    info->philos = malloc(sizeof(t_philos) * info->philo_nbr);
    info->forks = malloc(sizeof(pthread_mutex_t) * info->philo_nbr);
    if(!info->philos || !info->forks)
        return (1);
}
