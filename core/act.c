/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:43:12 by mfroissa          #+#    #+#             */
/*   Updated: 2023/04/28 20:51:02 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	is_eating(t_data *data, t_philo *philo)
{
	if (print_act(data, philo, "eat"))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	pthread_mutex_lock(&data->xelor);
	philo->until = get_time();
	pthread_mutex_unlock(&data->xelor);
	ft_usleep(data, data->time.time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&data->ougi);
	philo->meals++;
	pthread_mutex_unlock(&data->ougi);
	return (0);
}

int	is_forking(t_data *data, t_philo *philo)
{
	if (philo->id == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		if (print_act(data, philo, "fork"))
			return (pthread_mutex_unlock(philo->right_fork), 1);
		pthread_mutex_lock(philo->left_fork);
		if (print_act(data, philo, "fork"))
			return (pthread_mutex_unlock(philo->right_fork),
				pthread_mutex_unlock(philo->left_fork), 1);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		if (print_act(data, philo, "fork"))
			return (pthread_mutex_unlock(philo->left_fork), 1);
		pthread_mutex_lock(philo->right_fork);
		if (print_act(data, philo, "fork"))
			return (pthread_mutex_unlock(philo->left_fork),
				pthread_mutex_unlock(philo->right_fork), 1);
	}
	return (is_eating(data, philo));
}

int	is_sleeping(t_data *data, t_philo *philo)
{
	if (print_act(data, philo, "sleep"))
		return (1);
	ft_usleep(data, data->time.time_to_sleep);
	return (0);
}

int	is_thinking(t_data *data, t_philo *philo)
{
	if (print_act(data, philo, "think"))
		return (1);
	return (0);
}
