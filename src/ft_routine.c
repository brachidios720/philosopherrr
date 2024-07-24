/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:10:24 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/07/24 19:20:00 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void ft_eat(t_philo *philo)
{
    t_setting *set;
    
    set = philo->set;
    ft_pick_forks(set, philo);
    usleep(set->t_eat * 100);
    philo->last_meal = philo->last_meal + set->t_die;
    ft_printf("Philosopher %d is eating\n", philo->id);
    pthread_mutex_unlock(&set->forks[philo->left]);
    pthread_mutex_unlock(&set->forks[philo->right]);
    philo->left_hand = 0;
    philo->right_hand = 0;
}

void *ft_routine(void *p)
{
    t_philo *philo; 
    philo = (t_philo *)p;
    ft_printf("Philosopher %d is thinking\n", philo->id);  
    while(philo->set->die != 1)
    {
        ft_eat(philo);
        ft_printf("philosopher is slepping\n", philo->id);
        usleep(philo->set->t_sleep * 1000);
        ft_printf("Philosopher %d is thinking\n", philo->id);
    }
    return(0);
}
