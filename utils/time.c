/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:51:19 by mfroissa          #+#    #+#             */
/*   Updated: 2023/04/28 20:45:58 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	real_time(long long truc)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - truc);
}

// fonction ft_usleep avec plus de precision
void	ft_usleep(t_data *data, long int time_in_ms)
{
	long int	start_time;
	int			i;

	i = 0;
	start_time = real_time(data->time_start);
	while (real_time(data->time_start) < start_time + time_in_ms)
	{
		if (check(data))
			return ;
		usleep(time_in_ms / 20);
	}
}
