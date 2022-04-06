/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:01:41 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/04/05 21:52:46 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	return((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	get_values(char **argv, t_data *data)
{
	data->philo_num = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->eat_num = ft_atoi(argv[5]);
	else
		data->eat_num = -1;
	data->start_time = get_time();;
	data->dead = 0;
}

void	init_list_philo(t_data *data)
{
	int n;

	n = 1;
	data->philo = (t_philo *) malloc (sizeof(t_philo));
	pthread_mutex_init(&data->philo->fork, NULL);
	data->philo->data = data;
	data->philo->id = 1;
	data->philo->eat_count = 0;
	data->philo->next = data->philo;
	data->philo->prev = data->philo;
	while(n < data->philo_num)
	{
		add_to_list(data->philo, data, n);
		n++;
	}
}

void	add_to_list(t_philo *philo, t_data *data, int n)
{
	t_philo	*new_philo;
	t_philo *first;

	first = philo;
	new_philo = (t_philo *) malloc (sizeof(t_philo));
	pthread_mutex_init(&new_philo->fork, NULL);
	new_philo->id = n + 1;
	new_philo->data = data;
	new_philo->eat_count = 0;
	while (philo->next != first)
		philo = philo->next;
	philo->next = new_philo;
	new_philo->next = first;
	new_philo->prev = philo;
	first->prev = new_philo;
}

void	start_threads(t_data *data)
{
	int n;
	t_philo *temp;

	n = data->philo_num;
	temp = data->philo;
	pthread_mutex_init(&data->printer, NULL);
	data->start_time = get_time();
	while (n > 0)
	{
		pthread_create(&temp->th, NULL, (void *)&func_philo, temp);
		temp = temp->next;
		n--;
	}
	death_check(data);
	n = data->philo_num;
	while(n > 0)
	{
		pthread_join(temp->th, NULL);
		temp = temp->next;
		n--;
	}
	pthread_mutex_destroy(&data->printer);
}