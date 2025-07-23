/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:56:19 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/02/12 17:08:07 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*li;
	t_list	*idk;

	if (!lst || !f || !del)
		return (NULL);
	li = NULL;
	while (lst)
	{
		idk = ft_lstnew(f(lst->content));
		if (!idk)
		{
			ft_lstclear(&li, del);
			return (NULL);
		}
		ft_lstadd_back(&li, idk);
		lst = lst->next;
	}
	return (li);
}
