/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:43:38 by mmarzouk          #+#    #+#             */
/*   Updated: 2019/10/28 21:43:40 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_start(int i, int e, const char *s1, const char *set)
{
	while (s1[i] != '\0')
	{
		if (ft_strrchr((char *)set, s1[i]))
			e++;
		else
			break ;
		i++;
	}
	return (e);
}

static char	ft_end(int i, int f, const char *s1, const char *set)
{
	while (s1[i - 1] != '\0')
	{
		if (ft_strrchr((char *)set, s1[i - 1]))
			f++;
		else
			break ;
		i--;
	}
	return (f);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		e;
	int		f;
	char	*s;
	int		len;

	i = 0;
	e = 0;
	if (s1)
		e = ft_start(i, e, s1, set);
	else
		return (0);
	if (s1[e] == '\0')
		return (ft_strdup(""));
	i = ft_strlen(s1);
	len = i;
	f = 0;
	f = ft_end(i, f, s1, set);
	s = ft_substr(s1, e, len - e - f);
	return (s);
}
