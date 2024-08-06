/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_race.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:34:41 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/08/06 12:50:49 by raphaelcarb      ###   ########.fr       */
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
    ft_check_die();
    i = 0;
    while (i < set->num_philo)
    {
        pthread_join(set->p[i], NULL);
        i++;
    }
}

