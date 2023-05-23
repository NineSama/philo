/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:09:26 by mfroissa          #+#    #+#             */
/*   Updated: 2023/04/28 20:51:00 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	create_time(t_data *data, int ac, char **av)
{
	(void)ac;
	data->time.time_to_die = ft_atoi(av[2]);
	data->time.time_to_eat = ft_atoi(av[3]);
	data->time.time_to_sleep = ft_atoi(av[4]);
}

int	create_data(t_data *data, int ac, char **av)
{
	data->n_philo = ft_atoi(av[1]);
	if (ac == 6)
		data->n_meals = ft_atoi(av[5]);
	else
		data->n_meals = -1;
	data->un_mort = 0;
	data->time_start = 0;
	create_time(data, ac, av);
	init_mutex(data);
	init_philo(data);
	return (0);
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philo[i].id = i;
		data->philo[i].meals = 0;
		data->philo[i].thread = 0;
		data->philo[i].until = get_time();
		data->philo[i].data_save = data;
		i++;
	}
}
