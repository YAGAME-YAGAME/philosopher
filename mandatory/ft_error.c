/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:18:58 by yagame            #+#    #+#             */
/*   Updated: 2025/05/28 08:22:44 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    ft_error(const char *message)
{
    if (message)
    {
        write(2, RED"Error: ", 12);
        write(2, message, ft_strlen(message));
        write(2, "\n"RESET, 1);
    }
    exit(1);
}