/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:02:20 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/08/07 17:26:40 by raphaelcarb      ###   ########.fr       */
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
		ft_exit(0);
	return(res);
}

long	find_ms(void)
{
	struct timeval current_time;
	long long ms;
	
	gettimeofday(&current_time, NULL);
	ms = ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	return(ms);
}

void	ft_clear(t_setting *set)
{
    int i;
	i = 0;
    
    while (i < set->num_philo)
    {
        pthread_mutex_destroy(&set->forks[i]);
		i++; 
    }
    pthread_mutex_destroy(&set->print);
    free(set->forks);
    free(set->philo);
    free(set->p);
}

void ft_exit(int i)
{
	if(i == 1)
		ft_printf("ERROR\n");
	if(i == 2)
		ft_printf("wrong number of philo\n");
	exit(0);
}

void ft_usleep(int n,t_philo *philo)
{
	long long start;
	long long now;
	start = find_ms();
	while(philo->set->die != 1)
	{
		now = find_ms();
		if((now - start) >= (long)n)
			break;
		usleep(10);
	}
}