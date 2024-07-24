/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:26:06 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/07/24 17:19:13 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <stddef.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct setting_s t_setting;

typedef struct philo_s
{
	struct s_setting *set;
	long 			last_meal; // dernier repas
	int	num_p;
	int				id;	//id du philo 
	int 			left; // gauche
	int 			right; // droite
	int 			left_hand;
	int 			right_hand;
	
} t_philo;

typedef struct setting_s
{
	int num_philo; // nombre de philo
	int t_die; // temps de mort
	int t_eat; // temps de repas
	int t_sleep; // temps de repos
	int how_much; // combien de repas
	int die;
	long long start_time; // lancement du programme
	pthread_t *p; // les threads 
	pthread_mutex_t *forks; // fourchettes
    t_philo *philo; // acces paramettre des philos
	
} t_setting;



// parsing 
void    ft_pars_args(int ac, char **av, t_setting *set);
int     ft_atoi_dif(char *str);
int     ft_isdigit_dif(char *str);
long	find_ms(void);

// initialisation 

void init_philo(t_setting *set);
int init_settings(t_setting *set);
void init_forks(t_setting *set);
void    ft_pick_forks(t_setting *set, t_philo *philo);

// error

void	ft_exit(int i);
void	ft_clear(t_setting *set);
void 	ft_error(int i, t_setting *set);

// routine

void ft_eat(t_philo *philo);
void ft_routine(void *p);
void ft_start(t_setting *set);



