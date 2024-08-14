/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:48:05 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/08/14 15:44:08 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_pick_forks(t_philo *philo)
{
	t_setting	*set;
	int is_dead;

	set = philo->set;
	is_dead = 0;
	if (!is_dead)
	{
		if (!pthread_mutex_lock(&philo->set->forks[philo->left]))
		{
			philo->left_hand = 1;
			ft_print(philo, "has taken a fork\n");
		}
		if (!pthread_mutex_lock(&philo->set->forks[philo->right])
			&& philo->left_hand)
		{
			philo->right_hand = 1;
			ft_print(philo, "has taken a fork\n");
		}
		pthread_mutex_lock(&philo->set->check);
		if (philo->set->die)
			is_dead = 1;
		pthread_mutex_unlock(&philo->set->check);
	}
}

void	ft_pick_fork(t_philo *philo)
{
	t_setting	*set;
	int is_dead;

	set = philo->set;
	is_dead = 0;
	if (!is_dead)
	{
		if (!pthread_mutex_lock(&philo->set->forks[philo->right]))
		{
			philo->right_hand = 1;
			ft_print(philo, "has taken a fork\n");
		}
		if (!pthread_mutex_lock(&philo->set->forks[philo->left])
			&& philo->right_hand)
		{
			philo->left_hand = 1;
			ft_print(philo, "has taken a fork\n");
		}
		pthread_mutex_lock(&philo->set->check);
		if (philo->set->die)
			is_dead = 1;
		pthread_mutex_unlock(&philo->set->check);
	}
}

void	pick_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
		ft_pick_forks(philo);
	else
		ft_pick_fork(philo);
}
