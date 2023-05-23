/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:04:41 by mfroissa          #+#    #+#             */
/*   Updated: 2023/04/28 20:48:56 by mfroissa         ###   ########.fr       */
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

typedef struct s_philo
{
	int				meals;
	int				id;
	void			*data_save;
	long long		until;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}				t_philo;

typedef struct s_time
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}				t_time;

typedef struct s_data
{
	int				n_philo;
	int				n_meals;
	int				un_mort;
	long long		time_start;
	t_time			time;
	t_philo			philo[200];
	pthread_t		dead;
	pthread_mutex_t	xelor;
	pthread_mutex_t	sram;
	pthread_mutex_t	ougi;
	pthread_mutex_t	writing;
	pthread_mutex_t	fork[200];
}				t_data;

//	CORE
//	act.c
int			is_eating(t_data *data, t_philo *philo);
int			is_forking(t_data *data, t_philo *philo);
int			is_sleeping(t_data *data, t_philo *philo);
int			is_thinking(t_data *data, t_philo *philo);

//	create.c
void		create_time(t_data *data, int ac, char **av);
int			create_data(t_data *data, int ac, char **av);
void		init_philo(t_data *data);

//	mutex.c
void		cleanup_forks(t_data *data, int n);
int			init_forks(t_data *data);
void		attrib_forks(t_data *data);
int			init_mutex(t_data *data);

//	parsing.c
int			check_num(int ac, char **av);
int			check_pos(int ac, char **av);
int			parsing(int ac, char **av);

//	UTILS
//	print.c
int			print_act(t_data *data, t_philo *philo, char *str);
int			err_msg(char *str, int ret);

//	time.c
long long	get_time(void);
long long	real_time(long long truc);
void		ft_usleep(t_data *data, long int time_in_ms);

//	utils.c
int			ft_strlen(char *str);
long		ft_atoi(char *str);
int			is_same(char *s1, char *s2);
void		*ft_calloc(size_t n, size_t size);

//	THREADS	//
//	check.c
int			one(t_data *data);
int			count_meals(t_data *data, int i);
int			is_muerte(t_data *data, int *i);
int			check(t_data *data);

//	routine.c
void		*one_routine(void *arg);
void		*dead_routine(void *arg);
void		*start_routine(void *arg);
int			life_loop(t_data *data, t_philo *philo);

//	threads.c
int			create_threads(t_data *data);
int			join_threads(t_data *data);

#endif