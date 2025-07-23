/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:26:50 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/02/08 17:44:38 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numm(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*s;
	size_t		i;
	long int	num;

	i = numm(n);
	num = n;
	if (num == 0)
		return (ft_strdup("0"));
	s = ((char *)malloc(sizeof(char) * (i + 1)));
	if (!s)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		s[0] = '-';
	}
	s[i] = '\0';
	i--;
	while (num)
	{
		s[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	return (s);
}
