/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:45:57 by mmarzouk          #+#    #+#             */
/*   Updated: 2019/10/28 21:45:59 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *to, const void *from, int c, size_t n)
{
	unsigned int	i;
	char			*pto;
	const char		*pfrom;

	i = 0;
	pto = (char *)to;
	pfrom = (char *)from;
	while (i < n)
	{
		pto[i] = pfrom[i];
		if (pfrom[i] == (char)c)
			return (to + i + 1);
		i++;
	}
	return (0);
}
