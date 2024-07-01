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
void init_philo(t_setting *set, t_philo *philo)
{
    int i = 0;
    while(i < set->num_philo)
    {
        set->philo[i].id = i;
        set->philo[i].last_meal = 0;
        set->philo[i].left = i;
        set->philo[i].right = (i + 1) % set->num_philo;
        i++;
        ft_printf("id = %d\n", set->philo[i].id);
        ft_printf("last_meal = %d\n", set->philo[i].last_meal);
        ft_printf("left = %d\n", set->philo[i].left);
        ft_printf("right = %d\n", philo->right);
    }
}

int init_settings(t_setting *set)
{
    set->start_time = find_ms();
    set->forks = malloc(sizeof(pthread_mutex_t) * set->num_philo);
    set->philo = malloc(sizeof(t_philo) * set->num_philo);
    if(!set->forks || !set->philo)
        return(1);
    init_philo(set);
    init_forks(set);
    ft_printf("%d\n", set->start_time);
    return(0);
}



// typedef struct philo_s
// {
// 	long last_meal; // dernier repas
// 	int id; // identifiant du philo
	
// } t_philo;

// typedef struct setting_s
// {
// 	int num_philo; // nombre de philo
// 	int t_die; // temps de mort
// 	int t_eat; // temps de repas
// 	int t_sleep; // temps de repos
// 	int how_much; // combien de repas
// 	int start_time; // lancement du programme
// 	pthread_t num; // les threads 
// 	pthread_mutex_t *forks; // fourchettes
//     t_philo *philo; // acces paramettre des philos
	
// } t_setting;
