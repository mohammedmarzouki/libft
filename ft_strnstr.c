/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:36:55 by mmarzouk          #+#    #+#             */
/*   Updated: 2019/10/28 21:36:56 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compare(char *str1, char *str2, int *ptr, int len)
{
	while (*str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
		*ptr = *ptr + 1;
		if (*ptr > len)
			return (0);
	}
	return (1);
}

char		*ft_strnstr(const char *hays, const char *nedl, int len)
{
	int i;
	int *ptr;
	int c;

	if (*nedl == '\0')
		return ((char *)hays);
	i = 0;
	c = 0;
	ptr = &i;
	while (*hays)
	{
		if (*nedl == *hays)
		{
			if (ft_compare((char *)hays, (char *)nedl, ptr, len))
				return ((char *)hays);
		}
		*ptr = c;
		hays++;
		c++;
		*ptr = *ptr + 1;
		if (*ptr > len)
			break ;
	}
	return (0);
}
