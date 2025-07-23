/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:45:13 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/02/12 17:08:41 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*li;

	li = (t_list *)malloc(sizeof(t_list) * 1);
	if (!li)
		return (NULL);
	li->content = content;
	li->next = NULL;
	return (li);
}
