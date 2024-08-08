/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:10:24 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/08/07 20:16:45 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void ft_eat(t_philo *philo)
{
    t_setting *set;
    set = philo->set;
    pick_forks(philo);
    if (set->die != 1)
    {
        ft_print(philo, "\033[0;32mis eating\033[0m\n");
        if(set->how_much > 0)
        {
            philo->hate++;
            if(philo->hate == set->how_much)
            {
                set->all_hate++;
            }
        }
    }
    philo->last_meal = find_ms();
    ft_usleep(set->t_eat, philo);
    pthread_mutex_unlock(&set->forks[philo->left]);
    pthread_mutex_unlock(&set->forks[philo->right]);
    philo->left_hand = 0;
    philo->right_hand = 0;
}


void *ft_routine(void *p)
{
    t_philo *philo; 
    philo = (t_philo *)p;
    ft_print(philo, "is thinking\n");
     
    while((philo->set->die != 1))
    {
        ft_eat(philo);
        if(philo->hate == philo->set->how_much)
            return(0);
        ft_print(philo, "is sleeping\n");
        ft_usleep(philo->set->t_sleep, philo);
        ft_print(philo, "is thinking\n");
        ft_usleep(1, philo);
    }
    return(0);
}

// int ft_is_dead(t_philo *philo)
// {
//     t_setting *set = philo->set;
       
//     long long cur;
//     cur = find_ms();
//     if((cur - philo->last_meal) >= set->t_die)
//     {
//        ft_print(philo, "\033[0;31mis dead\033[0m\n");
//        set->die = 1;
//        if(set->die == 1)
//         return(1);
//     }
//     return(0);
// }