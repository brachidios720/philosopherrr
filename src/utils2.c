/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:46:28 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/08/06 16:09:29 by raphaelcarb      ###   ########.fr       */
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
        printf("%lld Philosopher %d %s",(find_ms() - philo->start_philo) ,philo->id, s);
    }
    pthread_mutex_unlock(&philo->set->print);
}

void    *ft_check_die(void *p)
{
    t_setting *set;
    int i = 0;

    set = (t_setting *)p;

    while(set->die != 1)
    {
        while(i < set->num_philo)
        {
            long long cur = find_ms();
            if((cur - set->philo[i].last_meal) >= set->t_die)
            {
             ft_print(&set->philo[i], "\033[0;31mis dead\033[0m\n");
             set->die = 1;
             return(0);
            }
            i++;
        }
        i=0;
    }
    return(0);
}

