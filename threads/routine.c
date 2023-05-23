/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:32:39 by mfroissa          #+#    #+#             */
/*   Updated: 2023/04/28 20:35:00 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*one_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data_save;

	philo = (t_philo *)arg;
	data_save = philo->data_save;
	print_act(data_save, &data_save->philo[0], "fork");
	ft_usleep(data_save, data_save->time.time_to_die);
	return (NULL);
}

void	*dead_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	if (data->n_meals > 0)
	{
		while (count_meals(data, i) && !data->un_mort)
			if (is_muerte(data, &i))
				return (NULL);
	}
	else
	{
		while (!data->un_mort)
			if (is_muerte(data, &i))
				return (NULL);
	}
	return (NULL);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data_save;

	philo = (t_philo *)arg;
	data_save = philo->data_save;
	if (data_save->n_meals > 0)
	{
		while (!check(data_save) && philo->meals < data_save->n_meals)
			if (life_loop(data_save, philo))
				return (NULL);
	}
	else
	{
		while (!check(data_save))
			if (life_loop(data_save, philo))
				return (NULL);
	}
	return (NULL);
}

int	life_loop(t_data *data, t_philo *philo)
{
	if (check(data))
		return (1);
	if (is_forking(philo->data_save, philo))
		return (2);
	if (check(data))
		return (1);
	if (is_sleeping(philo->data_save, philo))
		return (3);
	if (check(data))
		return (1);
	if (is_thinking(philo->data_save, philo))
		return (4);
	if (check(data))
		return (1);
	return (0);
}
