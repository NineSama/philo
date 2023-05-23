/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:32:11 by mfroissa          #+#    #+#             */
/*   Updated: 2023/05/10 19:40:16 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	one(t_data *data)
{
	if (pthread_create(&data->philo[0].thread, NULL,
			&one_routine, (void *)&data->philo[0]))
		return (err_msg("Error while creating thread\n", 1));
	return (join_threads(data));
}

int	count_meals(t_data *data, int i)
{
	pthread_mutex_lock(&data->ougi);
	if (data->philo[i].meals < data->n_meals)
		return (pthread_mutex_unlock(&data->ougi), 1);
	pthread_mutex_unlock(&data->ougi);
	return (0);
}

int	is_muerte(t_data *data, int *i)
{
	long long	time;

	if (*i == data->n_philo)
		*i = 0;
	pthread_mutex_lock(&data->xelor);
	time = real_time(data->philo[*i].until);
	pthread_mutex_unlock(&data->xelor);
	if (time > data->time.time_to_die)
	{
		print_act(data, &data->philo[*i], "dead");
		pthread_mutex_lock(&data->sram);
		data->un_mort = 1;
		pthread_mutex_unlock(&data->sram);
		return (1);
	}
	ft_usleep(data, 1);
	(*i)++;
	return (0);
}

int	check(t_data *data)
{
	pthread_mutex_lock(&data->sram);
	if (data->un_mort)
		return (pthread_mutex_unlock(&data->sram), 1);
	pthread_mutex_unlock(&data->sram);
	return (0);
}
