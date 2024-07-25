/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:48:05 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/07/25 15:49:06 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    ft_pick_forks(t_setting *set, t_philo *philo)
{
    if(set->die != 1)
    {
        if(!pthread_mutex_lock(&set->forks[philo->left]))
        ft_printf("Philosopher %d has taken the left fork %d\n", philo->id, philo->left);
        philo->left_hand = 1;
        if(!pthread_mutex_lock(&set->forks[philo->right]))
        ft_printf("Philosopher %d has taken the right fork %d\n", philo->id, philo->right);
        philo->right_hand = 1;
    }
}

void    ft_pick_fork(t_setting *set, t_philo *philo)
{
    if(set->die != 1)
    {
        if(!pthread_mutex_lock(&set->forks[philo->right]))
        ft_printf("Philosopher %d has taken the right fork %d\n", philo->id, philo->left);
        philo->left_hand = 1;
        if(!pthread_mutex_lock(&set->forks[philo->left]))
        ft_printf("Philosopher %d has taken the left fork %d\n", philo->id, philo->right);
        philo->right_hand = 1;
    }
}

void    pick_forks(t_setting *set, t_philo *philo)
{
    if(philo->id % 2 == 1)
        ft_pick_fork(set, philo);
    else 
        ft_pick_forks(set, philo);
}

