/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:48:44 by mmarzouk          #+#    #+#             */
/*   Updated: 2019/10/28 21:48:46 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_unsigneditoa(char *s, unsigned int n, int *p)
{
	if (n <= 9)
		s[*p] = n + 48;
	else
	{
		ft_unsigneditoa(s, n / 10, p);
		*p = *p + 1;
		ft_unsigneditoa(s, n % 10, p);
	}
	return (s);
}

static char	*condition1(int n, int len, int *p)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (len + 2));
	if (str == 0)
		return (0);
	str[*p] = '-';
	*p = *p + 1;
	ft_unsigneditoa(str, n * -1, p);
	str[*p + 1] = '\0';
	return (str);
}

static char	*condition2(int n, int len, int *p)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n <= 9)
		str[*p] = n + 48;
	else
		ft_unsigneditoa(str, n, p);
	str[*p + 1] = '\0';
	return (str);
}

static char	*condition3(int len)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (len + 2));
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		b;
	int		len;
	int		*p;
	int		i;

	len = 0;
	b = n;
	while (b != 0)
	{
		b = b / 10;
		len++;
	}
	i = 0;
	p = &i;
	if (n < 0)
		str = condition1(n, len, p);
	else if (n > 0)
		str = condition2(n, len, p);
	else
		return (condition3(len));
	return (str);
}
