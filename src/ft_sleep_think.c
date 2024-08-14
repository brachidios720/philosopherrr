/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_think.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:47:10 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/08/14 17:11:42 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// void	ft_sleep_and_think(t_philo *philo)
// {
// 	ft_print(philo, "is sleeping\n");
// 	ft_usleep(philo->set->t_sleep, philo);

// 	ft_print(philo, "is thinking\n");
// 	ft_usleep(5, philo);
// }

// int	ft_should_continue(t_philo *philo)
// {
// 	int is_dead;
	
// 	is_dead = 0;
// 	pthread_mutex_lock(&philo->set->check);
// 	if (philo->set->die == 1)
// 	{
// 		pthread_mutex_unlock(&philo->set->check);
// 		return (0);
// 	}
// 	pthread_mutex_unlock(&philo->set->check);
// 	pthread_mutex_lock(&philo->set->check);
// 		if (philo->set->die)
// 			is_dead = 1;
// 	pthread_mutex_unlock(&philo->set->check);
// 	return (1);
// }
