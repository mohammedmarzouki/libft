/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:38:01 by mmarzouk          #+#    #+#             */
/*   Updated: 2019/10/28 21:38:03 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	condition(long resultat, int signe)
{
	if (resultat > 2147483648 && signe == -1)
		return (0);
	if (resultat > 2147483647 && signe == 1)
		return (-1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		signe;
	int		i;
	long	resultat;

	resultat = 0;
	i = 0;
	signe = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + str[i] - '0';
		i++;
		if ((resultat > 2147483647 && signe == 1)
				|| (resultat > 2147483648 && signe == -1))
			return (condition(resultat, signe));
	}
	return (resultat * signe);
}
