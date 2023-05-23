/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:44:06 by mfroissa          #+#    #+#             */
/*   Updated: 2023/04/28 20:44:43 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	cleanup_forks(t_data *data, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (cleanup_forks(data, i), 1);
		usleep(100);
		i++;
	}
	return (0);
}

void	attrib_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (i == data->n_philo - 1)
			data->philo[i].right_fork = &data->fork[0];
		else
			data->philo[i].right_fork = &data->fork[i + 1];
		data->philo[i].left_fork = &data->fork[i];
		i++;
	}
}

int	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->writing, NULL))
		return (err_msg("Error while initializing mutex\n", 1));
	if (pthread_mutex_init(&data->xelor, NULL))
		return (pthread_mutex_destroy(&data->writing),
			err_msg("Error while initializing mutex\n", 2));
	if (pthread_mutex_init(&data->ougi, NULL))
		return (pthread_mutex_destroy(&data->xelor),
			pthread_mutex_destroy(&data->writing),
			err_msg("Error while initializing mutex\n", 3));
	if (pthread_mutex_init(&data->sram, NULL))
		return (pthread_mutex_destroy(&data->ougi),
			pthread_mutex_destroy(&data->xelor),
			pthread_mutex_destroy(&data->writing),
			err_msg("Error while initializing mutex\n", 4));
	if (init_forks(data))
		return (pthread_mutex_destroy(&data->ougi),
			pthread_mutex_destroy(&data->sram),
			pthread_mutex_destroy(&data->xelor),
			pthread_mutex_destroy(&data->writing),
			err_msg("Error while initializing mutex\n", 5));
	attrib_forks(data);
	return (0);
}
