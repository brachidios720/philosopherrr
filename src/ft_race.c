/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_race.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:34:41 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/08/08 18:17:19 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_start(t_setting *set)
{
	int	i;

	i = 0;
	set->start_time = find_ms();
	while (i < set->num_philo)
	{
		set->philo[i].start_philo = find_ms();
		pthread_create(&set->p[i], NULL, ft_routine, &set->philo[i]);
		i++;
	}
	ft_check_die(set);
	i = 0;
	while (i < set->num_philo)
	{
		pthread_join(set->p[i], NULL);
		i++;
	}
}
