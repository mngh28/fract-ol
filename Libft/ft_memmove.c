/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:26:10 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/01/31 16:51:35 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*p1;
	char	*p2;
	size_t	i;

	i = 0;
	p1 = (char *)dst;
	p2 = (char *)src;
	if (!p1 && !p2)
		return (NULL);
	if (p1 > p2 && p1 < p2 + len)
	{
		while (len > 0)
		{
			p1[len - 1] = p2[len - 1];
			len--;
		}
	}
	while (i < len)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dst);
}
