/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:11:22 by emilgarc          #+#    #+#             */
/*   Updated: 2024/12/16 09:45:26 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		x = 0;
		if (big[i] == little[x])
		{
			while (big[i + x] == little[x] && (i + x) < len)
			{
				x++;
				if (little[x] == '\0')
				{
					return ((char *)(big + i));
				}
			}
		}
		i++;
	}
	return (NULL);
}
