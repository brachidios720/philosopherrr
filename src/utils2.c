/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:46:28 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/08/06 12:49:18 by raphaelcarb      ###   ########.fr       */
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

void    *ft_check_die(void *p)
{
    t_setting *set;
    t_philo *philo;

    while(set->die != 1)
    {
        int cur = find_ms();
        if((cur - philo->last_meal) >= set->t_die)
        {
            set->die = 1;
        }
    }
}

