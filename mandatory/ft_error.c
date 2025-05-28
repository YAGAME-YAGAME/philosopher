/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagame <yagame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:18:58 by yagame            #+#    #+#             */
/*   Updated: 2025/05/26 21:23:07 by yagame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    ft_error(const char *message)
{
    if (message)
    {
        write(2, RED"Error: ", 7);
        write(2, message, ft_strlen(message));
        write(2, "\n", 1);
    }
}