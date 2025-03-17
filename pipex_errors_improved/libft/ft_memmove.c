/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:55:50 by emilgarc          #+#    #+#             */
/*   Updated: 2024/12/13 16:24:39 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*s;
	char		*d;

	d = (char *)dest;
	s = (char *)src;
	if (dest > src)
	{
		while (n--)
			d[n] = s[n];
	}
	else if (dest < src)
		ft_memcpy(dest, src, n);
	return (d);
}

// #include <stdio.h>
// int main()
// {
// 	char a[] = "holamundo";
// 	const char b[] = "quetal";
// 	char	*d;
// 	size_t n = 3;
// 	d = ft_memmove(a, b, n);
// 	printf("%s", d);
// 	return(0);
// }