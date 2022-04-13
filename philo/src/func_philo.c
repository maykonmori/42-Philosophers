/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:18:31 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/04/08 22:16:45 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*func_philo(t_philo *philo)
{
	philo->last_eat_time = get_time();
	if (philo->id % 2 == 0)
		usleep((philo->data->eat - 10) * 1000);
	while (philo->data->dead == 0 && (philo->data->eat_num == -1 \
		|| philo->eat_count < philo->data->eat_num))
	{
		philo_fork_lock(philo);
		philo_eat(philo);
		philo_fork_unlock(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

int	eat_count_check(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	if (philo->eat_count != data->eat_num)
		return (0);
	philo = philo->next;
	while (philo != data->philo)
	{
		if (philo->eat_count != data->eat_num)
			return (0);
		philo = philo->next;
	}
	return (1);
}

void	death_check(t_data *data)
{
	t_philo	*philo;

	usleep ((data->die * 1000) - 10);
	philo = data->philo;
	while (data->dead == 0)
	{
		if (eat_count_check(data))
			break ;
		if (get_time() - philo->last_eat_time > data->die)
		{
			pthread_mutex_lock(&data->printer);
			printf ("%lli %i died\n", get_time() - data->start_time, philo->id);
			data->dead = 1;
			pthread_mutex_unlock(&data->printer);
			pthread_mutex_destroy(&data->printer);
			break ;
		}
		philo = philo->next;
	}
}
