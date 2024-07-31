/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:48:05 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/07/31 16:07:25 by rcarbonn         ###   ########.fr       */
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
        if(!pthread_mutex_lock(&philo->set->forks[philo->right]))
        ft_print(philo, "has taken the right fork\n");
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
        if(!pthread_mutex_lock(&philo->set->forks[philo->left]))
        ft_print(philo, "has taken the left fork\n");
    }
}

void    pick_forks(t_philo *philo)
{
    if(philo->id % 2 == 0)
        ft_pick_fork(philo);
    else 
        ft_pick_forks(philo);
}

