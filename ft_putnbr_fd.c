/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:41:17 by mmarzouk          #+#    #+#             */
/*   Updated: 2019/10/28 21:41:18 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(unsigned int n, int fd)
{
	if (n <= 9)
		ft_putchar_fd(n + 48, fd);
	else
	{
		putnbr(n / 10, fd);
		putnbr(n % 10, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		putnbr(n * -1, fd);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + 48, fd);
		else
			putnbr(n, fd);
	}
}
