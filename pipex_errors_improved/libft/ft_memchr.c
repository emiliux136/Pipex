/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:10:54 by emilgarc          #+#    #+#             */
/*   Updated: 2024/12/16 09:40:00 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	ze;
	size_t			i;

	ze = (unsigned char)c;
	a = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (a[i] == ze)
			return ((void *)(&a[i]));
		i++;
	}
	return (NULL);
}
