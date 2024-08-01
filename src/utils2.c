/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:46:28 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/08/01 19:32:03 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    ft_print(t_philo *philo, char *s)
{
    t_setting *set;
    set = philo->set;
    pthread_mutex_lock(&philo->set->print);
    if(set->die != 1 && set->all_hate < set->num_philo) 
    {
        printf("%lld Philosopher %d %s",(find_ms() - philo->set->start_time) ,philo->id, s);
    }
    pthread_mutex_unlock(&philo->set->print);
}