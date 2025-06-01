/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:22:06 by yagame            #+#    #+#             */
/*   Updated: 2025/06/01 12:50:21 by otzarwal         ###   ########.fr       */
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
    if (argc < 5 || argc > 6)
        return ( write(2, RED"Error: Invalid number of arguments\n", 36), 1);

    if (ft_parser(&info, argv) == 1)
        ft_error("somethig wrrongs");
    if(ft_init_info(&info) == 1)
        ft_error("somethig wrrongs");
        
    start_simulation(&info);
    monitoring(&info);
    return (0);
}