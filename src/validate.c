/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:42:55 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/04/04 16:45:49 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	validate_argc(int argc)
{
	if (argc < 5)
	{
		printf("Too few arguments\n");
		exit(EXIT_FAILURE);
	}
	if (argc > 6)
	{
		printf("Too many arguments\n");
		exit(EXIT_FAILURE);
	}
}

static void	validate_argv_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
			{
				printf("Arguments Invalid!\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	validate_args(int argc, char **argv)
{
	validate_argc(argc);
	validate_argv_number(argv);
}