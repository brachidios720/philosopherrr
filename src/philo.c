#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_setting set;
	t_philo philo;

	if (ac != 5 && ac != 6)
		ft_exit(1);
	ft_pars_args(ac, av, &set);
	if(init_settings(&set) == 1)
		ft_error(1, &set);
	ft_pick_forks(&set, &philo);
	// ft_printf("test\n");
	// ft_printf("%d\n", set.num_philo);
	ft_clear(&set);
}
