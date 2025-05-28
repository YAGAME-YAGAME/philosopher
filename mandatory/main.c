/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagame <yagame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:22:06 by yagame            #+#    #+#             */
/*   Updated: 2025/05/26 21:18:33 by yagame           ###   ########.fr       */
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
    t_philo_info info;
    if (argc < 5 || argc > 6)
    {
        write(2, RED"Error: Invalid number of arguments\n", 36);
        return (1);
    }
    // ⁉️ parse arguments
    
    if(!ft_parser(&info, argv))
    {
        write(2, RED"Error: Invalid arguments\n", 25);
        return (1);
    }

    
    // ⁉️ int struct philo_args
    // ⁉️ start semulation
    
    
    
 
    return (0);
}