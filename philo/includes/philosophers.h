/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:14:33 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/04/08 22:18:05 by mjose-ye         ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	long long		last_eat_time;
	int				eat_count;
	pthread_t		th;
	pthread_mutex_t	fork;
	struct s_philo	*next;
	struct s_philo	*prev;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philo_num;
	int				eat;
	int				sleep;
	int				die;
	int				eat_num;
	long long		start_time;
	int				dead;
	pthread_mutex_t	printer;
	t_philo			*philo;
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
void		free_list(t_data *data);
#endif