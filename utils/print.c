/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:23:52 by mfroissa          #+#    #+#             */
/*   Updated: 2023/05/10 19:37:40 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	print_act(t_data *data, t_philo *philo, char *str)
{
	pthread_mutex_lock(&data->writing);
	pthread_mutex_lock(&data->sram);
	if (data->un_mort)
		return (pthread_mutex_unlock(&data->sram),
			pthread_mutex_unlock(&data->writing), 1);
	pthread_mutex_unlock(&data->sram);
	if (is_same(str, "eat"))
		printf("%lld	%d   is eating\n",
			real_time(data->time_start), philo->id + 1);
	else if (is_same(str, "sleep"))
		printf("%lld	%d   is sleeping\n",
			real_time(data->time_start), philo->id + 1);
	else if (is_same(str, "think"))
		printf("%lld	%d   is thinking\n",
			real_time(data->time_start), philo->id + 1);
	else if (is_same(str, "fork"))
		printf("%lld	%d   has taken a fork\n",
			real_time(data->time_start), philo->id + 1);
	else if (is_same(str, "dead"))
		return (printf("%lld	%d   died\n", real_time(data->time_start),
			philo->id + 1));
	return (pthread_mutex_unlock(&data->writing), 0);
}

int	err_msg(char *str, int ret)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	return (ret);
}
