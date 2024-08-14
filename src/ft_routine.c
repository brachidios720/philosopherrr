/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:10:24 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/08/14 17:12:03 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eat(t_philo *philo)
{
	t_setting	*set;
	int is_dead;

	set = philo->set;
	is_dead = 0;
	pick_forks(philo);
	pthread_mutex_lock(&set->check);
	philo->last_meal = find_ms();
	pthread_mutex_unlock(&set->check);
	if (!is_dead)
	{
		ft_print(philo, "\033[0;32mis eating\033[0m\n");
		if (set->how_much > 0)
		{
			philo->hate++;
			if (philo->hate == set->how_much)
			{
				set->all_hate++;
			}
		}
		pthread_mutex_lock(&set->check);
		if (philo->set->die)
			is_dead = 1;
		pthread_mutex_unlock(&set->check);

	}
	ft_usleep(set->t_eat, philo);
	pthread_mutex_unlock(&set->forks[philo->left]);
	pthread_mutex_unlock(&set->forks[philo->right]);
	philo->left_hand = 0;
	philo->right_hand = 0;
}

void	*ft_routine(void *p)
{
	t_philo	*philo;
	int is_dead;

	is_dead = 0;
	philo = (t_philo *)p;
	ft_print(philo, "is thinking\n");
	if (philo->id % 2 == 1)
		ft_usleep(60, philo);
	while (philo->set->die != 1)
	{
		ft_eat(philo);
		if (philo->hate == philo->set->how_much)
			return(0);
		ft_print(philo, "is sleeping\n");
		ft_usleep(philo->set->t_sleep, philo);
		ft_print(philo, "is thinking\n");
		ft_usleep(5, philo);
		//ft_sleep_and_think(philo);
		// pthread_mutex_lock(&philo->set->check);
		// if (philo->set->die)
		// 	is_dead = 1;
		// pthread_mutex_unlock(&philo->set->check);
	}
	return (0);
}
