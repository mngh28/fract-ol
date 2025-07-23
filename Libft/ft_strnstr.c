/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:39:20 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/02/01 16:52:53 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;

	p = (char *)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (p);
	while (p[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] != '\0' && p[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return (&p[i]);
			++j;
		}
		if (needle[j] != p[i + j])
			j++;
		++i;
	}
	return (NULL);
}
