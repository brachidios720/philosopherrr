/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:46:28 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/08/08 18:17:41 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_print(t_philo *philo, char *s)
{
	t_setting	*set;

	set = philo->set;
	pthread_mutex_lock(&philo->set->print);
	if (set->die != 1 && set->all_hate < set->num_philo)
	{
		printf("\033[38;5;214m%lld\033[0m %d %s", (find_ms()
				- philo->start_philo), philo->id, s);
	}
	pthread_mutex_unlock(&philo->set->print);
}

void	*ft_check_die(void *p)
{
	t_setting	*set;
	int			i;

	set = (t_setting *)p;
	while (set->die != 1)
	{
		i = 0;
		while (i < set->num_philo)
		{
			pthread_mutex_lock(&set->check);
			if ((find_ms() - set->philo[i].last_meal) >= set->t_die)
			{
				pthread_mutex_unlock(&set->check);
				ft_print(&set->philo[i], "\033[0;31mis dead\033[0m\n");
				set->die = 1;
				return (0);
			}
			pthread_mutex_unlock(&set->check);
			i++;
		}
		if (set->how_much != -1 && set->all_hate >= set->num_philo)
			return (0);
	}
	return (0);
}
