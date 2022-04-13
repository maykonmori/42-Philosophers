/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:46:44 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/04/08 22:15:12 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_fork_lock(t_philo *philo)
{
	if (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead == 0)
			printf ("%lli %i has taken a fork\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer);
		if (philo->data->philo_num == 1)
		{
			usleep((philo->data->die * 1000) + 1000);
			return ;
		}
		pthread_mutex_lock(&philo->prev->fork);
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead == 0)
			printf ("%lli %i has taken a fork\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer);
	}
}

void	philo_fork_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->prev->fork);
	pthread_mutex_unlock(&philo->fork);
}

void	philo_eat(t_philo *philo)
{
	if (philo->data->dead == 0)
	{
		philo->last_eat_time = get_time();
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead == 0)
			printf ("%lli %i is eating\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer);
		philo->eat_count++;
		usleep(philo->data->eat * 1000);
	}
}

void	philo_sleep(t_philo *philo)
{
	if (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead == 0)
			printf ("%lli %i is sleeping\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer);
		usleep(philo->data->sleep * 1000);
	}
}

void	philo_think(t_philo *philo)
{
	if (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead == 0)
			printf ("%lli %i is thinking\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer);
	}
}
