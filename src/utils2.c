/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:46:28 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/07/29 15:03:45 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    ft_print(t_philo *philo, char *s)
{
    t_setting *set;
    
    set = philo->set;
    pthread_mutex_lock(&philo->set->print);
    if(ft_is_dead(philo) != 1)
        printf("philo %d %s\n",philo->id, s);
    else 
        printf("philo %d %s\n", philo->id, s);
    usleep(200);
    pthread_mutex_unlock(&philo->set->print);
}