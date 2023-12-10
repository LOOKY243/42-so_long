/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:08:57 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/02 16:25:53 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

unsigned int	ft_countsplit(const char *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

char	*ft_prealloc(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (ft_calloc((count + 1), sizeof(char)));
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	size_t	i[3];

	if (!s)
		return (NULL);
	strs = ft_calloc(ft_countsplit(s, c) + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	i[2] = 0;
	i[0] = 0;
	while (s[i[0]])
	{
		while (s[i[0]] == c)
			i[0]++;
		if (s[i[0]] != c && s[i[0]])
		{
			i[1] = 0;
			strs[i[2]] = ft_prealloc(s, c, i[0]);
			while (s[i[0]] != c && s[i[0]])
				strs[i[2]][i[1]++] = s[i[0]++];
			i[2]++;
		}
	}
	return (strs);
}
