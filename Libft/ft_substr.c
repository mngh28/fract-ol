/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:50:06 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/02/12 19:37:24 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	i = ft_strlen(s) - start;
	if (len < i)
		i = len;
	p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s + start, i + 1);
	return (p);
}
