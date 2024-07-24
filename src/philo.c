#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_setting set;

	if (ac != 5 && ac != 6)
		ft_exit(1);
	ft_pars_args(ac, av, &set);
	if(init_settings(&set) == 1)
		ft_error(1, &set);
	ft_start(&set);
	ft_clear(&set);
}
