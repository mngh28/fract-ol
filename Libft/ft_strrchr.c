/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:59:44 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/02/08 19:03:29 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	p = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (p[i] == (char)c)
		{
			return (&p[i]);
			break ;
		}
		i--;
	}
	return (NULL);
}
