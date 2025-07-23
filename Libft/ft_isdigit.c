/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:15:27 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/01/30 19:10:42 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/* #include <stdio.h>
#include <ctype.h>
int main()
{
	char e = '5';
	int k = 77;
	int m = 5;
	printf("%d", isdigit(e));
	printf("%d", isdigit(k));
	printf("%d", isdigit(m));
	printf("%d", ft_isdigit(e));
	printf("%d", ft_isdigit(k));
	printf("%d", ft_isdigit(m));
} */
