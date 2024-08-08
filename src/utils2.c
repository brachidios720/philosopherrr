/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:46:28 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/08/08 15:03:48 by raphaelcarb      ###   ########.fr       */
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
        printf("\033[38;5;214m%lld\033[0m %d %s",(find_ms() - philo->start_philo) ,philo->id, s);
    }
    pthread_mutex_unlock(&philo->set->print);
}

void    *ft_check_die(void *p)
{
    t_setting *set;
    
    set = (t_setting *)p;

    while(set->die != 1)
    {
        int i = 0;
        while(i < set->num_philo)
        {
            if((find_ms() - set->philo[i].last_meal) >= set->t_die)
            {
                ft_print(&set->philo[i], "\033[0;31mis dead\033[0m\n");
                set->die = 1;
                return(0);
            }
            i++;
        }
        if (set->how_much != -1 && set->all_hate >= set->num_philo)
            return (0);
    }
    return(0);
}

void	ft_declaredeath(t_setting *set, int i )
{
	set->die = 1;
	ft_print(&set->philo[i], "\033[0;31mis dead\033[0m\n");
}

// void    *ft_check_die(void *p)
// {
//     int			i;
// 	long		time;
// 	t_setting		*set;

// 	set = (t_setting *)p;
// 	while (set->die != 1)
// 	{
// 		if (set->all_hate == set->num_philo)
// 			return (0);
// 		if (set->die != -1)
// 		{
// 			i = -1;
// 			time = find_ms();
// 			while (i++, i < set->num_philo)
// 			{
//                 //printf("lastmeal = %lld, find_ms = %ld, res = %lld\n", set->philo[i].last_meal, find_ms(), (find_ms() - set->philo[i].last_meal));
// 				if (time > set->philo[i].last_meal && set->philo[i].last_meal != set->start_time)
// 				{
// 					ft_declaredeath(set, i);
// 					return (0);
// 				}
// 			}
// 		}
// 	}
// 	return (0);
// }

//&& set->start_time != set->philo[i].last_meal


// void    *ft_check_die(void *p)
// {
//     t_setting *set;
    
//     set = (t_setting *)p;

//     while(set->die != 1)
//     {
//         int i = 0;
//         while(i < set->num_philo)
//         {
//             long cur = find_ms();
//             if((cur - set->philo[i].last_meal) >= set->t_die && set->philo[i].start_philo != set->philo[i].last_meal)
//             {
//                 printf("test !!!!!!!!!\n");
//                 ft_print(&set->philo[i], "\033[0;31mis dead\033[0m\n");
//                 set->die = 1;
//                 return(0);
//             }
//             i++;
//         }
//         if (set->how_much != -1 && set->all_hate >= set->num_philo)
//             return (0);
        
//         usleep(100);
//     }
//     return(0);
// }
