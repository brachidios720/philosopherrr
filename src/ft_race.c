/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_race.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:34:41 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/07/31 18:24:29 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void ft_start(t_setting *set)
{
    int i;
    i = 0;
    
    while(i < set->num_philo)
    {
        pthread_create(&set->p[i], NULL, ft_routine, &set->philo[i]);
        i++;
    }
    i = 0;
    while (i < set->num_philo)
    {
        pthread_join(set->p[i], NULL);
        i++;
    }

}


// void ft_start(t_setting *set)
// {
//     int i;

//     i = 0;
//     while (i < set->num_philo)
//     {
//         if (pthread_create(&set->p[i], NULL, ft_routine, &set->philo[i]) != 0)
//         {
//             // Gérer l'erreur si pthread_create échoue
//             printf("Erreur lors de la création du thread %d\n", i);
//             exit(EXIT_FAILURE);
//         }
//         i++;
//     }
//     i = 0;
//     while (i < set->num_philo)
//     {
//         if (pthread_join(set->p[i], NULL) != 0)
//         {
//             // Gérer l'erreur si pthread_join échoue
//             printf("Erreur lors de la jointure du thread %d\n", i);
//             exit(EXIT_FAILURE);
//         }
//         i++;
//     }
// }
