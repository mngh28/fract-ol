/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:13:27 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/02/08 19:26:35 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	k;

	i = 0;
	k = (unsigned char)c;
	p = (unsigned char *)s;
	if (!n)
		return (NULL);
	while (*p != k && --n)
		p++;
	if (*p == k)
		return (p);
	return (NULL);
}
