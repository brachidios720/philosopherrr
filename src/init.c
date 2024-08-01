/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:05:54 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/08/01 19:02:21 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
void init_forks(t_setting *set)
{
    int i = 0;
    while(i < set->num_philo)
    {
        pthread_mutex_init(&set->forks[i], NULL);
        i++;
    }
}
void init_philo(t_setting *set)
{
    int i = -1;
    while(++i < set->num_philo)
    {
        set->philo[i].id = i;
        set->philo[i].last_meal = find_ms();
        set->philo[i].left = i;
        set->philo[i].right = (i + 1) % set->num_philo;
        set->philo[i].num_p = i;
        set->philo[i].set = set;
    }
}

int init_settings(t_setting *set)
{
    set->start_time = find_ms();
    set->die = 0;
    set->all_hate = 0;
    set->hate = 0;
    pthread_mutex_init(&set->print, NULL);
    set->forks = malloc(sizeof(pthread_mutex_t) * set->num_philo);
    set->p = malloc(sizeof(pthread_t) * set->num_philo);
    set->philo = malloc(sizeof(t_philo) * set->num_philo);
    if(!set->forks || !set->philo || !set->p)
        return(1);
    init_philo(set);
    init_forks(set);
    return(0);
}

