/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 08:02:22 by otzarwal          #+#    #+#             */
/*   Updated: 2025/05/28 09:58:16 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"


static int skip(char c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}
static int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

char *is_valid(char *s)
{
    int len;
    char *on_nbr;

    
    on_nbr = NULL;
    len = 0;
    while (skip(*s))
        s++;
    if(*s == '-')
        ft_error("we seport just positive number");
    else if(*s == '+')
        s++;
    if(!is_digit(*s))
        ft_error("the input is not digit");
    on_nbr = s;
    while (is_digit(*s++))
        len++;
    if (len > 10)
        ft_error("the number is to big"); 
    return (on_nbr);
}

int ft_atoi(char *s)
{
    long res;
    
    res = 0;
    while(is_digit(*s))
    {
        res = (res * 10) + (*s - '0');
        if (res > INT_MAX)
            ft_error("the number is to big");
        s++;
    }
    return (res);
}

int ft_strlen(const char *s)
{
    int i;

    i = 0;
    while(s[i])
        i++;
    return (i);
}
