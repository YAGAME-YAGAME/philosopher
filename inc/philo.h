/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagame <yagame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:20:23 by yagame            #+#    #+#             */
/*   Updated: 2025/06/01 18:37:32 by yagame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# include <stdio.h>

/* ANSI Color Codes */
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"


typedef pthread_mutex_t t_mutex;
typedef struct s_info t_info;

typedef struct s_philos
{
    int                 id;
    long                meal_counter;
    long                last_meal;
    t_mutex             *left_fork;
    t_mutex             *right_fork;
    pthread_t           thread_philo;
    t_info              *info;
    
    
} t_philos;

typedef struct s_info
{
    long                 philo_nbr;
    long                 time_to_die;
    long                 time_to_eat;
    long                 time_to_sleep;
    long                 meal_limit;
    long                 start_simulation;
    long                 end_simulation;
    t_mutex              *forks;
    t_mutex              print_lock;
    t_philos             *philos;
} t_info;

// utils
int                     ft_atoi(char *s);
char                    *is_valid(char *s);
int                     ft_strlen(const char *s);

// 
int                     ft_parser(t_info *info, char **av);
int                     start_simulation(t_info *info);
int                     ft_init_info(t_info *info);

// for errors 
void                    ft_error(const char *message);

# endif