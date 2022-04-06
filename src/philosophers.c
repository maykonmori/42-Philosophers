/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:40:14 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/04/05 20:51:02 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data *data;

	validate_args(argc, argv);
	data = (t_data *) malloc (sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	get_values(argv, data);
	init_list_philo(data);
	start_threads(data);
	return (0);
}

