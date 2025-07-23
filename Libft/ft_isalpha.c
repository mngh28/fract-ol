/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:43:57 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/01/30 19:43:04 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/* #include <stdio.h>
#include <ctype.h>
int main()
{
	char c = '=';
	char k = 'q';
	printf("%d", isalpha(c));
	printf("%d", isalpha(k));
	printf("%d", ft_isalpha(c));
	printf("%d", ft_isalpha(k));
} */
