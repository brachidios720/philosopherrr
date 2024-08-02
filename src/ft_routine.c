/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:10:24 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/08/02 16:50:15 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void ft_eat(t_philo *philo)
{
    t_setting *set;
    set = philo->set;
    pick_forks(philo);
    if (ft_is_dead(philo) == 0)
    {
        ft_print(philo, "\033[0;32mis eating\033[0m\n");
        philo->last_meal = find_ms();
        if(set->how_much > 0)
        {
            philo->hate++;
            if(philo->hate == set->how_much)
            {
                set->all_hate++;
            }
        }
        ft_usleep(set->t_eat, philo);
    }
    pthread_mutex_unlock(&set->forks[philo->right]);
    pthread_mutex_unlock(&set->forks[philo->left]);
}
int ft_is_dead(t_philo *philo)
{
    t_setting *set = philo->set;
       
    long long cur;
    cur = find_ms();
    if((cur - philo->last_meal) >= set->t_die)
    {
       ft_print(philo, "\033[0;31mis dead\033[0m\n");
       set->die = 1;
       if(set->die == 1)
        exit(0);
       return(1);
    }
    return(0);
}

void *ft_routine(void *p)
{
    t_philo *philo; 
    philo = (t_philo *)p;
    ft_print(philo, "is thinking\n");
     
    if(philo->id % 2 == 1)
        ft_usleep(60, philo);
    while((ft_is_dead(philo) != 1))
    {
        ft_eat(philo);
        if(philo->hate == philo->set->how_much)
            return(0);
        ft_print(philo, "is sleeping\n");
        ft_usleep(philo->set->t_sleep, philo);
        ft_print(philo, "is thinking\n");
    }
    return(0);
}
