/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:48:05 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/07/29 15:20:53 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    ft_pick_forks(t_philo *philo)
{
    t_setting *set;

    set = philo->set;
    if(ft_is_dead(philo) != 1)
    {
        if(!pthread_mutex_lock(&philo->set->forks[philo->left]))
        ft_print(philo, "has taken the left fork\n");
        philo->left_hand = 1;
        if(!pthread_mutex_lock(&philo->set->forks[philo->right]) && philo->right_hand)
        ft_print(philo, "has taken the right fork\n");
        philo->right_hand = 1;
    }
}

void    ft_pick_fork(t_philo *philo)
{
    t_setting *set;

    set = philo->set;
    if(ft_is_dead(philo) != 1)
    {
        if(!pthread_mutex_lock(&philo->set->forks[philo->right]))
        ft_print(philo, "has taken the right fork\n");
        philo->left_hand = 1;
        if(!pthread_mutex_lock(&philo->set->forks[philo->left]) && philo->left_hand)
        ft_print(philo, "has taken the left fork\n");
        philo->right_hand = 1;
    }
}

void    pick_forks(t_philo *philo)
{
    if(philo->id % 2 == 0)
        ft_pick_fork(philo);
    else 
        ft_pick_forks(philo);
}

