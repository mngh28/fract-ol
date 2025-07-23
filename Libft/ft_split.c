/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:31:04 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/02/12 17:11:22 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	*ft_free(char **strs, int count)
{
	if (!strs)
		return (NULL);
	while (count--)
	{
		free(strs[count]);
		strs[count] = NULL;
	}
	free(strs);
	return (NULL);
}

static int	word_count(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*word;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str + start, end - start + 1);
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	int		j;
	int		s_word;

	i = 0;
	j = 0;
	s_word = -1;
	res = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			res[j] = fill_word(s, s_word, i);
			if (!res[j++])
				return (ft_free(res, j));
			s_word = -1;
		}
		i++;
	}
	return (res);
}
