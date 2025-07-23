/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:09:43 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/02/01 16:07:10 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst1, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src || !dstsize)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst1[i] = src[i];
		i++;
	}
	dst1[i] = '\0';
	return (ft_strlen(src));
}
