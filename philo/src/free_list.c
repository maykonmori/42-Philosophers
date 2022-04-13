/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:56:11 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/04/08 22:12:25 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_list(t_data *data)
{
	t_philo	*temp;
	int		size;

	size = data->philo_num;
	while (size > 0)
	{
		temp = data->philo;
		data->philo = data->philo->next;
		free(temp);
		size--;
	}
	free(data);
}
