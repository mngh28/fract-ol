/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sredup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:06:05 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/02/01 17:03:35 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)malloc(ft_strlen(src) + 1);
	if (s1 == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		s1[i] = src[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
