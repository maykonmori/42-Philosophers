/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:14:33 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/04/05 20:53:37 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_philo t_philo;
typedef struct s_data t_data;

typedef struct s_philo
{
	int				id;
	long long		last_eat_time;
	int				eat_count;
	pthread_t		th;
	pthread_mutex_t	fork;
	t_philo			*next;
	t_philo			*prev;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int			philo_num;
	int			eat;
	int			sleep;
	int			die;
	int			eat_num;
	long long	start_time;
	int			dead;
	pthread_mutex_t	printer;
	t_philo		*philo;
}	t_data;

void		validate_args(int argc, char **argv);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		get_values(char **argv, t_data *data);
long long	get_time(void);
void		init_list_philo(t_data *data);
void		add_to_list(t_philo *philo, t_data *data, int n);
void		start_threads(t_data *data);
void		*func_philo(t_philo *philo);
void		death_check(t_data *data);
void		philo_fork_lock(t_philo *philo);
void		philo_fork_unlock(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

#endif