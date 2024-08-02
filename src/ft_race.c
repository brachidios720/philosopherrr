/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_race.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:34:41 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/08/02 17:01:40 by rcarbonn         ###   ########.fr       */
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
    pthread_create(set->check, NULL, ft_check_die, NULL);
    i = 0;
    while (i < set->num_philo)
    {
        pthread_join(set->p[i], NULL);
        i++;
    }
}

