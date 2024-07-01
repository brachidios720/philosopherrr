/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:02:20 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/06/26 15:33:15 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


int		ft_atoi_dif(char *str)
{
	int i;
	int res;

	res = 0;
	i = 0;
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if(res > 2147483647 || res < -2147483647)
		ft_exit(1);
	return(res);
}

long	find_ms(void)
{
	struct timeval current_time;
	long long ms;
	
	gettimeofday(&current_time, 0);
	ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return(ms);
}

void	ft_clear(t_setting *set)
{
	free(set->forks);
	free(set->philo);
}

void ft_exit(int i)
{
	if(i == 1)
		ft_printf("ERROR\n");
	exit(0);
}