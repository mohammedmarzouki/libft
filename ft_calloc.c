/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:39:08 by mmarzouk          #+#    #+#             */
/*   Updated: 2019/10/28 21:39:10 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	int		i;

	i = 0;
	if (!(buffer = (void *)malloc(size * count)))
		return (0);
	if (buffer)
	{
		ft_bzero(buffer, size * count);
		return (buffer);
	}
	return (0);
}
