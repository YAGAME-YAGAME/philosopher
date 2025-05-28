/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagame <yagame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:20:23 by yagame            #+#    #+#             */
/*   Updated: 2025/05/27 18:58:29 by yagame           ###   ########.fr       */
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

/* ANSI Color Codes */
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"


typedef pthread_mutex_t t_mutex;
typedef struct s_philo_info t_philo_info;

typedef struct s_philos
{
    int                 id;
    long                meal_counter;
    long                last_meal_time;
    t_mutex             *left_fork;
    t_mutex             *right_fork;
    pthread_t           *thread_id;
    t_philo_info        *info;
    
    
} t_philos;

typedef struct s_philo_info
{
    long                 philo_nbr;
    long                 time_to_die;
    long                 time_to_eat;
    long                 time_to_sleep;
    long                 meal_limit;
    long                 start_simulation;
    long                 end_simulation;
    pthread_mutex_t      *forks;
    pthread_mutex_t      print_mutex;
    t_philos             *philos;
} t_philo_info;



// for errors 
void                    ft_error(const char *message);
void                    ft_parser(t_philo_info *info, char **av);

# endif