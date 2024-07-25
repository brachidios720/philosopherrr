/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:10:24 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/07/25 18:01:15 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void ft_eat(t_philo *philo)
{
    t_setting *set;
    
    set = philo->set;
    pick_forks(set, philo);
    ft_usleep(set->t_eat, philo->set);
    philo->last_meal = find_ms();
    ft_print(philo, "is eating");
    set->hate++;
    pthread_mutex_unlock(&set->forks[philo->left]);
    pthread_mutex_unlock(&set->forks[philo->right]);
    philo->left_hand = 0;
    philo->right_hand = 0;
}
int ft_is_dead(t_philo *philo)
{
    t_setting *set = NULL;
       
    long long cur;
    cur = find_ms();
    if((philo->last_meal - cur) > set->t_die)
    {
        ft_print(philo, "is dead");
        return(1);
    }
    else
    {
        printf("%lld\n", cur);
        printf("%lld\n", philo->last_meal);
        return(0);
    }
}

void *ft_routine(void *p)
{
    t_philo *philo; 
    philo = (t_philo *)p;
    ft_print(philo, "is thinking\n");
     
     
    if(philo->id % 2 == 1)
        ft_usleep(60, philo->set);
    while(philo->set->die != 1)
    {
        ft_eat(philo);
        ft_print(philo, "is sleeping");
        ft_usleep(philo->set->t_sleep, philo->set);
        ft_print(philo, "is thinking\n");
    }
    return(NULL);
}
