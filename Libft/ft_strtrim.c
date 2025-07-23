/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:04:33 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/02/07 17:30:47 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	char	*p;

	i = 0;
	k = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && i <= k)
		i++;
	if (i > k)
		return (ft_strdup(s1 + k + 1));
	while (ft_strchr(set, s1[k]) && k >= 0)
		k--;
	p = malloc(k - i + 2);
	if (!p)
		return (NULL);
	ft_strlcpy(p, &s1[i], k - i + 2);
	return (p);
}
