/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:04:00 by mfroissa          #+#    #+#             */
/*   Updated: 2023/04/12 17:12:42 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(data));
	if (!data)
		return (1);
	if (parsing(ac, av))
		return (2);
	if (create_data(data, ac, av))
		return (3);
	return (0);
}