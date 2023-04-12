/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:04:41 by mfroissa          #+#    #+#             */
/*   Updated: 2023/04/12 16:27:45 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_time
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}				t_time;

typedef struct	s_data
{
	t_time	time;
}				t_data;

//	parsing.c
int	check_num(int ac, char **av);
int	parsing(int ac, char **av);

//	temp.c
int	err_msg(char *str, int ret);

//	utils.c
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	*ft_calloc(size_t n, size_t size);



#endif