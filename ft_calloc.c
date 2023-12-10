/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:42:35 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/02 16:27:31 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*str;
	unsigned int	i;

	if (nmemb > 65535 && size > 65535)
		return (NULL);
	if (nmemb * size > 2147483647)
		return (NULL);
	str = malloc(size * nmemb);
	i = 0;
	if (!str)
		return (NULL);
	while (i < nmemb * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}
