#include "../include/philo.h"
void init_forks(t_setting *set)
{
    int i = 0;
    while(i < set->num_philo)
    {
        pthread_mutex_init(&set->forks[i], 0);
        i++;
    }
}
void init_philo(t_setting *set)
{
    int i = 0;
    while(i < set->num_philo)
    {
        set->philo[i].id = i;
        set->philo[i].last_meal = 0;
        set->philo[i].left = i;
        set->philo[i].right = (i + 1) % set->num_philo;
        set->philo[i].left_hand = 0;
        set->philo[i].right_hand = 0;
        // ft_printf("id = %d\n", set->philo[i].id);
        // ft_printf("last_meal = %d\n", set->philo[i].last_meal);
        // ft_printf("left = %d\n", set->philo[i].left);
        // ft_printf("right = %d\n", set->philo[i].right);
        i++;
    }
}

int init_settings(t_setting *set)
{
    set->start_time = find_ms();
    set->die = 0;
    set->forks = malloc(sizeof(pthread_mutex_t) * set->num_philo);
    set->philo = malloc(sizeof(t_philo) * set->num_philo);
    if(!set->forks || !set->philo)
        return(1);
    init_philo(set);
    init_forks(set);
    // ft_printf("%d\n", set->start_time);
    return(0);
}

