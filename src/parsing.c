#include "../include/philo.h"



int	ft_isdigit_dif(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
            return(0);
        else
            return(1);
        i++;
    }
    return(1);
}

void ft_pars_args(int ac, char **av, t_setting *set)
{
    int  i = 1;
    while(i < ac)
    {
        if(ft_isdigit_dif(av[i]) == 1)
            ft_exit(1);
        i++;
    }
    set->num_philo = ft_atoi_dif(av[1]);
    set->t_die  = ft_atoi_dif(av[2]);
    set->t_sleep = ft_atoi_dif(av[3]);
    set->t_eat = ft_atoi_dif(av[4]);
    if(ac == 6)
        set->how_much=ft_atoi_dif(av[5]);
}