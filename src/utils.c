/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:15:23 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/04/05 20:53:26 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int	resu;
	int	sign;
	int	cont;

	resu = 0;
	sign = 1;
	cont = 0;
	while ((str[cont] >= '\t' && str[cont] <= '\r') || str[cont] == ' ')
		cont++;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			sign = -1;
		cont++;
	}
	while (ft_isdigit(str[cont]))
	{
		resu = resu * 10 + str[cont] - '0';
		cont++;
	}
	return (sign * resu);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}