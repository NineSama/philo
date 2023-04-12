/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:13:21 by mfroissa          #+#    #+#             */
/*   Updated: 2023/04/12 16:44:43 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_pos(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 0	)
			return (3);
		i++;
	}
	return (0);
}

int	parsing(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (err_msg("Incorrect number of args\n", 1));
	if (check_num(ac, av))
		return (err_msg("Args can only be numbers\n", 2));
	if (check_pos(ac, av))
		return (err_msg("Arguments can only be positive ints\n", 3));
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > 200)
		return (err_msg("Number of philo should be between 1 and 200\n", 4));
	return (0);
}