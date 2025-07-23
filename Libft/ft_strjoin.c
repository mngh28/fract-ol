/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:31:14 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/02/08 19:16:15 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	p = malloc(sizeof(char) * (i + j + 1));
	if (p == NULL)
		return (NULL);
	p[i + j] = '\0';
	while (k <= i)
	{
		p[k] = s1[k];
		k++;
	}
	k = 0;
	while (k <= j)
	{
		p[i] = s2[k];
		i++;
		k++;
	}
	return (p);
}
