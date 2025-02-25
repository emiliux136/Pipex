/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:23:04 by emilgarc          #+#    #+#             */
/*   Updated: 2024/12/17 17:26:21 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nuobj;
	t_list	*nulist;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	nulist = NULL;
	while (lst)
	{
		content = (f(lst->content));
		nuobj = ft_lstnew(content);
		if (!nuobj)
		{
			del(content);
			ft_lstclear(&nulist, del);
			return (NULL);
		}
		ft_lstadd_back(&nulist, nuobj);
		lst = lst->next;
	}
	nuobj->next = NULL;
	return (nulist);
}
