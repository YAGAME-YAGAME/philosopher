/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagame <yagame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:22:06 by yagame            #+#    #+#             */
/*   Updated: 2025/06/01 18:26:10 by yagame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"


//          ./philo  5   800   200  200   7
//                   |    |    |     |    |
//                   |    |    |     |    |
//                   |    |    |     |    |__>  number_of_times_each_philosopher_must_eat
//                   |    |    |     |
//                   |    |    |     |__>  time_to_eat
//                   |    |    |
//                   |    |    |__>  time_to_eat
//                   |    |
//                   |    |
//                   |    |__>  time_to_die
//                   |
//                   |
//                   |__>  number_of_philosophers
//                   


int main(int argc, char **argv)
{
    t_info info;
    int i;
    
    if (argc < 5 || argc > 6)
        return( write(2, RED"Error: Invalid number of arguments\n", 36), 1);
    if (ft_parser(&info, argv) == 1)
        ft_error("somethig wrrongs");
        
        
    if(ft_init_info(&info) == 1)
        ft_error("somethig wrrongs");
        
        
        
    start_simulation(&info);
    // monitoring(&info);
    i = -1;
    while (++i < info.philo_nbr)
        pthread_join((void *)info.philos[i].thread_philo, NULL);
    
    return (0);
}