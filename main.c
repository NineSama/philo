/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:04:00 by mfroissa          #+#    #+#             */
/*   Updated: 2023/05/10 18:16:51 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;

	data = (t_data){0};
	if (parsing(ac, av))
		return (2);
	if (create_data(&data, ac, av))
		return (3);
	if (create_threads(&data))
		return (4);
	return (0);
}
