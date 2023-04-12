/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:53 by mfroissa          #+#    #+#             */
/*   Updated: 2023/04/12 16:31:33 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	err_msg(char *str, int ret)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	return (ret);
}