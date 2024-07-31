/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:46:28 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/07/31 16:57:22 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    ft_print(t_philo *philo, char *s)
{
    pthread_mutex_lock(&philo->set->print);
    printf("%lld Philosopher %d %s",(find_ms() - philo->set->start_time) ,philo->id, s);
    pthread_mutex_unlock(&philo->set->print);
}