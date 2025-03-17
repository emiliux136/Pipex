/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:26:52 by emilgarc          #+#    #+#             */
/*   Updated: 2024/12/11 18:27:38 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		div;
	int		mod;
	char	a;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0 && n != -2147483648)
	{
		write (fd, "-", 1);
		n = n * -1;
	}
	div = n / 10;
	mod = n % 10;
	if (div > 0)
	{
		ft_putnbr_fd(div, fd);
	}
	a = mod + '0';
	write(fd, &a, 1);
}
