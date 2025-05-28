/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagame <yagame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:20:31 by yagame            #+#    #+#             */
/*   Updated: 2025/05/26 21:26:35 by yagame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


static int invalid_args(char **av)
{
    int i;

    i = 0;
    while(av[i])
    {
        if(!ft_check_is_ligit(av[i]))
            return (0);
    }
}

ft_parser(t_philo_info *info, char **av)
{
    if(!invalid_args(av))
        ft_error("arguments not valid");
    
}