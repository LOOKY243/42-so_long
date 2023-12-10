/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:06:24 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/08 19:31:56 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_strlen(char const *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *extra, char const *buff)
{
	char				*str;
	unsigned int		i;

	if (!buff)
		return (NULL);
	if (!extra)
		str = malloc(sizeof(char) * ft_strlen(buff) + 1);
	else
		str = malloc(sizeof(char) * (ft_strlen(extra) + ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (extra)
		while (*extra)
			str[i++] = *extra++;
	while (*buff)
		str[i++] = *buff++;
	str[i] = 0;
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int				i;
	unsigned char	*str1;
	unsigned char	str2;

	str1 = (unsigned char *)s;
	str2 = (unsigned char)c;
	i = 0;
	while (str1[i])
	{
		if (str1[i] == str2)
			return ((char *)&s[i]);
		i++;
	}
	if (str2 == 0)
		return ((char *)&str1[i]);
	return (NULL);
}
