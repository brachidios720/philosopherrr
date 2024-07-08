/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:48:05 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/07/08 16:56:50 by raphaelcarb      ###   ########.fr       */
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

// #include "philo.h"

// void    ft_pick_forks(t_setting *set, t_philo *philo)
// {
//     // Vérifie si le philosophe est encore en vie
//     if (set->die != 1)
//     {
//         // Le philosophe essaie de prendre la fourchette de gauche
//         pthread_mutex_lock(&philo->set->forks[philo->left]);
//         // Ajout d'un message pour savoir que la fourchette de gauche est prise
//         printf("Philosopher %d has taken the left fork %d\n", philo->id, philo->left);

//         // Le philosophe essaie de prendre la fourchette de droite
//         pthread_mutex_lock(&philo->set->forks[philo->right]);
//         // Ajout d'un message pour savoir que la fourchette de droite est prise
//         printf("Philosopher %d has taken the right fork %d\n", philo->id, philo->right);

//         // Si les deux fourchettes sont prises, le philosophe peut manger
//         // Logique pour manger, par exemple :
//         philo->last_meal = get_time();
//         printf("Philosopher %d is eating\n", philo->id);

//         // Simule le temps pour manger
//         usleep(philo->set->time_to_eat * 1000);

//         // Le philosophe a fini de manger et repose les fourchettes
//         pthread_mutex_unlock(&philo->set->forks[philo->right]);
//         printf("Philosopher %d has put down the right fork %d\n", philo->id, philo->right);

//         pthread_mutex_unlock(&philo->set->forks[philo->left]);
//         printf("Philosopher %d has put down the left fork %d\n", philo->id, philo->left);
//     }
// }
