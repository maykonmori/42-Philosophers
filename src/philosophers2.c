/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:19:55 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/04/04 14:05:42 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int mails = 0;
pthread_mutex_t mutex;

void	*routine(void *a)
{
	(void) a;
	int i = 0;
	while (i < 10000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	th[8];
	int	i;

	(void) argc;
	(void) argv;
	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < 8)
	{
		if (pthread_create(th + i, NULL, &routine, NULL) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (3);
		i++;
	}
	printf("Number of mails: %d\n", mails);
	pthread_mutex_destroy(&mutex);
	return (0);
}
