/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:10:24 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/07/25 15:44:36 by rcarbonn         ###   ########.fr       */
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
    printf("Philosopher %d is eating\n", philo->id);
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
        printf("philo %d is dead\n", philo->id);
        return(1);
    }
    return(0);
}

void *ft_routine(void *p)
{
    t_philo *philo; 
    philo = (t_philo *)p;
    printf("Philosopher %d is thinking\n", philo->id);
     
    while(ft_is_dead(philo) == 0)
    {
        ft_eat(philo);
        printf("philosopher %d is slepping\n", philo->id);
        ft_usleep(philo->set->t_sleep, philo->set);
        printf("Philosopher %d is thinking\n", philo->id);
    }
    return(NULL);
}
