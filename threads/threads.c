/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:41:17 by mfroissa          #+#    #+#             */
/*   Updated: 2023/04/28 20:36:15 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	data->time_start = get_time();
	if (pthread_create(&data->dead, NULL, &dead_routine, (void *)data))
		return (err_msg("Error while creating thread\n", 1));
	if (data->n_philo == 1)
		return (one(data));
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL,
				&start_routine, (void *)&data->philo[i]))
			return (err_msg("Error while creating thread\n", 2));
		i += 2;
		if (i >= data->n_philo && i % 2 == 0)
		{
			i = 1;
			if (data->time.time_to_eat < data->time.time_to_die)
				ft_usleep(data, data->time.time_to_eat);
			else
				ft_usleep(data, data->time.time_to_die / 2);
		}
	}
	return (join_threads(data));
}

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_join(data->dead, NULL))
		return (err_msg("Error while joining thread\n", 3));
	if (data->n_philo == 1)
	{
		if (pthread_join(data->philo[0].thread, NULL))
			return (err_msg("Error while joining thread\n", 4));
	}
	else
	{
		while (i < data->n_philo)
		{
			if (pthread_join(data->philo[i].thread, NULL))
				return (err_msg("Error while joining thread\n", 4));
			i++;
		}
	}
	return (0);
}
