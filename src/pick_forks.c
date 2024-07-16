/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:48:05 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/07/15 21:43:08 by raphaelcarb      ###   ########.fr       */
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
        ft_printf("%d\n", philo->last_meal = find_ms());
        usleep(set->t_eat * 1000);
        pthread_mutex_unlock(&set->forks[philo->left]);
        philo->left_hand = 0;
        ft_printf("Philosopher %d has put down the left fork %d\n", philo->id, philo->left);
        pthread_mutex_unlock(&set->forks[philo->right]);
        philo->right_hand = 0;
        ft_printf("Philosopher %d has put down the right fork %d\n", philo->id, philo->right);
    }
}

