/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:24:47 by emilgarc          #+#    #+#             */
/*   Updated: 2024/12/16 14:51:24 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	dest = (char *)malloc((sizeof(char)) * len + 1);
	if (!dest)
		return (0);
	i = 0;
	while (*s != '\0' && i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
// #include "libft.h"
// #include <stdio.h>
// int main(void)
// {
//     char *str = "hola";
//     unsigned int start = 4294967295;
//     size_t len = 0;
//     char *substr = ft_substr(str, start, len);
//         printf("Subcadena: %s\n", substr);
//         free(substr);
//     return 0;
// }