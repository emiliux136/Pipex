/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:21:45 by emilgarc          #+#    #+#             */
/*   Updated: 2024/12/16 09:39:44 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*dest;
	long int	nb;

	nb = n;
	len = length(nb);
	dest = (char *)malloc((sizeof(char)) * (len + 1));
	if (!dest)
		return (NULL);
	if (nb < 0)
	{
		dest[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		dest[0] = '0';
	dest[len] = '\0';
	while (nb > 0)
	{
		if (nb < 0 && (len--) == 1)
			break ;
		dest[(len--) - 1] = (nb % 10) + '0';
		nb /= 10;
	}
	return (dest);
}
